#include "Stack.h"
#include "Calculator.h"


void test1(const Calculator s1)
{
	0;
}


int Calculate(Stack<char> &operators, Stack<double> &numbers, char* lesh, int i = 0)
{
	bool a = 0;
	int size = strlen(lesh) + 1;
	for (; i < size ; i++)
	{
		operators.peek() == '(' ? (operators.push('v'), i = Calculate(operators, numbers, lesh, i), printf("zalez\n")) : 0;
		
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
			if (operators.peek() == ')')
			{
				operators.pop();
				break;
			}
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
	while (numbers.getCount() > 1 && operators.peek() != '(')
	{
		double temp = numbers.peek();
		operators.peek() == '-' ? temp *= -1 : 0;
		operators.pop();
		numbers.pop();
		operators.peek() == '-' ? temp = (numbers.peek() * -1) + temp : temp = numbers.peek() + temp;
		numbers.pop();
		numbers.push(temp);


		operators.pop();
		operators.push('+');
	}

	return i;
}


void main()
{
	Stack<double> numbers(200);
	Stack<char> operators(200);
	Calculator* test = Calculator::Obj();
	cout << test->getMaxSize() << endl;
	test1(*test);
	char * lesh = new char[200];
	cin.getline(lesh, 200);
	
	
	 Calculate(operators, numbers, lesh);

	 cout << numbers.getCount() << endl;

	for (int i = 0; i < numbers.getCount(); i++)
	{
		cout << "Numbers : " << numbers.arr[i] << " ";
	}
	cout << endl;
	cout << "Symb : " << operators.arr << endl;
	cout << "Symb Size: " << operators.getCount() << endl;


	
}

