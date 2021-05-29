#ifndef TREETYPE_H
#define TREETYPE_H

#include <iostream>
#include <fstream>
#include <new>

using namespace std;

template<class ItemType>
struct TreeNode
{
    ItemType info;
    TreeNode * left;
    TreeNode * right;
};

template<class ItemType>
class TreeType
{
    public:
        TreeType();
        ~TreeType();
        bool IsEmpty() const;
        bool IsFull() const;
        int GetLength() const;
        ItemType GetItem(ItemType item, bool& found);
        void PutItem(ItemType);
        void DeleteItem(ItemType);
        void Print(ofstream&) const;

    private:
        TreeNode<ItemType> * root;
};

#include "TreeType.cpp"

#endif // TREETYPE_H
