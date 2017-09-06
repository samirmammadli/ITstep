#include "CRect.h"


void main()
{
	CRect rect1(-12, 12, 12, -3);
	rect1.NormalizeRect();
	rect1.Print();
	rect1.OffsetRect(0, -5);
	rect1.Print();
}