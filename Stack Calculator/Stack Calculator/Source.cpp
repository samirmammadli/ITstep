#include "Stack.h"
#include "Calculator.h"



void main()
{
	Calculator* test = Calculator::Obj();
	while (true)
	{
		system("cls");
		cout << "Input Expression:\nExample: 5.2*(-2.9+8)+4\n\n";
		char *temp = new char[200];
		cin.getline(temp, 200);
		cout << "Total: " << test->inputExpression(temp) << endl;
		system("pause");
	}
}
