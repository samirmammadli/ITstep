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
	Samir operator+ (Samir t2)
	{
		t2.a += a;
		t2.b += b;
		return t2;
	}
	Samir operator- (Samir t2)
	{
		t2.a -= a;
		t2.b -= b;
		return t2;
	}
	void operator++ (int)
	{
		++a;
		b += 1.3;
	}
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
	else
	{
		//cout << "Ответ: " << sum << endl;
		cout << a << "    " << b << endl;
	}
}

void main()
{
	setlocale(NULL, "Russian");
	Samir calc(18);
	Samir calc2(7);
	char key = 0;
	//while (key != 13)
	//{
	//	system("cls");
	//	calc.iter();
	//	calc.operations();
	//	calc.print();
	//	cout << "Для продолжения нажмите любую клавишу, для выхода нажмите ВВОД.\n";
	//	key = _getch();
	//}
	calc.print();
	calc2.print();
	calc = calc + calc2 + calc2;
	calc.print();
	calc2.print();
	calc2++;
	calc2.print();
}