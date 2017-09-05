#include <iostream>
#include <string>
using namespace std;

class CRect {

	int left;
	int right;
	int top;
	int bottom;
public:
	CRect()
	{
		this->left = 0;
		this->right = 0;
		this->top = 0;
		this->bottom = 0;
	}
	CRect(int l, int r, int t, int b)
	{
		this->left = l;
		this->right = r;
		this->top = t;
		this->bottom = b;
	}
	int getWidth()
	{
		return this->right - this->left;
	}
	int getHeight()
	{
		return this->top - this->bottom;
	}
	void NormalizeRect()
	{
		if (this->left > this->right)
			swap(this->left, this->right);
		if (this->bottom > this->top)
			swap(this->bottom , this->top);
	}
	bool getIsRectNull()
	{
		if (this->left == 0, this->right == 0, this->top == 0, this->bottom == 0)
			return true;
		else
			return false;
	}
};

void main()
{

	/*int left_x, left_y, bot_x, bot_y;
	cout << "Write rectangle`s coordinates (min = -50, max = 50):\n";
	cout << "Input Left top X: ";
	cin >> left_x;
	cout << "Input Left top Y: ";
	cin >> left_y;
	cout << "Input Right bottom X: ";
	cin >> bot_x;
	cout << "Input Right bottom Y: ";
	cin >> bot_y;
*/
}