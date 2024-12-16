/** @file Node.cpp
 * Node implenents a node to hold an item and a smart pointer to the next node.
 * @author Stephen Wagner
 * @date 11/5/2024
 * CSCI 591 Section 1 */

#include "Node.h"

template<class ItemType>
Node<ItemType>::Node()
{ } // end default constructor

template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem) : item(anItem)
{ } // end parameterized constructor

template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem,
    std::shared_ptr<Node<ItemType>> nextNodePtr)
    : item(anItem), next(nextNodePtr)
{ } // end parameterized constructor

template<class ItemType>
void Node<ItemType>::setItem(const ItemType& anItem) noexcept
{
    item = anItem;
}  // end setItem

template<class ItemType>
void Node<ItemType>::setNext(std::shared_ptr<Node<ItemType>> nextNodePtr) noexcept
{
    next = nextNodePtr;
}  // end setNext

template<class ItemType>
ItemType Node<ItemType>::getItem() const noexcept
{
    return item;
}  // end getItem

template<class ItemType>
auto Node<ItemType>::getNext() const noexcept
{
    return next;
}  // end getNext