#include "Rectangle.h"
using namespace std;

Rectangle::Rectangle() 
{
	length = 1;
	width = 1;
}
bool Rectangle::set(double newLength, double newWidth) 
{
	bool change;
	if (newLength > 0.0 && newWidth > 0.0)
	{
		length = newLength;
		width = newWidth;
		change = true;
	}
	// else the Rectangle is left unchanged
	else
	{
		change = false;
	}
	return change;
}
double Rectangle::getLength() const 
{
	return length;
}
double Rectangle::getWidth() const 
{
	return width;
}
double Rectangle::getArea() const 
{
	return length * width;
}

