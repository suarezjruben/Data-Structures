// Programmer:     Juan Ruben Suarez
// Project number: 4
// Project Desc:   Linked bag using nodes
// Course:         COSC 2436 PF III Data Structures
// Date:           October, 2017

#include <iostream>
#include <string>
#include "LinkedBag.h"
using namespace std;

void display(LinkedBag<string>& bag)
{
	cout << "Total item count: " << bag.getCurrentSize()
		<< " items:" << endl;
	vector<string> bagItems = bag.toVector();

	int numberOfEntries = static_cast<int>(bagItems.size());
	for (int i = 0; i < numberOfEntries; i++)
	{
		cout << bagItems[i] << " ";
	}  // end for
	cout << endl << endl;
}  // end displaySet

int main()
{
	LinkedBag<string> bag;
	cout << "Testing array-based Set:" << endl;
	cout << "The initial bag is empty." << endl;
	cout << "isEmpty(): returns: " << bag.isEmpty()
		<< "; should be 1 (for true)" << endl;
	display(bag);

	string items[] = { "one", "two", "three", "four", "one" };
	cout << "Add 5 items to the bag {one, two, three, four, one}: " << endl;
	for (int i = 0; i < 5; i++)
	{
		bag.add(items[i]);
	}  // end for

	display(bag);

	cout << "isEmpty(): returns: " << bag.isEmpty()
		<< "; should be 0 (for false)" << endl;

	cout << "getCurrentSize(): returns: " << bag.getCurrentSize()
		<< "; should be 5 total." << endl;

	cout << "contains(\"three\"): returns: " << bag.contains("three")
		<< "; should be 1 (for true)" << endl;
	cout << "remove(\"three\"): returns: " << bag.remove("three")
		<< "; should be 1 (for true)" << endl;
	cout << "remove(\"three\"): returns: " << bag.remove("three")
		<< "; should be 0 (for false)" << endl;
	cout << endl;

	display(bag);

	// removing a randmon item from the bag
	cout << "We will now be removing a random item from the bag." << endl;
	bag.remove();
	display(bag);


	cout << "After clearing the bag with clear(), " << endl;
	bag.clear();

	cout << "isEmpty(): returns: " << bag.isEmpty()
		<< "; should be 1 (for true)" << endl;

	//system("pause");

	return 0;
}  // end main
