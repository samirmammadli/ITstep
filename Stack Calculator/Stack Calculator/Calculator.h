#pragma once
#include "Stack.h"

class Calculator
{
	Stack<int>* numbers;
	Stack<char>* operators;
	string input;
	const int max_size;
public:
	Calculator(int size);
	Calculator(const Calculator &calc);
	~Calculator();

	void inputExpression();
};

