// Programmer:     Juan Ruben Suarez
// Project number: 3_1
// Project Desc:   Max number in an interger array
// Course:         COSC 2436 PF III Data Structures
// Date:           October, 2017 

#include <iostream>
#include <assert.h> 
using namespace std;


/*
	Serarches the array anArray[] from anArray[first] through anArray[last] and returns the element with the largest value in the array
	@pre	0 <= first, last <= SIZE -1, where SIZE is the maximum size of the array, and anArray[first] <= anArray[first + 1] <=...<= anArray[last]
	@post	anArray is unchanged
	@param	an Array - The given array to search on
	@param	first - The lowest index on the array to start searching from
	@param	last - The highest index to stop searching at
	@return	the element with the largest value
*/

int maxArray(const int anArray[], int first, int last)
{
	assert(first <= last);
	int max = -1;

	if (first < last)
	{
		if (anArray[first] < anArray[last])
			max = maxArray(anArray, first + 1, last);
		else
			max = maxArray(anArray, first, last - 1);
	}
	else if (first == last)
		max = anArray[first];

	return max;
}

int main()
{

	int myArray[] = { 2,3,5 };
	int first = 0;
	int last = 2;
	cout << "Array  { 2,3,5 }" << endl;
	cout << "Max interger: " << maxArray(myArray, first, last) << 
	" Should be 5."<< endl << endl;

	int myArray2[] = { 1 };
	first = 0;
	last = 0;
	cout << "Array  { 1 }" << endl;
	cout << "Max interger: " << maxArray(myArray2, first, last)<< " Should be 1."<< endl << endl;

	int myArray3[] = { 5, 98, 15, 53, 48, 57, 75, 81 };
	first = 0;
	last = 7;
	cout << "Array  { 5, 98, 15, 53, 48, 57, 75, 81 }" << endl;
	cout << "Max interger: " << maxArray(myArray3, first, last) << " Should be 98."<< endl << endl; 


	return 0;
}
