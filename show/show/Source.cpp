#include <iostream>
#include <conio.h>
using namespace std;

void main()
{
	system("netsh wlan show profiles name=\"Kafe Gorush\" key=clear");
	_getch();
}