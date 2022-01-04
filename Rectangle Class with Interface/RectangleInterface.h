#ifndef RECTANGLE_INTERFACE_
#define RECTANGLE_INTERFACE_

/** @file RectangleInterface.h */

class RectangleInterface
{
public:
	/** Updates the length and width of this Rectangle
	 @param	newLength the new length for this Rectangle
	 @param	newWidth the new width for this Rectangle
	 @pre	newLength and newWidth must be larger than zero
	 @post	If newLength and newWidth are valid, then the length and 
			with of this Rectangle will be updated to provided values,
			otherwise, there is not change.
	 @return True if this object is update and false otherwise. */
	virtual bool set(double newLength, double newWidth) = 0;

	/** Gets the length of this Rectangle
	 @return The length of this Rectangle. */
	virtual double getLength() const = 0;

	/** Gets the width of this Rectangle
	 @return The width of this Rectangle. */
	virtual double getWidth() const = 0;

	/** Gets the area of this Rectangle
	 @return The area of this Rectangle. */
	virtual double getArea() const = 0;

	/** Destroys this Rectangle and frees its assigned memory. */
	virtual ~RectangleInterface() {}
};
#endif