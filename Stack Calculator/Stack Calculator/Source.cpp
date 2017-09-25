#include "Stack.h"
#include "Calculator.h"



void main()
{
	Calculator* test = Calculator::Obj();
	cout << "Input Expression:\n";
	char *temp = new char[200];
	cin.getline(temp, 200);
	cout << "Total: " << test->inputExpression(temp) << endl;
	system("pause");
}

