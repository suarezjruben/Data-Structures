/** ADT list: Array-based implementation.
    @file ArrayList.h */

#ifndef ARRAY_LIST_
#define ARRAY_LIST_

#include "ListInterface.h"
#include <cassert>

template<class ItemType>
class ArrayList : public ListInterface<ItemType>
{
private:
	static const int DEFAULT_CAPACITY = 5; // Small capacity to test for a full list 
	ItemType items[DEFAULT_CAPACITY+1];      // Array of list items (not using element [0]
   int itemCount;                         // Current count of list items 
   int maxItems;                          // Maximum capacity of the list
   
public:
   ArrayList();
   // Copy constructor and destructor are supplied by compiler
   
   bool isEmpty() const;
   int getLength() const;
   bool insert(int newPosition, const ItemType& newEntry);
   bool remove(int position);
   void clear();
   int getPosition(const ItemType& entry) const;
   bool remove(const ItemType& entry);
   
   /** @throw PrecondViolatedExcep if position < 1 or 
                                      position > getLength(). */
   ItemType getEntry(int position) const;

   /** @throw PrecondViolatedExcep if position < 1 or 
                                      position > getLength(). */
   void replace(int position, const ItemType& newEntry);
}; // end ArrayList

/** Implementation file for the class ArrayList.
 @file ArrayList.cpp */

template<class ItemType>
ArrayList<ItemType>::ArrayList() : itemCount(0), maxItems(DEFAULT_CAPACITY)
{
}  // end default constructor

template<class ItemType>
bool ArrayList<ItemType>::isEmpty() const
{
   return itemCount == 0;
}  // end isEmpty

template<class ItemType>
int ArrayList<ItemType>::getLength() const
{
   return itemCount;
}  // end getLength

template<class ItemType>
bool ArrayList<ItemType>::insert(int newPosition, const ItemType& newEntry)
{
   bool ableToInsert = (newPosition >= 1)
                           && (newPosition <= itemCount + 1)
                           && (itemCount < maxItems);
   if (ableToInsert)
   {
      // Make room for new entry by shifting all entries at
      // positions >= newPosition toward the end of the array
      // (no shift if newPosition == itemCount + 1)
      for (int entryPosition = itemCount; entryPosition >= newPosition; entryPosition--)
         items[entryPosition + 1] = items[entryPosition]; // copy the entry right
         
      // Insert new entry
      items[newPosition] = newEntry;
      itemCount++;  // Increase count of entries
   }  // end if
   
   return ableToInsert;
}  // end insert

template<class ItemType>
bool ArrayList<ItemType>::remove(int position)
{
   bool ableToRemove = (position >= 1) && (position <= itemCount);
   if (ableToRemove)
   {
      // Remove entry by shifting all entries after the one at
      // position toward the beginning of the array
      // (no shift if position == itemCount)
      for (int entryPosition = position; entryPosition < itemCount; entryPosition++)
         items[entryPosition] = items[entryPosition + 1]; // copy entry on the right to left
         
      itemCount--;  // Decrease count of entries
   }  // end if
   
   return ableToRemove;
}  // end remove

template<class ItemType>
void ArrayList<ItemType>::clear()
{
   itemCount = 0;
}  // end clear

template<class ItemType>
ItemType ArrayList<ItemType>::getEntry(int position) const
{
   // Enforce precondition
   bool ableToGet = (position >= 1) && (position <= itemCount);

   assert( ableToGet );

   return items[position];
}  // end getEntry

template<class ItemType>
void ArrayList<ItemType>::replace(int position, const ItemType& newEntry)
{
   // Enforce precondition
   bool ableToSet = (position >= 1) && (position <= itemCount);
   assert (ableToSet);

   items[position] = newEntry;
}  // end replace

template<class ItemType>
int ArrayList<ItemType>::getPosition(const ItemType& entry) const
{
	int position = 1;
 	bool found = false;
	while (!found && position <= itemCount && position>=1)
 	{
 	 	if (getEntry(position)==entry)
  	 		found = true;
  		else if (position < itemCount)
 			position++;
  		else
  			position = 0;
	}
 	return position;
}// end getPosition

template<class ItemType>
bool ArrayList<ItemType>::remove(const ItemType& entry)
{
	int position = 1;
 	bool discarded = false;
	while (!discarded && position <= itemCount && position>=1)
 	{
 	 	if (getEntry(position)==entry)
 	 	{
 	 		remove(position);
  	 		discarded = true;
  	 	}
  		else if(position < itemCount)
 			position++;
 		else
  			position = 0;
	}
 	return discarded;
}// end remove

//  End of implementation file.
#endif 
