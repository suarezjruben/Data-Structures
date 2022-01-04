// Programmer:     Juan Ruben Suarez
// Project number: 6
// Project Desc:   Array based List ADT with getPosition and remove methods
// Course:         COSC 2436 PF III Data Structures
// Date:           NOvember, 2017

#include <iostream>
#include <string>
#include "ArrayList.h" // ADT list operations
using namespace std;

void displayList(ListInterface<std::string>* listPtr)
{
	if (listPtr->isEmpty())
		cout << "The list is empty" << endl;
	else
	{
		cout << "The list contains " << endl;
		for (int pos = 1; pos <= listPtr->getLength(); pos++)
		{
			cout << listPtr->getEntry(pos) << " ";
   		}
		cout << endl;
	}
}


int main()
{
	ListInterface<std::string>* listPtr = new ArrayList<std::string>();
	
	cout << "List should be empty" << endl;;
	displayList(listPtr);
	cout << "Length : " << listPtr->getLength() << "; should be 0" << endl << endl;
	
	listPtr->insert(1, "two");
	displayList(listPtr);
	cout << "Length : " << listPtr->getLength() << "; should be 1" << endl << endl;	
	
	listPtr->insert(1, "one");
	displayList(listPtr);
	cout << "Length : " << listPtr->getLength() << "; should be 2" << endl << endl;		
	
	listPtr->insert(3, "three");
	displayList(listPtr);
	cout << "Length : " << listPtr->getLength() << "; should be 3" << endl << endl;	
	
	listPtr->insert(3, "two.five");
	displayList(listPtr);
	cout << "Length : " << listPtr->getLength() << "; should be 4" << endl << endl;	
	
	listPtr->insert(5, "five");
	displayList(listPtr);
	cout << "Length : " << listPtr->getLength() << "; should be 5" << endl << endl;
	
	cout << "List should be full; next insert should fail" << endl;
	if (listPtr->insert(6, "six"))
         cout << "Inserted \"six\" at position 6" << endl;
    else
         cout << "Cannot insert \"six\" at position 6" << endl;
    displayList(listPtr);
	cout << "Length : " << listPtr->getLength() << "; should be 5" << endl << endl;
	
	cout << "Remove first entry" << endl;
	listPtr->remove(1);
	displayList(listPtr);
	cout << "Length : " << listPtr->getLength() << "; should be 4" << endl << endl;
	
	cout << "Remove last entry" << endl;
	listPtr->remove(4);
	displayList(listPtr);
	cout << "Length : " << listPtr->getLength() << "; should be 3" << endl << endl;
	
	cout << "Remove remaining entries" << endl;
	listPtr->remove(1);
	listPtr->remove(1);
	listPtr->remove(1);
	displayList(listPtr);
	cout << "Length : " << listPtr->getLength() << "; should be 0" << endl << endl;

	cout << "Try to remove entry from empty list" << endl;
	if (listPtr->remove(1))
         cout << "Removed an entry" << endl;
    else
         cout << "Cannot remove entry" << endl;
	
	// test clear
	listPtr->insert(1, "one");
	displayList(listPtr);
	cout << "Length : " << listPtr->getLength() << "; should be 1" << endl << endl;		
	
	listPtr->insert(2, "two");
	displayList(listPtr);
	cout << "Length : " << listPtr->getLength() << "; should be 2" << endl << endl;
	
	cout << "Clearing list" << endl;
	listPtr->clear();
	displayList(listPtr);
	cout << "Length : " << listPtr->getLength() << "; should be 0" << endl << endl;	
	
	// test getPosition
	cout << "Testing getPostion method" << endl;
	listPtr->insert(1, "one");
	listPtr->insert(2, "two");	
	listPtr->insert(3, "three");
	listPtr->insert(4, "one");
	listPtr->insert(5, "two");
	displayList(listPtr);
	cout << "The position of \"one\" is: " << listPtr->getPosition("one") << "; should be 1" << endl;
	cout << "The position of \"two\" is: " << listPtr->getPosition("two") << "; should be 2" << endl;
	cout << "The position of \"three\" is: " << listPtr->getPosition("three") << "; should be 3" << endl;
	cout << "The position of \"four\" is: " << listPtr->getPosition("four") << "; should be 0 if not found" << endl << endl;
	
	
	//test second remove
	cout << "Testing the new remove method" << endl;
	displayList(listPtr);
	cout << endl;
	
	cout << "Removing \"one\" from list" << endl;
	if (listPtr->remove("one"))
         cout << "Removed an entry" << endl;
    else
         cout << "Cannot remove entry" << endl;
	displayList(listPtr);
	cout << endl;
	
	cout << "Removing \"three\" from list" << endl;
	if (listPtr->remove("three"))
         cout << "Removed an entry" << endl;
    else
         cout << "Cannot remove entry" << endl;
	displayList(listPtr);
	cout << endl;
	
	cout << "Removing \"two\" from list" << endl;
	if (listPtr->remove("two"))
         cout << "Removed an entry" << endl;
    else
         cout << "Cannot remove entry" << endl;
	displayList(listPtr);
	cout << endl;
	
	cout << "Removing \"four\" from list" << endl;
	if (listPtr->remove("four"))
         cout << "Removed an entry" << endl;
    else
         cout << "Cannot remove entry" << endl;
	displayList(listPtr);
	cout << endl;
	
	cout << "Clearing list" << endl;
	listPtr->clear();
	displayList(listPtr);
	cout << "Length : " << listPtr->getLength() << "; should be 0" << endl << endl;
	
	return 0;
}  // end main
