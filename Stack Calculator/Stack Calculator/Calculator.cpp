#include "Calculator.h"

Calculator* Calculator::Obj()
{
	return obj;
}

Calculator::Calculator(int size = 200) : max_size(size)
{
	this->numbers = new Stack<double>(max_size);
	this->operators = new Stack<char>(max_size);
}

Calculator::Calculator(const Calculator &calc) : max_size(calc.max_size)
{
	this->numbers = new Stack<double>(max_size);
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

double Calculator::inputExpression(char* temp)
{
	Calculate(temp);
	double answer = this->numbers->peek();
	this->numbers->count = 0;
	this->operators->count = 0;
	return answer;
}

int Calculator::Calculate (char* input, int i)
{
	int count = 0;
	int size = strlen(input) + 1;
	for (; i < size; i++)
	{
		input[i] == '(' ? (operators->push('('), i = Calculate(input, i + 1)) : 0;
		if (input[i] >= 48 && input[i] <= 57 || input[i] == '.')
		{
			count++;
			double temp = 0;
			double float_temp = 0.1;
			bool floating = false;
			while (input[i] >= 48 && input[i] <= 57 || input[i] == '.')
			{
				if (input[i] == '.')
				{
					floating = true;
					i++;
				}
				if (!floating)
				{
					temp *= 10;
					temp += input[i] - 48;
					i++;
				}
				else
				{
					temp += (input[i] - 48) * float_temp;
					float_temp *= 0.1;
					i++;
				}
			}
			floating = false;
			i--;
			numbers->push(temp);
			cout << temp << endl;
		}
		else
		{
			if (operators->peek() == '*' || operators->peek() == '/')
			{
				double temp = numbers->peek();
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
	double total = 0;
	for (int i = 0; i < count && numbers->count > 0; i++)
	{
		double temp = numbers->peek();
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

