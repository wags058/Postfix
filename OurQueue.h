/** @file OurQueue.h
 * @class OurQueue
 * Implements a queue using the STL Queue class and inherits from QueueInterface. */

#ifndef OUR_QUEUE_
#define OUR_QUEUE_

#include <queue>
#include "QueueInterface.h"
#include "PrecondViolatedExcept.h"


template<class ItemType>
class OurQueue : public QueueInterface<ItemType>
{
private:
    /** The internal STL queue used to store items. */
    std::queue<ItemType> stlQueue;

public:
    /** Default constructor. Initializes an empty queue. */
    OurQueue();

    /** Sees whether this queue is empty.
     * @pre None
     * @post Does not change the queue
     * @return True if the queue is empty, or false if not. */
    bool isEmpty() const noexcept override;

    /** Adds a new entry to the back of this queue.
     * @pre None
     * @post If the operation was successful, the item is at the back of the queue.
     * @param someItem The object to be added as a new entry.
     * @return True if the addition is successful, or false if not. */
    bool enqueue(const ItemType& someItem) noexcept override;

    /** Removes the front of this queue.
     * @pre None
     * @post If the operation was successful, the front of the queue has been removed.
     * @return True if the removal is successful, or false if not. */
    bool dequeue() noexcept override;

    /** Returns a copy of the front of this queue.
     * @pre The queue is not empty.
     * @post A copy of the front of the queue has been returned, and the queue is unchanged.
     * @return A copy of the front of the queue.
     * @throws PrecondViolatedExcept if the queue is empty. */
    ItemType peekFront() const override;

    /** Removes all entries from this queue.
     * @pre None
     * @post The queue is empty. */
    void clear() final override;

    /** Destructor */
    virtual ~OurQueue();
};

#include "OurQueue.cpp"
#endif
