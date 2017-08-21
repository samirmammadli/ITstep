#include <iostream>
#include <conio.h>
using namespace std;

class Samir
{
	double a;
	double b, sum;
	char oper;
public:
	Samir(int);
	void iter();
	void operations();
	void print();
};

Samir::Samir(int q)
{
	a = q;
	b = 2.5;
	sum = 0;
	oper = 0;
}

void Samir::iter()
{
	cout << "Введите первое число: ";
	cin >> a;
	cout << "Введите операцию: ";
	cin >> oper;
	cout << "Введите второе число: ";
	cin >> b;
}

void Samir::operations()
{
	oper == '+' ? sum = a + b : 0;
	oper == '-' ? sum = a - b : 0;
	oper == '*' ? sum = a * b : 0;
	oper == '/' ? sum = a / b : 0;
}

void Samir::print()
{
	if (b == 0 && oper == '/') cout << "На ноль делить нельзя !" << endl;
	else cout << "Ответ: " << sum << endl;
}

void main()
{
	setlocale(NULL, "Russian");
	Samir calc(18);
	char key = 0;
	while (key != 13)
	{
		system("cls");
		calc.iter();
		calc.operations();
		calc.print();
		cout << "Для продолжения нажмите любую клавишу, для выхода нажмите ВВОД.\n";
		key = _getch();
	}
	
}