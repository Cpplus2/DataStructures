#ifndef ITEMTYPE_H
#define ITEMTYPE_H

#include <fstream>
#include <iostream>

using namespace std;

enum RelationType{LESS, EQUAL, GREATER};

class ItemType
{
    public:
        int value;

    public:
        ItemType();
        int getValue();
        RelationType ComparedTo(ItemType) const;
        void Initialize(int);
        void Print(ofstream&) const;
};

#endif // ITEMTYPE_H

