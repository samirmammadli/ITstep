#include <windows.h>
#include <tchar.h>
#include <string>
#include "resource.h"
using namespace std;

#define wArr(param) to_wstring(param).c_str()
#define wStr(param) to_wstring(param)

typedef BOOL(*INSTALL)();
typedef BOOL(*REMOVE)();

BOOL CALLBACK DlgProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPTSTR lpszCmdLine, int nCmdShow)
{
	return DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DlgProc);
}

INSTALL hookInstall;
REMOVE hookRemove;
HMODULE hModule;


BOOL CALLBACK DlgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static TCHAR buffer[300];
	switch (message)
	{
	case WM_INITDIALOG:
		hModule = LoadLibrary(L"Dll.dll");
		hookInstall = (INSTALL)GetProcAddress(hModule, "InstallHook");
		hookRemove = (REMOVE)GetProcAddress(hModule, "RemoveHook");
		break;
	case WM_COMMAND:
		if (LOWORD(wParam) == IDC_BUTTON_SET)
		{
			hookInstall();
			/*HWND hEdit = GetDlgItem(hWnd, IDC_EDIT1);
			GetWindowText(hEdit, buffer, 300);
			HWND hStatic = GetDlgItem(hWnd, IDC_STATIC1);
			SetWindowText(hStatic, buffer);*/
		}
		else if (LOWORD(wParam) == IDC_BUTTON_CLEAR)
		{
			hookRemove();
			
			/*HWND hEdit = GetDlgItem(hWnd, IDC_EDIT1);
			SetWindowText(hEdit, L"");
			HWND hStatic = GetDlgItem(hWnd, IDC_STATIC1);
			SetWindowText(hStatic, L"");*/
		}
		break;
	case WM_CLOSE:
		FreeLibrary(hModule);
		EndDialog(hWnd, 0); //закрываем модальный диалог
		return TRUE;
	}
	return FALSE;
}