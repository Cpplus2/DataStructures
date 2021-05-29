#ifndef UNSORTEDLIST_H
#define UNSORTEDLIST_H

#include "ItemType.h"

struct NodeType{
    ItemType info;
    NodeType* next;
};

class UnsortedList
{
    private:
        int length;
        NodeType* currentPos;
        NodeType* listData;

    public:
        UnsortedList();
        ~UnsortedList();
        void MakeEmpty();
        bool IsFull() const;
        bool IsEmpty() const;
        int GetLength();
        ItemType GetItem(ItemType, bool&);
        void InsertItem(ItemType);
        void DeleteItem(ItemType);
        void ResetList();
        ItemType GetNextItem();
};

#endif // UNSORTEDLIST_H

