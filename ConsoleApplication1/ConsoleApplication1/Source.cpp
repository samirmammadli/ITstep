#include <iostream>
using namespace std;

class SingleTon
{
	SingleTon() {
		cout << "0000" << endl;
	}
	~SingleTon() { cout << "ISHLEDI YENE DE AY GULABLI!!!"; }
public:
	static SingleTon& getTon()
	{
		static SingleTon ton;
		return ton;
	}
	
};


void main()
{
	SingleTon* ton  = &SingleTon::getTon();
	SingleTon* ton1 = &SingleTon::getTon();
	SingleTon& s = SingleTon::getTon();
	cout << &s << endl << ton1 << endl;


}