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
	Stack<double> numb(200);
	Stack<char> symb(200);
	int size = strlen(lesh) +1;
	for (int i = 0;i < size; i++)
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
			numb.push(temp);
		}
		else //(i > 0 && (lesh[i] == '+' || lesh[i] == '-' || lesh[i] == '*' || lesh[i] == '/'))
		{
			if (symb.peek() == '*' || symb.peek() == '/')
			{
				double temp = numb.peek();
				numb.pop();
				symb.peek() == '*' ? temp *= numb.peek() : temp = numb.peek() / temp;
				numb.pop();
				numb.push(temp);
				symb.pop();
			}
			lesh[i] != '\0' ? symb.push(lesh[i]) : 0;
		}
	}

	double total = 0;
	size = symb.getCount();
	for (int i = 0; i < size; i++)
	{
		double temp = numb.peek();
		numb.pop();
		symb.peek() == '+' ? temp = temp + numb.peek() : (temp = numb.peek() - temp, temp *= -1);
		numb.pop();
		numb.push(temp);
		symb.pop();
	}


	for (int i = 0; i < numb.getCount(); i++)
	{
		cout << "Numbers : " << numb.arr[i] << " ";
	}
	cout << endl;
	cout << "Symb : " << symb.arr << endl;
	cout << "Answer: " << total << endl;
	cout << "Symb Size: " << symb.getCount() << endl;



	
}

