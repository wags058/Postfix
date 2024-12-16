/** @file LinkedStack.cpp
 * LinkedStack creates a stack using a linked list of nodes with smart pointers.
 * @author Stephen Wagner
 * @date 11/5/2024
 * CSCI 591 Section 1 */

#include "LinkedStack.h"
#include "PrecondViolatedExcept.h"

// Default constructor initializes the stack as empty by setting the top pointer to nullptr.
template<class ItemType>
LinkedStack<ItemType>::LinkedStack() : topPtr(nullptr)
{} // end default constructor

// Copy constructor that creates a deep copy of the original stack.
template<class ItemType>
LinkedStack<ItemType>::LinkedStack(const LinkedStack<ItemType>& originalStack)
{
    // Initialize a pointer to traverse the original stack
    auto originalChainPtr = originalStack.topPtr;
    if (originalChainPtr == nullptr)
        topPtr = nullptr;  // Original stack was empty
    else
    {
        // Copy the first node of the original stack
        topPtr = std::make_shared<Node<ItemType>>();
        topPtr->setItem(originalChainPtr->getItem());

        // Create a pointer to track the end of the new chain
        auto myChainTailPtr = topPtr;

        // Move to the next node in the original stack
        originalChainPtr = originalChainPtr->getNext();

        // Copy all remaining nodes from the original stack
        while (originalChainPtr != nullptr)
        {
            // Copy the next item from the original stack
            auto nextItem = originalChainPtr->getItem();
            auto itemNodePtr = std::make_shared<Node<ItemType>>(nextItem);

            // Link the new node to the end of the new chain
            myChainTailPtr->setNext(itemNodePtr);
            myChainTailPtr = myChainTailPtr->getNext();

            // Move to the next node in the original stack
            originalChainPtr = originalChainPtr->getNext();
        }

        myChainTailPtr->setNext(nullptr); // Flag the end of the new chain
    }
} // end copy constructor

// Destructor that clears all nodes from the stack.
template<class ItemType>
LinkedStack<ItemType>::~LinkedStack()
{
    clear();  // Clear the stack by setting topPtr to nullptr
} // end destructor

// Checks if the stack is empty.
template<class ItemType>
bool LinkedStack<ItemType>::isEmpty() const noexcept
{
    return topPtr == nullptr;
}  // end isEmpty

// Pushes an item onto the top of the stack.
template<class ItemType>
bool LinkedStack<ItemType>::push(const ItemType& someItem) noexcept
{
    // Create a new node pointing to the current top of the stack
    auto itemNodePtr = std::make_shared<Node<ItemType>>(someItem, topPtr);

    // Update the top pointer to the new node
    topPtr = itemNodePtr;
    return true;
}  // end push

// Pops (removes) the item at the top of the stack.
template<class ItemType>
bool LinkedStack<ItemType>::pop() noexcept
{
    if (!isEmpty())
    {
        // Hold the current top node to delete it
        auto nodeToDeletePtr = topPtr;

        // Update topPtr to the next node in the stack
        topPtr = topPtr->getNext();

        // Disconnect the node to delete from the stack
        nodeToDeletePtr->setNext(nullptr);
        nodeToDeletePtr.reset();  // Automatically deallocates the node
        return true;
    }
    return false;  // Stack was empty, nothing to pop
}  // end pop

// Retrieves the item at the top of the stack without removing it.
template<class ItemType>
ItemType LinkedStack<ItemType>::peek() const
{
    // Check if the stack is empty before peeking
    if (isEmpty())
        throw PrecondViolatedExcept("peek() called with empty stack.");

    return topPtr->getItem();  // Return the item at the top of the stack
}  // end peek

// Clears all items from the stack.
template<class ItemType>
void LinkedStack<ItemType>::clear()
{
    topPtr = nullptr;  // Automatically deallocates all nodes in the stack
} // end clear