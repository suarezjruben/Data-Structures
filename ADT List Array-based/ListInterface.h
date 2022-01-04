/** Interface for the ADT list
    @file ListInterface.h */

#ifndef _LIST_INTERFACE
#define _LIST_INTERFACE

template<class ItemType>
class ListInterface
{
public:
   /** Sees whether this list is empty.
    @return True if the list is empty; otherwise returns false. */
   virtual bool isEmpty() const = 0;
   
   /** Gets the current number of entries in this list.
    @return The integer number of entries currently in the list. */
   virtual int getLength() const = 0;
   
   /** Inserts an entry into this list at a given position.
    @pre  None.
    @post  If 1 <= position <= getLength() + 1 and the insertion is
       successful, newEntry is at the given position in the list,
       other entries are renumbered accordingly, and the returned
       value is true.
    @param newPosition  The list position at which to insert newEntry.
    @param newEntry  The entry to insert into the list.
    @return  True if insertion is successful, or false if not. */
   virtual bool insert(int newPosition, const ItemType& newEntry) = 0;
   
   /** Removes the entry at a given position from this list.
    @pre  None.
    @post  If 1 <= position <= getLength() and the removal is successful,
       the entry at the given position in the list is removed, other
       items are renumbered accordingly, and the returned value is true.
    @param position  The list position of the entry to remove.
    @return  True if removal is successful, or false if not. */
   virtual bool remove(int position) = 0;
   
   /** Removes all entries from this list.
    @post  List contains no entries and the count of items is 0. */
   virtual void clear() = 0;
   
   /** Gets the entry at the given position in this list.
    @pre  1 <= position <= getLength().
    @post  The desired entry has been returned.
    @param position  The list position of the desired entry.
    @return  The entry at the given position. */
   virtual ItemType getEntry(int position) const = 0;
   
   /** Replaces the entry at the given position in this list.
    @pre  1 <= position <= getLength().
    @post  The entry at the given position is newEntry.
    @param position  The list position of the entry to replace.
    @param newEntry  The replacement entry. */
   virtual void replace(int position, const ItemType& newEntry) = 0;
   
   /** Gets the position at the given entry in this list.
    @pre	None.
    @post	The desired postion has been returned.
    @param	entry 	The list entry of the desired position.
    @retrun	The position at the given entry. */
   virtual int getPosition(const ItemType& entry) const = 0;
   
   /** Removes first entry that matches a specifed entry.
    @pre	None.
    @post	The first occurance of the given entry has been removed.
    @param	entry	The list entry to be removed.
    @return	True if removal is successful, or fase if not.	*/
   virtual bool remove(const ItemType& entry) = 0;
   
}; // end ListInterface
#endif






