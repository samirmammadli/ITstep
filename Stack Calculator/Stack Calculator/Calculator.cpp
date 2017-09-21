#include "Calculator.h"

Calculator* Calculator::Obj()
{
	return obj;
}

Calculator::Calculator(int size = 200) : max_size(size)
{
	this->numbers = new Stack<int>(max_size);
	this->operators = new Stack<char>(max_size);
	this->input = new string;
}

Calculator::Calculator(const Calculator &calc) : max_size(calc.max_size)
{
	this->input = new string;
	this->numbers = new Stack<int>(max_size);
	this->operators = new Stack<char>(max_size);
	*this->input = *calc.input;
	memcpy(this->operators->arr, calc.operators->arr, max_size);
	memcpy(this->numbers->arr, calc.numbers->arr, sizeof(int) * max_size);
	
}

Calculator::~Calculator()
{
	delete this->numbers;
	delete this->operators;
	delete this->input;
}

void Calculator::inputExpression()
{
	cout << "Input Expression:\n";
	char *temp = new char[max_size];
	cin.getline(temp, max_size);
	*this->input = temp;
}

int Calculator::getMaxSize()
{
	return this->max_size;
}

Calculator* Calculator::obj = new Calculator;

