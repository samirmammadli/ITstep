#include "Stack.h"
#include "Calculator.h"


void test1(const Calculator s1)
{
	0;
}

void main()
{
	Calculator* test = Calculator::Obj();
	cout << test->getMaxSize() << endl;
	test1(*test);
	int u;
	char * lesh = new char[200];
	cin.getline(lesh, 200);
	Stack<double> numbers(200);
	Stack<char> operators(200);
	int size = strlen(lesh) + 1;
	for (int i = 0; i < size; i++)
	{
		if (lesh[i] >= 48 && lesh[i] <= 57)
		{
			int temp = 0;
			while (lesh[i] >= 48 && lesh[i] <= 57)
			{
				temp *= 10;
				temp += lesh[i] - 48;
				i++;
			}
			i--;
			numbers.push(temp);
		}
		else 
		{
			if (operators.peek() == '*' || operators.peek() == '/')
			{
				double temp = numbers.peek();
				numbers.pop();
				operators.peek() == '*' ? temp *= numbers.peek() : temp = numbers.peek() / temp;
				numbers.pop();
				numbers.push(temp);
				operators.pop();
			}
			lesh[i] != '\0' ? operators.push(lesh[i]) : 0;
		}
	}

	double total = 0;
	while (numbers.getCount() > 1)
	{
		double temp = numbers.peek();
		operators.peek() == '-' ? temp *= -1 : 0;
		operators.pop();
		numbers.pop();
		operators.peek() == '-' ? temp = (numbers.peek() * -1) + temp : temp = numbers.peek() + temp;
		operators.pop();
		numbers.pop();
		numbers.push(temp);
		operators.push('+');
	}


	for (int i = 0; i < numbers.getCount(); i++)
	{
		cout << "Numbers : " << numbers.arr[i] << " ";
	}
	cout << endl;
	cout << "Symb : " << operators.arr << endl;
	//cout << "Answer: " << total << endl;
	cout << "Symb Size: " << operators.getCount() << endl;



	
}

