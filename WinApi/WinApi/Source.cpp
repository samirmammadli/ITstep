#include <windows.h>
#include <tchar.h>
#include <string>
using namespace std;

#define wStr(param) to_wstring(param)
#define wArr(param) to_wstring(param).c_str()



// �������� ������� ���������
LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);
// ��� ������ ����
TCHAR szClassWindow[] = TEXT("WinAPI App");

INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpszCmdLine, int nCmdShow)
{
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
	int x, y;
	wstring result;
	switch (uMessage)
	{
	case WM_KEYDOWN:
		result += wParam;
		if (wParam == VK_RETURN)
		{
			MessageBox(NULL, wArr(wParam), L"Key Code", MB_OK);
		}
		break;
	/*case WM_CHAR:
		result += wParam;
		MessageBox(NULL, result.c_str(), L"Key Code", MB_OK);
		break;*/
	case WM_MOUSEMOVE:
		x = LOWORD(lParam);
		y = HIWORD(lParam);
		result += L"x: " + wStr(x) + L" y: " + wStr(y);
		SetWindowText(hWnd, result.c_str());
		break;
	case WM_LBUTTONDOWN:
		MessageBox(NULL, L"�������!", L"���������!", MB_OK);
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