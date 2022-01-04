#include "insertionSort.cpp"
#include "quickSort.cpp"
#include <string>
using namespace std;

template <class ItemType>
void display(ItemType theArray[], int size)
{
	for (int i = 0; i < size; i++)
        std::cout << theArray[i] << " ";
    cout << endl << endl;
}

int main ()
{
	// Array of strings
	string a[27] = {"B", "Z", "Y", "X", "W", "V", "U", "T", "S", "R", "Q", "P", "O", "N",
						 "M", "L", "K", "J", "I", "H", "G", "F", "E", "D", "C", "B", "A"};
  
    cout << "Sortin array with 27 items:" << endl;
	display(a, 27);  
    quickSort(a, 0, 26);
    cout << endl;
    display(a, 27);

    
    // Array of integers
    int b[30] = {5, 1, 4, 7, 2, 51, 72, 6, 57, 8, 59, 84, 52, 63, 58,
					 9, 45, 25, 63, 25, 3, 10, 12, 89, 15, 19, 25, 11, 46, 53};
	
	cout << "Sortin array with 30 items:" << endl;
	display(b, 30);				
	quickSort(b, 0, 29);
	cout << endl;
	display(b, 30);	
    

    return 0;
}
