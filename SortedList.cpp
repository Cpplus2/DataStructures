#ifndef SORTEDLIST_CPP
#define SORTEDLIST_CPP

#include "SortedList.h"

SortedList::SortedList()
{
    listData = NULL;
    cursor = NULL;
    length = 0;
}

SortedList::~SortedList()
{
    NodeType* tempPtr;

    while(listData != NULL)
    {
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
    }
}

int SortedList::GetLength()
{
    return length;
}

ItemType SortedList::GetItem(ItemType otherItem, bool& found)
{
    NodeType* location = listData;
    bool moreToSearch = (location != NULL);
    found = false;

    while(moreToSearch && !found)
    {
        switch(otherItem.ComparedTo(location->info))
        {
            case LESS:
            case GREATER:
                location = location->next;
                moreToSearch = (location != NULL);
                break;

            case EQUAL:
                found = true;
                otherItem = location->info;
        }
    }
    return otherItem;
}

void SortedList::DeleteItem(ItemType otherItem)
{
    NodeType * location = listData;
    NodeType * tempLocation;

    if(otherItem.ComparedTo(listData->info) != EQUAL)
    {
        tempLocation = location;
        listData = listData->next;
    }
    else
    {
        while(otherItem.ComparedTo(location->next->info) != EQUAL)
            location = location->next;

        tempLocation = location->next;
        location->next = (location->next)->next;
    }

    delete tempLocation;
    length--;
}

void SortedList::InsertItem(ItemType otherItem)
{
    NodeType* location = new NodeType;
    location->info = otherItem;
    location->next = listData;

    listData = location;
    length++;
}

void SortedList::MakeEmpty()
{
    NodeType* tempPtr = listData;

    while(listData != NULL)
    {
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
    }
    length = 0;
}

bool SortedList::IsEmpty()
{
    NodeType* location;

    try{
        location = new NodeType;
        delete location;
        return false;
    }
    catch(bad_alloc exception)
    {
        return true;
    }
}

void SortedList::ResetList()
{
    cursor = NULL;
}

ItemType SortedList::GetNextItem()
{
    if(cursor == NULL)
        cursor = listData;
    else
        cursor = cursor->next;

    return cursor->info;
}

#endif // SORTEDLIST_CPP
