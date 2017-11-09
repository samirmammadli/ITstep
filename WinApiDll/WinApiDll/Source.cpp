#include <windows.h>

HHOOK hHook;
HINSTANCE hInstance;
HWND hWnd;

// точка входа в длл
BOOL APIENTRY DllMain(HANDLE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved) {
	hInstance = (HINSTANCE)hModule;
	return TRUE;
}

// в лпараме приходит указатель на msg - событие. 
// мы можем модифицировать пол¤ этой структуры подмен¤¤ таким образом отдельные свойства или вообще все событие
LRESULT CALLBACK GetMsgProc(int idCode, WPARAM wParam, LPARAM lParam) {
	MSG*pMsg = (MSG*)lParam;
	if (idCode == HC_ACTION) {
		// мен¤ем регистр кода нажатой клавиши, в приложение прийдет уже подмененный код. т.е. мы пишем в нижнем регистре, а получаем буквы в верхнем
		if (pMsg->message == WM_CHAR) {
			if (pMsg->wParam >= 'a'&&pMsg->wParam <= 'z')
				pMsg->wParam -= 32;
			else if (pMsg->wParam >= 'A'&&pMsg->wParam <= 'Z')
				pMsg->wParam += 32;
		}
		// мен¤ем местами кнопки мыши - если была нажата лева¤, мен¤ем на правую и наоборот
		else if (pMsg->message == WM_LBUTTONDOWN) {
			pMsg->message = WM_RBUTTONDOWN;
		}
		else if (pMsg->message == WM_LBUTTONUP) {
			pMsg->message = WM_RBUTTONUP;
		}
		else if (pMsg->message == WM_RBUTTONDOWN) {
			pMsg->message = WM_LBUTTONDOWN;
		}
		else if (pMsg->message == WM_RBUTTONUP) {
			pMsg->message = WM_LBUTTONUP;
		}
	}
	return CallNextHookEx(hHook, idCode, wParam, lParam);
}

// специальна¤ директива, котора¤ указывает, что эта функци¤ должна быть публичной - доступной дл¤ загрузки из других модулей
extern "C" __declspec(dllexport)
BOOL InstallHook() {
	// HWND h = FindWindow(TEXT("Notepad++"), 0);
	// DWORD dw = GetWindowThreadProcessId(h, 0);

	// устанавливаем хук, указываем процедуру-перехватчик и поулчаем дескриптор хука
	hHook = SetWindowsHookEx(WH_GETMESSAGE, GetMsgProc, hInstance, 0);
	//  hWnd = h;
	return hHook != NULL;
}

extern "C" __declspec(dllexport)
BOOL RemoveHook() {
	// снимаем хук
	return UnhookWindowsHookEx(hHook);
}

