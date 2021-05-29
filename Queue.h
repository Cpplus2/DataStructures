#ifndef QUEUE_H
#define QUEUE_H

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class FullQueue
{
    private:
        string message;

    public:
        FullQueue()
        {
            message = "Queue Full!";
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
        EmptyQueue()
        {
            message = "Queue Empty!";
        }
        string getMessage()
        {
            return message;
        }
};

template<class ItemType>
class Queue
{
    public:
        Queue();
        Queue(int);
        ~Queue();
        void MakeEmpty();
        bool IsEmpty() const;
        bool IsFull() const;
        void Enqueue(ItemType newItem);
        void Dequeue(ItemType& newItem);

    private:
        int front;
        int rear;
        ItemType* items;
        int maxQueue;
};

#include "Queue.cpp"

#endif // QUEUE_H
