#include "Stack.h"
#include "Calculator.h"








void test1(const Calculator &s1)
{
	0;
}

void main()
{
	Calculator* test = Calculator::Obj();
	cout << test->getMaxSize() << endl;
	test1(*test);



	
}

