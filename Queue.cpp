#ifndef QUEUE_CPP
#define QUEUE_CPP

#include "Queue.h"

template<class ItemType>
Queue<ItemType>::Queue()
{
    maxQueue = 501;
    front = maxQueue-1;
    rear = maxQueue-1;
    items = new ItemType[maxQueue];
}

template<class ItemType>
Queue<ItemType>::Queue(int maximum)
{
    maxQueue = maximum;
    front = maximum-1;
    rear = maximum-1;
    items = new ItemType[maximum];
}

template<class ItemType>
Queue<ItemType>::~Queue()
{
    delete [] items;
}

template<class ItemType>
void Queue<ItemType>::MakeEmpty()
{
    front = maxQueue - 1;
    rear = maxQueue -1;
}

template<class ItemType>
bool Queue<ItemType>::IsEmpty() const
{
    return (rear == front);
}

template<class ItemType>
bool Queue<ItemType>::IsFull() const
{
    return ((rear+1)%maxQueue)==front;
}

template<class ItemType>
void Queue<ItemType>::Enqueue(ItemType newItem)
{
    if(IsFull())
        throw FullQueue();
    else
    {
        rear = (rear+1) % maxQueue;
        items[rear] = newItem;
    }
}

template<class ItemType>
void Queue<ItemType>::Dequeue(ItemType& item)
{
    if(IsEmpty())
        throw EmptyQueue();
    else
    {
        front = (front+1) % maxQueue;
        item = items[front];
    }
}

#endif // QUEUE_CPP
