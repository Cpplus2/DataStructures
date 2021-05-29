#ifndef TREETYPE_CPP
#define TREETYPE_CPP

#include "TreeType.h"

template<class ItemType>
TreeType<ItemType>::TreeType()
{
    root=NULL;
}

template<class ItemType>
void Destroy(TreeNode<ItemType>*& tree)
{
    if(tree!=NULL)
    {
        Destroy(tree->left);
        Destroy(tree->right);

        delete tree;
    }
}

template<class ItemType>
TreeType<ItemType>::~TreeType()
{
    Destroy(root);
}

template<class ItemType>
bool TreeType<ItemType>::IsEmpty() const
{
    return (root==NULL);
}

template<class ItemType>
bool TreeType<ItemType>::IsFull() const
{
    TreeNode<ItemType>* location;

    try{
        location = new TreeNode<ItemType>;
        delete location;
        return false;
    }
    catch(bad_alloc exception)
    {
        return true;
    }
}

template<class ItemType>
void Insert(TreeNode<ItemType>*& tree, ItemType item)   //Tree represents root of the tree
{
    if(tree==NULL)
    {
        tree = new TreeNode<ItemType>;
        tree->right = NULL;
        tree->left = NULL;
        tree->info = item;
    }
    else if(item < tree->info)
        Insert(tree->left, item);
    else
        Insert(tree->right, item);
}

template<class ItemType>
void TreeType<ItemType>::PutItem(ItemType item)
{
    Insert(root, item);
}

template<class ItemType>
int CountNodes(TreeNode<ItemType> *tree)
{
    if(tree == NULL)
        return 0;
    else
        return (CountNodes(tree->left) + CountNodes(tree->right) + 1);
}

template<class ItemType>
int TreeType<ItemType>::GetLength() const
{
    return CountNodes(root);
}

template<class ItemType>
void Retrieve(TreeNode<ItemType> * tree, ItemType& item, bool& found)
{
    if(tree == NULL)
        found = false;
    else if(item < tree->info)
        Retrieve(tree->left, item, found);
    else if(item > tree->info)
        Retrieve(tree->right, item, found);
    else
    {
        item = tree->info;
        found = true;
    }
}

template<class ItemType>
ItemType TreeType<ItemType>::GetItem(ItemType item, bool& found)
{
    Retrieve(root, item, found);
    return item;
}

template<class ItemType>
void PrintTree(TreeNode<ItemType>* tree, ofstream* outFile)
{
    if(tree != NULL)
    {
        PrintTree(tree->left, outFile);
        outFile << tree->info << " ";
        PrintTree(tree->right, outFile);
    }
}

template<class ItemType>
void TreeType<ItemType>::Print(ofstream& outFile) const
{
    PrintTree(root, outFile);
}

template<class ItemType>
void DeleteNode(TreeNode<ItemType>*& tree)
{
    ItemType data;
    TreeNode<ItemType> tempPtr;

    tempPtr = tree;
    if(tree->left == NULL)
    {
        tree = tree->right;
        delete tempPtr;
    }
    else if(tree->right == NULL)
    {
        tree = tree->left;
        delete tempPtr;
    }
    else
    {
        GetPredecessor(tree->left, data);
        tree->info = data;
        Delete(tree->left, data);
    }
}

template<class ItemType>
void GetPredecessor(TreeNode<ItemType>* tree, ItemType& data)
{
    while(tree->right != NULL)
        tree = tree->right;

    data = tree->info;
}

#endif // TREETYPE_H
