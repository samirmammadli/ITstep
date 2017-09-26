#include "Calculator.h"

Calculator* Calculator::Obj()
{
	return obj;
}

Calculator::Calculator(int size = 200) : max_size(size)
{
	this->numbers = new Stack<int>(max_size);
	this->operators = new Stack<char>(max_size);
}

Calculator::Calculator(const Calculator &calc) : max_size(calc.max_size)
{
	this->numbers = new Stack<int>(max_size);
	this->operators = new Stack<char>(max_size);
	memcpy(this->operators->arr, calc.operators->arr, max_size);
	memcpy(this->numbers->arr, calc.numbers->arr, sizeof(int) * max_size);
	
}

Calculator::~Calculator()
{
	delete this->numbers;
	delete this->operators;
}


int Calculator::getMaxSize()
{
	return this->max_size;
}

int Calculator::inputExpression(char* temp)
{
	Calculate(temp);
	return this->numbers->peek();
}

int Calculator::Calculate (char* input, int i)
{
	int count = 0;
	int size = strlen(input) + 1;
	for (; i < size; i++)
	{
		input[i] == '(' ? (operators->push('('), i = Calculate(input, i + 1)) : 0;
		if (input[i] >= 48 && input[i] <= 57)
		{
			count++;
			int temp = 0;
			while (input[i] >= 48 && input[i] <= 57)
			{
				temp *= 10;
				temp += input[i] - 48;
				i++;
			}
			i--;
			numbers->push(temp);
		}
		else
		{
			if (operators->peek() == '*' || operators->peek() == '/')
			{
				int temp = numbers->peek();
				numbers->pop();
				operators->peek() == '*' ? temp *= numbers->peek() : temp = numbers->peek() / temp;
				numbers->pop();
				numbers->push(temp);
				operators->pop();
			}
			if (input[i] == ')') break;
			input[i] != '\0' ? operators->push(input[i]) : 0;
		}
	}
	int total = 0;
	for (int i = 0; i < count && numbers->count > 0; i++)
	{
		int temp = numbers->peek();
		if (operators->peek() == '-') temp *= -1;
		total += temp;
		numbers->pop();
		operators->pop();
	}
	if (operators->peek() == '(') operators->pop();
	numbers->push(total);
	return i+1;
}

Calculator* Calculator::obj = new Calculator;

