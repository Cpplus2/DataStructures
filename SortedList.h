#ifndef SORTEDLIST_H
#define SORTEDLIST_H

#include "ItemType.h"

struct NodeType{
    ItemType info;
    NodeType* next;
};

class SortedList
{
    private:
        NodeType* listData;
        NodeType* cursor;
        int length;

    public:
        SortedList();
        ~SortedList();
        int GetLength();
        ItemType GetItem(ItemType, bool&);
        void InsertItem(ItemType);
        void MakeEmpty();
        bool IsFull();
        void DeleteItem(ItemType);
        void ResetList();
        ItemType GetNextItem();
};
#endif // SORTEDLIST_H
