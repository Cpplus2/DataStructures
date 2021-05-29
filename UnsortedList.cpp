#ifndef UNSORTEDLIST_CPP
#define UNSORTEDLIST_CPP

#include "UnsortedList.h"

UnsortedList::UnsortedList()
{
    length = 0;
    listData = currentPos = NULL;
}

UnsortedList::~UnsortedList()
{
    NodeType* tempPtr;

    while(listData != NULL)
    {
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
    }
}

void UnsortedList::MakeEmpty()
{
    NodeType* tempPtr;

    while(listData != NULL)
    {
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
    }
    length = 0;
}

bool UnsortedList::IsFull() const
{
    NodeType * location;

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

ItemType UnsortedList::GetNextItem()
{
    ItemType tempItem;

    if(currentPos == NULL)
        currentPos = listData;
    else
        currentPos = currentPos->next;

    tempItem = currentPos->info;

    return tempItem;
}

void UnsortedList::ResetList()
{
    currentPos = NULL;
}

void UnsortedList::InsertItem(ItemType otherItem)
{
    NodeType* tempLocation = new NodeType;
    tempLocation->info = otherItem;
    tempLocation->next = listData;
    listData = tempLocation;
    length++;
}

void UnsortedList::DeleteItem(ItemType otherItem)
{
    NodeType* location = listData;
    NodeType* tempLocation;

    if(otherItem.ComparedTo(location->info) == EQUAL)
    {
        tempLocation = location;
        listData = listData->next;
    }
    else
    {
        while(otherItem.ComparedTo((location->next)->info) != EQUAL)
            location = location->next;

        tempLocation = location->next;
        location->next = (location->next)->next;
    }
    delete tempLocation;
    length--;
}

ItemType UnsortedList::GetItem(ItemType otherItem, bool& found)
{
    NodeType* location; location = listData;
    bool moreToSearch = (location != NULL);
    found = false;

    while(moreToSearch && found)
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

#endif // UNSORTEDLIST_CPP
