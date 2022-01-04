
/** Header file for an array-based implementation of the ADT Set.
 @file ArraySet.h */

#ifndef ARRAY_SET_
#define ARRAY_SET_

#include "SetInterface.h"

template<class ItemType>
class ArraySet : public SetInterface<ItemType>
{
private:
	static const int DEFAULT_CAPACITY = 10; 
	ItemType items[DEFAULT_CAPACITY];      // Array of set items
	int itemCount;                         // Current count of set items 
	int maxItems;                          // Max capacity of the set
	// Returns either the index of the element in the array items that
	// contains the given target or -1, if the array does not contain 
	// the target.
	int getIndexOf(const ItemType& target) const;   

public:
	ArraySet();
	ArraySet(const ItemType anArray[], int count);
	int getCurrentSize() const;
	bool isEmpty() const;
	bool add(const ItemType& newEntry);
	bool remove(const ItemType& anEntry);
	void clear();
	bool contains(const ItemType& anEntry) const;
	std::vector<ItemType> toVector() const;
}; // end ArraySet

/** Implementation file for the class ArraySet.
 @file ArraySet.cpp */

#include <cstddef>

template<class ItemType>
ArraySet<ItemType>::ArraySet(): itemCount(0), maxItems(DEFAULT_CAPACITY)
{
}  // end default constructor

template<class ItemType>
ArraySet<ItemType>::ArraySet(const ItemType anArray[], int count)
{
	for (int i=0; i < count; i++)
	{
		items[i]=anArray[i];
	}
	itemCount = count;
	maxItems = DEFAULT_CAPACITY;
}  // end of second constructor

template<class ItemType>
int ArraySet<ItemType>::getCurrentSize() const
{
	return itemCount;
}  // end getCurrentSize

template<class ItemType>
bool ArraySet<ItemType>::isEmpty() const
{
	return itemCount == 0;
}  // end isEmpty

template<class ItemType>
bool ArraySet<ItemType>::add(const ItemType& newEntry)
{
	bool hasRoomToAdd = (itemCount < maxItems);
	bool duplicate = contains(newEntry);
	if (hasRoomToAdd && !duplicate)
	{
		items[itemCount] = newEntry;
		itemCount++;
	}  // end if
    
	return hasRoomToAdd;
}  // end add

template<class ItemType>
bool ArraySet<ItemType>::remove(const ItemType& anEntry)
{
   int locatedIndex = getIndexOf(anEntry);
	bool canRemoveItem = !isEmpty() && (locatedIndex > -1);
	if (canRemoveItem)
	{
		itemCount--;
		items[locatedIndex] = items[itemCount];
	}  // end if
    
	return canRemoveItem;
}  // end remove

template<class ItemType>
void ArraySet<ItemType>::clear()
{
	itemCount = 0;
}  // end clear

template<class ItemType>
bool ArraySet<ItemType>::contains(const ItemType& anEntry) const
{
	return getIndexOf(anEntry) > -1;
}  // end contains

template<class ItemType>
std::vector<ItemType> ArraySet<ItemType>::toVector() const
{
   std::vector<ItemType> setContents;
	for (int i = 0; i < itemCount; i++)
		setContents.push_back(items[i]);
      
   return setContents;
}  // end toVector

// private
template<class ItemType>
int ArraySet<ItemType>::getIndexOf(const ItemType& target) const
{
	bool found = false;
	int result = -1;
	int searchIndex = 0;
   
	// If the set is empty, itemCount is zero, so loop is skipped
	while (!found && (searchIndex < itemCount))
	{
  		if (items[searchIndex] == target)
    	{
        	found = true;
        	result = searchIndex;
    	} 
    	else
    	{
        	searchIndex++;
    	}  // end if
	}  // end while
   
	return result;
} 	// end getIndexOf
#endif
