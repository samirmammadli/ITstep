#pragma once
#include <iostream>
#include <string>
using namespace std;

class CRect {

	int left;
	int right;
	int top;
	int bottom;
public:
	CRect();
	CRect(int l, int r, int t, int b);
	int getWidth();
	int getHeight();
	bool getIsRectNull();
	bool PtInRect(int x, int y);
	bool CheckData(int a, int b, int c, int d);
	void setRectEmpty();
	void NormalizeRect();
	void Print();
};
