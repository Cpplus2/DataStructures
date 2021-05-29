#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <iostream>

using namespace std;

class DynamicArray
{
    private:
        double * data;
        int sz;
        int row;
        int column;
        bool dimension;

    public:
        DynamicArray();
        DynamicArray(int);
        DynamicArray(int, int);
        ~DynamicArray();
        void Insert(int, double);
        void Insert(int, int, double);
        double getValue(int);
        double getValue(int, int);
        double getProduct();
        double getSum();
        int getSize();
        void setRow(int);
        void setColumn(int);
        int getRow();
        int getColumn();
        bool getDimension();
        void setDimension(bool);
};


#endif // DYNAMICARRAY_H
