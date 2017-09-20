#include "Calculator.h"



Calculator::Calculator(int size = 200) : max_size(size)
{
	this->numbers = new Stack<int>(max_size);
	this->operators = new Stack<char>(max_size);
}

Calculator::Calculator(const Calculator &calc) : max_size(calc.max_size)
{
	this->input = new char[max_size];
	this->numbers = new Stack<int>(max_size);
	this->operators = new Stack<char>(max_size);
	this->input = calc.input;
	memcpy(this->numbers, calc.numbers, sizeof(int)* max_size);
	memcpy(this->operators, calc.operators, max_size);
}

Calculator::~Calculator()
{
	delete[] this->numbers;
	delete[] this->operators;
}

void Calculator::inputExpression()
{
	cout << "Input Expression:\n";
	char *temp = new char[max_size];
	cin.getline(temp, max_size);
	this->input = temp;
	
}
