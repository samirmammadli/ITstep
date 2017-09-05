#include <iostream>
#include <string>
using namespace std;

class CRect {

	bool is_correct = false;
	int left_top_x;
	int left_top_y;
	int right_bottom_x;
	int right_bottom_y;
public:
	CRect()
	{
		this->left_top_x = 0;
		this->left_top_y = 0;
		this->right_bottom_x = 0;
		this->right_bottom_y = 0;
	}
	CRect(int left_top_x, int left_top_y, int right_bottom_x, int right_bottom_y)
	{

		this->left_top_x < 0 ? this->left_top_x *= -1 : 0;
		this->left_top_y < 0 ? this->left_top_y *= -1 : 0;
		this->right_bottom_x < 0 ? this->right_bottom_x *= -1 : 0;
		this->right_bottom_y < 0 ? this->right_bottom_y *= -1 : 0;

		if (left_top_x >= 0 && left_top_x <= 50 && left_top_y >= 0 && left_top_y <= 50 && right_bottom_x >= 0 && right_bottom_x <= 50 && right_bottom_y >= 0 && right_bottom_y <= 50)
		{
			if (left_top_x != right_bottom_x && left_top_y != right_bottom_y)
			{
				this->left_top_x = left_top_x;

				this->left_top_y = left_top_y;

				this->right_bottom_x = right_bottom_x;

				this->right_bottom_y = right_bottom_y;

				this->is_correct = true;
			}		
		}
	}
	bool IsRectNull()
	{
		if (this->left_top_x == 0 && this->left_top_y == 0 && this->right_bottom_x == 0 && this->right_bottom_y == 0)
			return true;
		else
			return false;
	}
	void SetRectEmpty()
	{
		this->left_top_x = 0;

		this->left_top_y = 0;

		this->right_bottom_x = 0;

		this->right_bottom_y = 0;
	}
	void NormalizeRect()
	{
		int temp;
		if (right_bottom_y > left_top_y)
		{
			temp = right_bottom_y;
			right_bottom_y = left_top_y;
			left_top_y = temp;
		}
		if (right_bottom_x < left_top_x)
		{
			temp = right_bottom_x;
			right_bottom_x = left_top_x;
			left_top_x = temp;
		}
	}
	int getWidth()
	{
		return this->right_bottom_x - this->left_top_x;
	}
	int getHeight()
	{
		return this->left_top_y - this->right_bottom_y;
	}
};

void main()
{
	CRect rect1(21, 18, 17, 24);
	rect1.NormalizeRect();
	cout << rect1.getWidth() << endl;
	cout << rect1.getHeight() << endl;
	rect1.SetRectEmpty();
	cout << rect1.getWidth() << endl;
	cout << rect1.getHeight() << endl;
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