#ifndef HEAP_H
#define HEAP_H

template<class ItemType>
class Heap
{
    public:
        void ReheapDown(int root, int bottom);
        void ReheapUp(int root, int bottom);


    private:
        ItemType* elements;
        int numOfElements;

};
#endif // HEAP_H
