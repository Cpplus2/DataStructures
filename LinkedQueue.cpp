#ifndef LINKEDQUEUE_CPP
#define LINKEDQUEUE_CPP

#include "LinkedQueue.h"

template<class ItemType>
LinkedQueue<ItemType>::LinkedQueue()
{
    front = NULL;
    rear = NULL;
}

template<class ItemType>
bool LinkedQueue<ItemType>::IsEmpty() const
{
    return (front == NULL);
}

template<class ItemType>
bool LinkedQueue<ItemType>::IsFull() const
{
    NodeType<ItemType>* location;

    try{
        location = new NodeType<ItemType>;
        delete location;
        return false;
    }
    catch(bad_alloc exception)
    {
        return true;
    }
}

template<class ItemType>
void LinkedQueue<ItemType>::Enqueue(ItemType newItem)
{
    if(IsFull())
        throw FullQueue();
    else
    {
        NodeType<ItemType>* newNode;

        newNode = new NodeType<ItemType>;
        newNode->info = newItem;
        newNode->next = NULL;

        if(rear == NULL)
            front = newNode;
        else
            rear->next = newNode;
    }
}

template<class ItemType>
void LinkedQueue<ItemType>::Dequeue(ItemType& item)
{
    if(IsEmpty())
        throw EmptyQueue();
    else
    {
        NodeType<ItemType>* tempPtr;

        tempPtr = front;
        item = front->info;     //FIFO
        front = front->next;        //Remove first item and get next

        if(front == NULL)               //If next item doesn't exit
            rear = NULL;                    //Neither does rear item
    }
}

#endif // LINKEDQUEUE_CPP
