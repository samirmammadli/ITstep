#include <windows.h>

HHOOK hHook;
HINSTANCE hInstance;
HWND hWnd;

// ����� ����� � ���
BOOL APIENTRY DllMain(HANDLE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved) {
	hInstance = (HINSTANCE)hModule;
	return TRUE;
}

// � ������� �������� ��������� �� msg - �������. 
// �� ����� �������������� ��� ���� ��������� ������ ����� ������� ��������� �������� ��� ������ ��� �������
LRESULT CALLBACK GetMsgProc(int idCode, WPARAM wParam, LPARAM lParam) {
	MSG*pMsg = (MSG*)lParam;
	if (idCode == HC_ACTION) {
		// ����� ������� ���� ������� �������, � ���������� ������� ��� ����������� ���. �.�. �� ����� � ������ ��������, � �������� ����� � �������
		if (pMsg->message == WM_CHAR) {
			if (pMsg->wParam >= 'a'&&pMsg->wParam <= 'z')
				pMsg->wParam -= 32;
			else if (pMsg->wParam >= 'A'&&pMsg->wParam <= 'Z')
				pMsg->wParam += 32;
		}
		// ����� ������� ������ ���� - ���� ���� ������ ����, ����� �� ������ � ��������
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

// ���������� ���������, ������ ���������, ��� ��� ������ ������ ���� ��������� - ��������� �� �������� �� ������ �������
extern "C" __declspec(dllexport)
BOOL InstallHook() {
	// HWND h = FindWindow(TEXT("Notepad++"), 0);
	// DWORD dw = GetWindowThreadProcessId(h, 0);

	// ������������� ���, ��������� ���������-����������� � �������� ���������� ����
	hHook = SetWindowsHookEx(WH_GETMESSAGE, GetMsgProc, hInstance, 0);
	//  hWnd = h;
	return hHook != NULL;
}

extern "C" __declspec(dllexport)
BOOL RemoveHook() {
	// ������� ���
	return UnhookWindowsHookEx(hHook);
}

