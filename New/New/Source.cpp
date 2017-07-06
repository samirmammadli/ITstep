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
	//
	//int count = 0;
	//POINT cp;
	//POINT cp2;
	////ScreenToClient(,&cp);
	//while (true)
	//{
	//	GetCursorPos(&cp);
	//	cp2 = cp;
	//	GetCursorPos(&cp);
	//	
	//	if (cp2.x != cp.x || cp2.y != cp.y)
	//	{
	//		system("cls");
	//		cout <<"\t\t" << cp.x << " " << cp.y << "\t\t";
	//	}	
	//}
	///*Sleep(9000);
	//SetCursorPos(cp.x, cp.y);*/
	////SetCursorPos(15, 125);


	char **test1 = new char*[10];
	for (int i = 0; i < 10; i++)
	{
		test1[i] = new char[100];
		strcpy(test1[i], "giuerhgiuquhIOGIUYgyuig");
		cout << test1[i] << endl;
	}

	cout << endl;
	char **test2 = new char*[10];
	for (int i = 0; i < 10; i++)
	{
		test2[i] = test1[i];
		cout << test2[i] << endl;
	}

	strcpy(test2[0], "GOvno;ftiohue5tyiohuoetyjhpe5");
	cin.getline(test2[0], 100);

	cout << test2[0] << endl;
	test2[0][0] = 'U';
	cout << test2[0] << endl;

	
}