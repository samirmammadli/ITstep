#include "CRect.h"
using namespace std;



void main()
{

	CRect rect1(-12, 12, 12, -3);
	rect1.NormalizeRect();
	rect1.Print();
}