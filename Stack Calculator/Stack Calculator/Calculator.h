#pragma once
#include "Stack.h"

class Calculator
{
	Stack<int>* numbers;
	Stack<char>* operators;
	string* input;
	const int max_size;
	static Calculator* obj;
	Calculator(int size);
public:
	static Calculator* Obj();
	Calculator(const Calculator &calc);
	~Calculator();
	void inputExpression();
	int getMaxSize();
};

