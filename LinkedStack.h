/** @file LinkedStack.h
 * @class LinkedStack
 * Implements a stack using a linked list of nodes with smart pointers and inherits from StackInterface. */

#ifndef LINKED_STACK_
#define LINKED_STACK_

#include "StackInterface.h"
#include "Node.h"
#include <memory>

template<class ItemType>
class LinkedStack : public StackInterface<ItemType>
{
private:
    /** Pointer to the top node in the stack */
    std::shared_ptr<Node<ItemType>> topPtr;

public:
    /** Default constructor
     * Initializes the stack to be empty. */
    LinkedStack();

    /** Copy constructor
     * Creates a copy of another LinkedStack.
     * @param originalStack The stack to be copied. */
    LinkedStack(const LinkedStack<ItemType>& originalStack);

    /** Destructor
     * Frees the dynamically allocated memory. */
    virtual ~LinkedStack();

    /** Checks if the stack is empty.
     * @pre None
     * @post Does not change the stack
     * @return True if the stack is empty, false otherwise. */
    bool isEmpty() const noexcept override;

    /** Adds a new entry to the top of this stack.
     * @pre None
     * @post If the operation was successful, someItem is at the top of the stack.
     * @param someItem The object to be added as a new entry.
     * @return True if the addition is successful, or false if not. */
    bool push(const ItemType& someItem) noexcept override;

    /** Removes the top of this stack.
     * @pre None
     * @post If the operation was successful, the top of the stack has been removed.
     * @return True if the removal is successful, or false if not. */
    bool pop() noexcept override;

    /** Retrieves a copt of the top item of this stack.
     * @pre The stack is not empty.
     * @post A copy of the top item is returned, and the stack remains unchanged.
     * @return A copy of the top item of the stack.
     * @throws PreconditionViolationException if the stack is empty. */
    ItemType peek() const override;

    /** Clears all items from the stack.
     * @pre None 
     * @post The stack is empty. */
    void clear() final override;

};

#include "LinkedStack.cpp"
#endif
