#pragma once
#include "Stack.h"

class Calculator
{
	Stack<double>* numbers;
	Stack<char>* operators;
	const int max_size;
	static Calculator* obj;
	Calculator(int size);
	int Calculate(char* input, int i = 0);
public:
	static Calculator* Obj();
	Calculator(const Calculator &calc);
	~Calculator();
	double inputExpression(char* temp);
	int getMaxSize();
};

