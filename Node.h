/** @file Node.h
 * @class Node
 * Implements a node to hold an item and a smart pointer. */

#ifndef NODE_
#define NODE_

#include <memory>

template<class ItemType>
class Node
{
private:
    /** A data item stored in the node. */
    ItemType item;

    /** A shared pointer to the next node in the list. */
    std::shared_ptr<Node<ItemType>> next;

public:
    /** Default constructor that initializes an empty node. */
    Node();

    /** Constructs a node with a given item and no link to a next node.
     * @param anItem The item to store in the node. */
    Node(const ItemType& anItem);

    /** Constructs a node with a given item and a link to a specified next node.
     * @param anItem The item to store in the node.
     * @param nextNodePtr A shared pointer to the next node. */
    Node(const ItemType& anItem, std::shared_ptr<Node<ItemType>> nextNodePtr);

    /** Sets the item stored in the node.
     * @pre None
     * @post None
     * @param anItem The item to store in the node. */
    void setItem(const ItemType& anItem) noexcept;

    /** Sets the link to the next node in the list.
     * @pre None
     * @post None
     * @param nextNodePtr A shared pointer to the next node. */
    void setNext(std::shared_ptr<Node<ItemType>> nextNodePtr) noexcept;

    /** Retrieves the item stored in the node.
     * @pre None
     * @post None
     * @return The item stored in the node. */
    ItemType getItem() const noexcept;

    /** Retrieves the next node in the list.
     * @pre None
     * @post None
     * @return A shared pointer to the next node in the list. */
    auto getNext() const noexcept;

}; // end Node

#include "Node.cpp"
#endif