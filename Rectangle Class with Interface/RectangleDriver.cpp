// Programmer:     Juan Ruben Suarez
// Project number: 2
// Project Desc:   Rectangle creation class with class interface.
// Course:         COSC 2436 PF III Data Structures
// Date:           September 17, 2017 

#include "Rectangle.cpp"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	//string key;
	Rectangle newRectangle;

	cout << "Initial state of the Rectangle" << endl;
	cout << setw(10)<< left << "Length: " << newRectangle.getLength() << endl;
	cout << setw(10) << left << "Width: " << newRectangle.getWidth() << endl;
	cout << setw(10) << left << "Area: " << newRectangle.getArea() << endl;

	cout << "\nNew length input: -1" << endl;
	cout << "New width input:   2" << endl;
	cout << "Valid change: " << boolalpha << newRectangle.set(-1, 2) << endl;
	cout << "\nCurrent state of the Rectangle" << endl;
	cout << setw(10) << left << "Length: " << newRectangle.getLength() << endl;
	cout << setw(10) << left << "Width: " << newRectangle.getWidth() << endl;
	cout << setw(10) << left << "Area: " << newRectangle.getArea() << endl;

	cout << "\nNew length input:  3" << endl;
	cout << "New width input:   2" << endl;
	cout << "Valid change: " << boolalpha << newRectangle.set(3, 2) << endl;
	cout << "\nCurrent state of the Rectangle" << endl;
	cout << setw(10) << left << "Length: " << newRectangle.getLength() << endl;
	cout << setw(10) << left << "Width: " << newRectangle.getWidth() << endl;
	cout << setw(10) << left << "Area: " << newRectangle.getArea() << endl;
	cout << "" << endl;

	//getline(cin, key);
	//system("pause");
	return 0;
}
