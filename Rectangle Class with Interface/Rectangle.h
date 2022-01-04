/** @file Rectangle.h */

#include "RectangleInterface.h"

using namespace std;

class Rectangle : public RectangleInterface
{
private:
	double length;
	double width;
public:
	Rectangle();
	bool set(double newLength, double newWidth);
	double getLength() const;
	double getWidth() const;
	double getArea() const;

};
