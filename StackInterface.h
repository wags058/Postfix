/** @file StackInterface.h 
 * @class StackInterface
 * Interface for classes that create a stack. */

#ifndef STACK_INTERFACE_
#define STACK_INTERFACE_

template<class ItemType>
class StackInterface
{
public:
    /** Checks whether this stack is empty.
     * @pre None
     * @post Does not change the stack.
     * @return True if the stack is empty, or false if not. */
    virtual bool isEmpty() const = 0;

    /** Adds a new entry to the top of this stack.
     * @pre None
     * @post If the operation was successful, someItem is at the top of the stack.
     * @param someItem The object to be added as a new entry.
     * @return True if the addition is successful, or false if not. */
    virtual bool push(const ItemType& someItem) = 0;

    /** Removes the top of this stack.
     * @pre None
     * @post If the operation was successful, the top of the stack has been removed.
     * @return True if the removal is successful, or false if not. */
    virtual bool pop() = 0;

    /** Returns a copy of the top of this stack.
     * @pre The stack is not empty.
     * @post A copy of the top of the stack has been returned, and the stack is unchanged.
     * @return A copy of the top of the stack. */
    virtual ItemType peek() const = 0;

    /** Removes all entries from this stack.
     * @pre None 
     * @post The stack is empty. */
    virtual void clear() = 0;

    /** Destroys this stack and frees its assigned memory. */
    virtual ~StackInterface() {}

}; // end StackInterface

#endif
