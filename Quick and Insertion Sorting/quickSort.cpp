#include <iostream>

const int MIN_SIZE = 4;

/** 	Swaps the values of two variable items.
@pre  	a and b are two different varible items.
@post 	the values of a and b will be swapped.
@param	a 		one of the two given items to swap.
@param	b 		one of the two given items to swap.
@param	temp 	a temporary item that is used to 
 		hold the value of one of the two provided items. */
template <class ItemType>
void swap(ItemType& a, ItemType& b)
{
	ItemType temp = a;
	a = b;
	b = temp;
}// end swap

/** 	Arranges the first, middle, and last entries 
		in an array into ascending order.
@pre	array must be of size 3 or greater.
@post 	the first, middle and last entries are arranged
		into ascending order.
@param	theArray 	The given array.
@param	first  		The index of the first element to consider in theArray.
@param	mid  		The index of the middle element to consider in theArray.
@param	last 		The index of the last element to consider in theArray. */
template <class ItemType>
void sortFirstMiddleLast(ItemType theArray[], int first, int mid, int last)
{
	if (theArray[first] > theArray[mid])
	{
		/*int temp = theArray[first];
		theArray[first] = theArray[mid];
		theArray[mid] = theArray[temp];*/
		swap(theArray[first], theArray[mid]);
	}
	if (theArray[mid] > theArray[last])
	{
		/*int temp = theArray[mid];
		theArray[mid] = theArray[last];
		theArray[last] = theArray[temp];*/
		swap(theArray[mid], theArray[last]);
	}
	if (theArray[first] > theArray[mid])
	{
		/*int temp = theArray[first];
		theArray[first] = theArray[mid];
		theArray[mid] = theArray[temp];*/
		swap(theArray[first], theArray[mid]);
	}
}

/**		Partitions a given array theArray[].
@pre  	theArray[first..last] is an array.
@post 	theArray[first..last] is partitioned.
@param	theArray  	The given array.
@param	first 		The index of the first element to consider in theArray.
@param	last  		The index of the last element to consider in theArray. */
template <class ItemType>
int partition(ItemType theArray[], int first, int last)
{
	int mid = first + (last - first) / 2;
	sortFirstMiddleLast(theArray, first, mid, last);
	swap(theArray[mid], theArray[last - 1]);
	int pivotIndex = last -1;
	ItemType pivot = theArray[pivotIndex];
	int indexFromLeft = first + 1;
	int indexFromRight = last - 2;
	
	bool done = false;
	while (!done)
	{
		while (theArray[indexFromLeft] < pivot)
		{
			indexFromLeft = indexFromLeft + 1;
		}
		while (theArray[indexFromRight] > pivot)
		{
			indexFromRight = indexFromRight - 1;
		}
		if (indexFromLeft < indexFromRight)
		{
			swap(theArray[indexFromLeft], theArray[indexFromRight]);
			indexFromLeft = indexFromLeft + 1;
			indexFromRight = indexFromRight - 1;
		}
		else done = true;
	} 
	swap(theArray[pivotIndex], theArray[indexFromLeft]);
	pivotIndex = indexFromLeft;
	
	return pivotIndex;
}



/**		Sorts an array into ascending order. Uses the quick sort with
    	median-of-three pivot selection for arrays of at least MIN_SIZE
    	entries, and uses the insertion sort for other arrays.
@pre  	theArray[first..last] is an array.
@post 	theArray[first..last] is sorted.
@param	theArray  	The given array.
@param	first  		The index of the first element to consider in theArray.
@param	last  		The index of the last element to consider in theArray. */
template <class ItemType>
void quickSort(ItemType theArray[], int first, int last)
{
	
	if ((last - first + 1) < MIN_SIZE)
	{
		std::cout << "Calling insertionSort with array of " << last - first + 1 << std::endl;
    	insertionSort(theArray, first, last);
	}
	else
  	{
		// Create the partition: S1 | Pivot | S2
      	int pivotIndex = partition(theArray, first, last);
      
      	// Sort subarrays S1 and S2
      	std::cout << "Calling quickSort with left side size of " << pivotIndex - first;
      	std::cout << " and right side size of " << last - pivotIndex << std::endl;
      	quickSort(theArray, first, pivotIndex - 1);
      	std::cout << "Calling quickSort with right side size of " << last - pivotIndex;
      	std::cout << " and left side size of " << pivotIndex - first << std::endl;
      	quickSort(theArray, pivotIndex + 1, last);
   	}// end if
}// end quickSort










