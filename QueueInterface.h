/** @file QueueInterface.h
 * @class QueueInterface
 * Interface for classes that create a queue. */

#ifndef QUEUE_INTERFACE_
#define QUEUE_INTERFACE_

template<class ItemType>
class QueueInterface
{
public:
    /** Sees whether this queue is empty.
     * @pre None
     * @post Does not change the queue
     * @return True if the queue is empty, or false if not. */
    virtual bool isEmpty() const = 0;

    /** Adds a new entry to the back of this queue.
     * @pre None
     * @post If the operation was successful, the item is at the back of the queue.
     * @param someItem The object to be added as a new entry.
     * @return True if the addition is successful, or false if not. */
    virtual bool enqueue(const ItemType& someItem) = 0;

    /** Removes the front of this queue.
     * @pre None
     * @post If the operation was successful, the front of the queue has been removed.
     * @return True if the removal is successful, or false if not. */
    virtual bool dequeue() = 0;

    /** Returns a copy of the front of this queue.
     * @pre The queue is not empty.
     * @post A copy of the front of the queue has been returned, and the queue is unchanged.
     * @return A copy of the front of the queue. */
    virtual ItemType peekFront() const = 0;

    /** Removes all entries from this queue.
     * @pre None
     * @post The queue is empty. */
    virtual void clear() = 0;

    /** Destructor */
    virtual ~QueueInterface() {}
}; // end QueueInterface

#endif
