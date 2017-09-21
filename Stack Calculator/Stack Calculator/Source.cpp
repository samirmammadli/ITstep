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
	Stack<int> numb(200);
	Stack<char> symb(200);
	for (int i = 0; lesh[i] != '\0'; i++)
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
		if (lesh[i] == '+' || lesh[i] == '-' || lesh[i] == '*' || lesh[i] == '/')
		{
			if (symb.peek() == '*')
			{
				int temp = numb.peek();
				numb.pop();
				temp *= numb.peek();
				numb.pop();
				numb.push(temp);
				symb.pop();
			}
			symb.push(lesh[i]);
		}
			
	}
	
	for (int i = 0; i < numb.getSize(); i++)
	{
		0;
	}


	for (int i = 0; i < numb.getCount(); i++)
	{
		cout << "Numbers : " << numb.arr[i] << " ";
	}
	cout << endl;
	cout << "Symb : " << symb.arr << endl;



	
}

