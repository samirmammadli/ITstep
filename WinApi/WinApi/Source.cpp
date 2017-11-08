#include <windows.h>
#include <tchar.h>
#include <string>
#include <vector>
using namespace std;

#define wStr(param) to_wstring(param)
#define wArr(param) to_wstring(param).c_str()

vector<HWND> windows;
HWND Prog = NULL;
TCHAR buffer[201] = L"Notepad";
LPRECT siZe;
bool timeR = false;
int x = 0, y = 0;

// �������� ������� ���������
LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);
// ��� ������ ����
TCHAR szClassWindow[] = TEXT("WinAPI App");



INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpszCmdLine, int nCmdShow)
{
	siZe = new RECT;
	HWND hWnd;
	MSG lpMsg;
	WNDCLASSEX wcl;

	/* 1. ����������� ������ ���� */
	// ������ ��������� WNDCLASSEX
	wcl.cbSize = sizeof(wcl);
	// ������������ �� ����, ���� ������ ������ �� ����������� ��� �� ���������
	wcl.style = CS_HREDRAW | CS_VREDRAW;
	// ����� ������� ���������
	wcl.lpfnWndProc = WindowProc;
	// ������������ Windows
	wcl.cbWndExtra = 0;
	// ������������ Windows
	wcl.cbClsExtra = 0;
	// ���������� ������� ����������
	wcl.hInstance = hInst;
	// �������� ����������� ������
	wcl.hIcon = LoadIcon(NULL, IDI_ASTERISK);
	// �������� ������������ �������
	wcl.hCursor = LoadCursor(NULL, IDC_ARROW);
	// ���������� ���� ����� ������
	wcl.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	//���������� �� �������� ����
	wcl.lpszMenuName = NULL;
	//��� ������ ����
	wcl.lpszClassName = szClassWindow;
	// ���������� ��������� ������
	wcl.hIconSm = LoadIcon(NULL, IDI_ERROR);

	/* 2. ����������� ������ ���� */
	if (!RegisterClassEx(&wcl))
		return 0; // ��� ��������� ����������� - �����

				  /* 3. �������� ���� */
				  // ��������� ���� � ���������� hWnd ������������� ���������� ����
	hWnd = CreateWindowEx(
		0, // ����������� ����� ����
		szClassWindow, // ��� ������ ����
		TEXT("������!"), // ��������� ����
		WS_OVERLAPPEDWINDOW, // ����� ����
		CW_USEDEFAULT, // �-���������� ������ �������� ���� ����
		CW_USEDEFAULT, // y-���������� ������ �������� ���� ����
		CW_USEDEFAULT, // ������ ����
		CW_USEDEFAULT, // ������ ����
		NULL, // ���������� ������������� ����
		NULL, // ���������� ���� ����
		hInst, // ������������� ����������, ���������� ����
		NULL); // ��������� �� ������� ������ ����������

			   /* 4. ����������� ���� */
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);// ����������� ����

					   /* 5. ������ ����� ��������� ��������� */
					   // ��������� ���������� ��������� �� ������� ���������
	while (GetMessage(&lpMsg, NULL, 0, 0))
	{
		TranslateMessage(&lpMsg);// ���������� ���������
		DispatchMessage(&lpMsg); // ��������������� ���������
	}
	return lpMsg.wParam;
}

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam)
{
	wstring result;
	switch (uMessage)
	{
	case WM_CREATE:
	{
		
		{
			HWND moveWindow = CreateWindow(L"BUTTON", L"Move Window", WS_VISIBLE | WS_CHILD, 10, 10, 130, 20, hWnd, NULL, NULL, NULL);
			HWND closeWindow = CreateWindow(L"BUTTON", L"Close Window", WS_VISIBLE | WS_CHILD, 10, 50, 130, 20, hWnd, NULL, NULL, NULL);
			HWND changeText = CreateWindow(L"BUTTON", L"Change Text", WS_VISIBLE | WS_CHILD, 10, 90, 130, 20, hWnd, NULL, NULL, NULL);
			HWND Text = CreateWindow(L"EDIT", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 10, 140, 150, 20, hWnd, NULL, NULL, NULL);
			HWND findWindow = CreateWindow(L"BUTTON", L"Find Window", WS_VISIBLE | WS_CHILD, 175, 140, 130, 20, hWnd, NULL, NULL, NULL);
			windows.push_back(moveWindow);
			windows.push_back(closeWindow);
			windows.push_back(changeText);
			windows.push_back(Text);
			windows.push_back(findWindow);
		}
		break;
	}

	case WM_COMMAND:
	{
		
		if ((HWND)lParam == windows[0])
		{
			if (!timeR) {SetTimer(hWnd, 123, 10, NULL); timeR = true;}
			else { KillTimer(hWnd, 123); timeR = false; }
		}
		else if ((HWND)lParam == windows[1])
		{
			SendMessage(Prog, WM_CLOSE, NULL, NULL);
		}
		else if ((HWND)lParam == windows[2])
		{
			0;
		}
		else if ((HWND)lParam == windows[3])
		{
			0;
		}
		else if ((HWND)lParam == windows[4])
		{
			GetWindowText(windows[3], buffer, 200);
			Prog = FindWindow(buffer, NULL);
		}
		break;

		/*TCHAR buffer[201];
		HWND hNotepad = FindWindow(L"Notepad", NULL);
		HWND hEdit = FindWindowEx(hNotepad, NULL, L"Edit", NULL);
		SendMessage(hEdit, WM_GETTEXT, 200, LPARAM(buffer));
		MessageBox(NULL, buffer, L"Text", MB_OK);
		break;*/
	}
	case WM_TIMER:
		if (Prog != NULL) GetWindowRect(Prog, siZe);
		if (Prog != NULL) MoveWindow(Prog, ++x, y, siZe->right - siZe->left, siZe->bottom - siZe->top, TRUE);
		break;
	case WM_DESTROY: // ��������� � ���������� ���������
		PostQuitMessage(0); // ������� ��������� WM_QUIT
		break;
	default:
		// ��� ���������, ������� �� �������������� � ������ �������
		// ������� ������������ ������� Windows �� ��������� �� ���������
		return DefWindowProc(hWnd, uMessage, wParam, lParam);
	}
	return 0;
}