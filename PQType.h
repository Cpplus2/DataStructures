#ifndef PQTYPE_H_INCLUDED
#define PQTYPE_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>

#include "Heap.h"

using namespace std;

class FullPQ
{
    private:
        string message;

    public:
        FullPQ()
        {
            message = "Priority Queue Full";
        }
        string GetMessage()
        {
            return message;
        }
};

class EmptyPQ
{
    private:
        string message;

    public:
        EmptyPQ()
        {
            message = "Priority Queue Empty";
        }
        string GetMessage()
        {
            return message;
        }
};

template<class ItemType>
class PQType
{
    private:
        int length;
        Heap<ItemType> items;
        int maxItems;

    public:
        PQType(int);
        ~PQType();
        void MakeEmpty();
        bool IsEmpty() const;
        bool IsFull() const;
        void Enqueue(ItemType);
        void Dequeue(ItemType&);
};

#endif // PQTYPE_H_INCLUDED
