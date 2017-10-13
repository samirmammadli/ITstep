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
	int width;
	Point position;
	Color bgcolor;
	Color fgcolor;
public:
	Figure(int width = 0) : width(width)
	{

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
	void setWidth(int width)
	{
		this->width = width;
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
public:
	Square() : Figure()
	{

	}
	void draw();
};
	

class Rectangle : Figure
{
	int height;
public:
	void draw();
};
	

class Circle : Figure
{
	int radius;
public:
	void draw();
};
	


void main()
{
	Circle f;
	printf("#%02x%02x%02x\n", 0, 0, 0);
}

/*------ - DRAW------
Type: Rectangle
	Width : 100
	Height : 200
	Position : 10 x 20
	Background Color : #ff00e5;
Foreground Color : #000000;  */