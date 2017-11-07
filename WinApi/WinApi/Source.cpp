#include <windows.h>
#include <tchar.h>
#include <string>
using namespace std;

#define wStr(param) to_wstring(param)
#define wArr(param) to_wstring(param).c_str()



// прототип оконной процедуры
LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);
// »м€ класса окна
TCHAR szClassWindow[] = TEXT("WinAPI App");

INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpszCmdLine, int nCmdShow)
{
	HWND hWnd;
	MSG lpMsg;
	WNDCLASSEX wcl;

	/* 1. ќпределение класса окна */
	// размер структуры WNDCLASSEX
	wcl.cbSize = sizeof(wcl);
	// ѕерерисовать всЄ окно, если изменЄн размер по горизонтали или по вертикали
	wcl.style = CS_HREDRAW | CS_VREDRAW;
	// адрес оконной процедуры
	wcl.lpfnWndProc = WindowProc;
	// используетс€ Windows
	wcl.cbWndExtra = 0;
	// используетс€ Windows
	wcl.cbClsExtra = 0;
	// дескриптор данного приложени€
	wcl.hInstance = hInst;
	// загрузка стандартной иконки
	wcl.hIcon = LoadIcon(NULL, IDI_ASTERISK);
	// загрузка стандартного курсора
	wcl.hCursor = LoadCursor(NULL, IDC_ARROW);
	// заполнение окна белым цветом
	wcl.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	//приложение не содержит меню
	wcl.lpszMenuName = NULL;
	//им€ класса окна
	wcl.lpszClassName = szClassWindow;
	// отсутствие маленькой иконки
	wcl.hIconSm = LoadIcon(NULL, IDI_ERROR);

	/* 2. –егистраци€ класса окна */
	if (!RegisterClassEx(&wcl))
		return 0; // при неудачной регистрации - выход

				  /* 3. —оздание окна */
				  // создаетс€ окно и переменной hWnd присваиваетс€ дескриптор окна
	hWnd = CreateWindowEx(
		0, // расширенный стиль окна
		szClassWindow, // им€ класса окна
		TEXT("ѕривет!"), // заголовок окна
		WS_OVERLAPPEDWINDOW, // стиль окна
		CW_USEDEFAULT, // х-координата левого верхнего угла окна
		CW_USEDEFAULT, // y-координата левого верхнего угла окна
		CW_USEDEFAULT, // ширина окна
		CW_USEDEFAULT, // высота окна
		NULL, // дескриптор родительского окна
		NULL, // дескриптор меню окна
		hInst, // идентификатор приложени€, создавшего окно
		NULL); // указатель на область данных приложени€

			   /* 4. ќтображение окна */
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);// перерисовка окна

					   /* 5. «апуск цикла обработки сообщений */
					   // получение очередного сообщени€ из очереди сообщений
	while (GetMessage(&lpMsg, NULL, 0, 0))
	{
		TranslateMessage(&lpMsg);// трансл€ци€ сообщени€
		DispatchMessage(&lpMsg); // диспетчеризаци€ сообщений
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
		MessageBox(NULL, L"«дорова!", L"«аголовок!", MB_OK);
		break;
	case WM_DESTROY: // сообщение о завершении программы
		PostQuitMessage(0); // посылка сообщени€ WM_QUIT
		break;
	default:
		// все сообщени€, которые не обрабатываютс€ в данной оконной
		// функции направл€ютс€ обратно Windows на обработку по умолчанию
		return DefWindowProc(hWnd, uMessage, wParam, lParam);
	}
	return 0;
}