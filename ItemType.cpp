#ifndef ITEMTYPE_CPP
#define ITEMTYPE_CPP

#include "ItemType.h"

ItemType::ItemType()
{
    value = 0;
}

void ItemType::Initialize(int newValue)
{
    value = newValue;
}

int ItemType::getValue()
{
    return value;
}

RelationType ItemType::ComparedTo(ItemType otherItem) const
{
    if(value > otherItem.value)
        return GREATER;
    else if(value < otherItem.value)
        return LESS;

    return EQUAL;
}

void ItemType::Print(ofstream& outFile) const
{
    outFile << value << endl;
}

#endif // ITEMTYPE_CPP
