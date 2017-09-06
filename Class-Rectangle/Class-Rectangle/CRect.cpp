#include "CRect.h"

CRect::CRect()
{
	this->left = 0;
	this->right = 0;
	this->top = 0;
	this->bottom = 0;
}

CRect::CRect(int l, int r, int t, int b)
{
	bool IsCorrect = this->CheckData(l, r, t, b);

	if (IsCorrect)
	{
		this->left = l;
		this->right = r;
		this->top = t;
		this->bottom = b;
	}
	else
		this->setRectEmpty();
}

int CRect::getWidth()
{
	this->NormalizeRect();

	if (this->left < 0 && this->right >= 0)
		return this->left * -1 + this->right;
	else if (this->left < 0 && this->right < 0)
		return (this->left - this->right) * -1;
	else
		return this->right - this->left;
}

int CRect::getHeight()
{
	if (this->bottom < 0 && this->top >= 0)
		return this->bottom * -1 + this->top;
	else if (this->bottom < 0 && this->top < 0)
		return (this->bottom - this->top) * -1;
	else
		return this->top - this->bottom;
}

void CRect::setRectEmpty()
{
	this->left = 0;
	this->right = 0;
	this->top = 0;
	this->bottom = 0;
}

void CRect::NormalizeRect()
{
	if (this->left > this->right)
		swap(this->left, this->right);
	if (this->bottom > this->top)
		swap(this->bottom, this->top);
}

bool CRect::getIsRectNull()
{
	if (this->left == 0, this->right == 0, this->top == 0, this->bottom == 0)
		return true;
	else
		return false;
}

bool CRect::PtInRect(int x, int y)
{
	if (x > this->left && x < this->right && y > this->bottom && y < this->top)
		return true;
	else
		return false;
}

void CRect::Print()
{
	cout << "               y\n               ^\n";
	for (int i = 15; i > -16; i--)
	{
		for (int j = -15; j < 16; j++)
		{
			if (i == 0 && j == 15)
				cout << "-> x";
			else if (i == 0)
				cout << '-';
			else if (j == 0)
				cout << '|';
			else if ((j == this->left || j == this->right) && i <= this->top && i >= this->bottom)
				cout << '*';
			else if ((i == this->top || i == this->bottom) && j >= this->left && j <= this->right)
				cout << '*';
			else
				cout << ' ';
		}
		cout << endl;
	}
}

bool CRect::CheckData(int a, int b, int c, int d)
{
	if (a < -15 || a > 15)
		return false;
	if (b < -15 || b > 15)
		return false;
	if (c < -15 || c > 15)
		return false;
	if (d < -15 || d > 15)
		return false;

	return true;
}
