#include <iostream>
#include <string>
using namespace std;

struct Point
{
	int x;
	int y;
};

class Color
{
	short red;
	short green;
	short blue;
public:
	
	Color() : red(0), green(0), blue(0) {}
	short getRed()
	{
		return red;
	}
	short getGreen()
	{
		return green;
	}
	short getBlue()
	{
		return blue;
	}
	void setColor(short r, short g, short b)
	{
		if (r <= 255 && g <= 255 && b <= 255)
		{
			red = r;
			green = g;
			blue = b;
		}
		else
			cout << "Incorrect color code!\n";
	}
	void lghten(short value)
	{
		if (value + red <= 255)
			red += value;
		if (value + green <= 255)
			green += value;
		if (value + blue <= 255)
			blue += value;
	}
	void darken(short value)
	{
		if (value - red >= 0)
			red -= value;
		if (value - green >= 0)
			green -= value;
		if (value - blue >= 0)
			blue -= value;
	}
};
	
class Figure
{
protected:
	Point position;
	Color bgcolor;
	Color fgcolor;
public:
	Figure()
	{
		position.x = 0;
		position.y = 0;
	}
	void setBgColor(short r, short g, short b)
	{
		bgcolor.setColor(r,g,b);
	}
	void setFgColor(short r, short g, short b)
	{
		fgcolor.setColor(r,g,b);
	}
	void lghtenBgColor(short value)
	{
		bgcolor.lghten(value);
	}
	void darkenBgColor(short value)
	{
		bgcolor.darken(value);
	}
	void lghtenFgColor(short value)
	{
		fgcolor.lghten(value);
	}
	void darkenFgColor(short value)
	{
		fgcolor.darken(value);
	}
	void setPosition(int x, int y)
	{
		position.x = x;
		position.y = y;
	}
	void draw()
	{
		cout << "Position x: " << position.x << endl;
		cout << "Position y: " << position.y << endl;
		printf("Foreground color: #%02x%02x%02x\n", fgcolor.getRed(), fgcolor.getGreen(), fgcolor.getBlue());
		printf("Background color: #%02x%02x%02x\n", bgcolor.getRed(), bgcolor.getGreen(), bgcolor.getBlue());
	}
};
	
class Square : public Figure
{
	int size;
public:
	Square() : Figure()
	{
		size = 0;
	}
	void setSize(int size)
	{
		this->size = size;
	}
	void draw()
	{
		cout << "Type - Square.\n";
		cout << "Size: " << size << endl;
		Figure::draw();
	}
};
	

class Rectangle : public Figure
{
	int height;
	int width;
public:
	Rectangle() :  Figure()
	{
		height = 0;
		width = 0;
	}
	void setSize(int H, int W)
	{
		height = H;
		width = W;
	}
	void draw()
	{
		cout << "Type - Rectangle.\n";
		cout << "Height: " << height << endl;
		cout << "Width: " << width << endl;
		Figure::draw();
	}
};
	

class Circle : public Figure
{
	int radius;
public:
	Circle() : Figure()
	{
		radius = 0;
	}
	void setRadius(int rad)
	{
		radius = rad;
	}
	void draw()
	{
		cout << "Type - Circle.\n";
		cout << "Radius: " << radius << endl;
		Figure::draw();
	}
};
	


void main()
{
	Circle c;
	c.draw();
	c.setBgColor(154,221,13);
	c.setFgColor(11, 100, 0);
	c.setRadius(110);
	c.setPosition(15, 25);
	cout << endl;
	c.draw();

	cout << "--------------------------------------------\n";

	Rectangle r;
	r.draw();
	r.setBgColor(154, 221, 13);
	r.setFgColor(11, 100, 0);
	r.setSize(150, 210);
	r.setPosition(15, 25);
	cout << endl;
	r.draw();

	cout << "--------------------------------------------\n";

	Square s;
	s.draw();
	s.setBgColor(54, 21, 13);
	s.setFgColor(111, 100, 0);
	s.setSize(150);
	s.setPosition(15, 25);
	cout << endl;
	s.draw();
	
}