#include <windows.h>
#include <iostream>
#include <conio.h>
using namespace std;

//COORD crd = { 125, 54 };
//HANDLE out_handle = GetStdHandle(STD_OUTPUT_HANDLE);
//SMALL_RECT src = { 0, 0, crd.X - 1, crd.Y - 1 };
//SetConsoleWindowInfo(out_handle, true, &src);
//SetConsoleScreenBufferSize(out_handle, crd);




void main()
{
	
	int count = 0;
	POINT cp;
	POINT cp2;
	//ScreenToClient(,&cp);
	while (true)
	{
		GetCursorPos(&cp);
		cp2 = cp;
		GetCursorPos(&cp);
		
		if (cp2.x != cp.x || cp2.y != cp.y)
		{
			system("cls");
			cout <<"\t\t" << cp.x << " " << cp.y << "\t\t";
		}	
	}
	/*Sleep(9000);
	SetCursorPos(cp.x, cp.y);*/
	//SetCursorPos(15, 125);
}