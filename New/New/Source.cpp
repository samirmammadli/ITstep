#include <iostream>
using namespace std;

class A {
public:
	int x;
	virtual void Show() {
		cout << "A";
	}
};
class B :public A {
public:
	int y;
	void Show() {
		cout << "B";
	}
};
void main()
{
	A *ptr = new B();

	ptr->Show();
	B::pt

	delete ptr;
}





//#include <iostream>
//#include <memory>
//using namespace std;
//
//class Fraction
//{
//private:
//	int m_numerator = 0;
//	int m_denominator = 1;
//
//public:
//	Fraction(int numerator = 0, int denominator = 1) :
//		m_numerator(numerator), m_denominator(denominator)
//	{
//	}
//
//	friend std::ostream& operator<<(std::ostream& out, const Fraction &f1)
//	{
//		out << f1.m_numerator << "/" << f1.m_denominator;
//		return out;
//	}
//};
//
//void printFraction(const unique_ptr<Fraction> const &ptr)
//{
//	if (ptr)
//		std::cout << *ptr << endl;
//}
//
//int main()
//{
//
//
//	unique_ptr<Fraction> ptr(new Fraction(3, 5));
//
//	//Fraction *ptr = new Fraction(3, 5);
//
//	printFraction(ptr);
//
//	return 0;
//}