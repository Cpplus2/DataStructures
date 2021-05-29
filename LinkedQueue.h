#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

template<class ItemType>
struct NodeType{
    ItemType info;
    NodeType* next;
};

class FullQueue
{
    private:
        string message;

    public:
        FullQueue()
        {
            message = "Queue Full";
        }
        string getMessage()
        {
            return message;
        }
};

class EmptyQueue
{
    private:
        string message;

    public:
        EmtptyQueue()
        {
            message = "Queue Empty";
        }
        string getMessage()
        {
            return message;
        }
};

template<class ItemType>
class LinkedQueue
{
    public:
        LinkedQueue();
        ~LinkedQueue();
        void MakeEmpty();
        void Enqueue(ItemType);
        void Dequeue(ItemType&);
        bool IsEmpty() const;
        bool IsFull() const;

    private:
        NodeType<ItemType>* front;
        NodeType<ItemType>* rear;
};

#include "LinkedQueue.cpp"

#endif // LINKEDQUEUE_H
