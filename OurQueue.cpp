/** @file OurQueue.cpp
 * OurQueue implenents a queue using the STL Queue class.
 * @author Stephen Wagner
 * @date 11/5/2024
 * CSCI 591 Section 1 */

#include "OurQueue.h"

// Default constructor. Initializes an empty queue.
template<class ItemType>
OurQueue<ItemType>::OurQueue()
{ } // end default constructor

// Destructor. Automatically cleans up the queue.
template<class ItemType>
OurQueue<ItemType>::~OurQueue()
{
    clear(); // Uses clear
} // end destructor

// Checks if the queue is empty.
template<class ItemType>
bool OurQueue<ItemType>::isEmpty() const noexcept
{
    return stlQueue.empty();
} // end isEmpty

// Adds a new entry to the back of the queue.
template<class ItemType>
bool OurQueue<ItemType>::enqueue(const ItemType& someItem) noexcept
{
    stlQueue.push(someItem);
    return true;
} // end enqueue

// Removes the item at the front of the queue.
template<class ItemType>
bool OurQueue<ItemType>::dequeue() noexcept
{
    if (!stlQueue.empty())
    {
        stlQueue.pop();
        return true;
    }
    return false;
} // end dequeue

// Retrieves the item at the front of the queue. Throws PrecondViolatedExcept if the queue is empty.
template<class ItemType>
ItemType OurQueue<ItemType>::peekFront() const
{
    if (stlQueue.empty())
    {
        throw PrecondViolatedExcept("peekFront() called with empty queue.");
    }
    return stlQueue.front();
} // end peekFront

// Removes all items from the queue by popping until it is empty.
template<class ItemType>
void OurQueue<ItemType>::clear()
{
    while (!stlQueue.empty())
    {
        stlQueue.pop();
    }
} // end clear