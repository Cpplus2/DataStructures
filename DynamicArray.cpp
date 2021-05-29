#ifndef DYNAMICARRAY_CPP
#define DYNAMICARRAY_CPP

#include "DynamicArray.h"

DynamicArray::DynamicArray()
{
    dimension = false;
    data = NULL;
    sz = 0;
}

DynamicArray::DynamicArray(int newSize)
{
    dimension = false;
    data = new double[newSize];
    sz = newSize;
}

DynamicArray::DynamicArray(int newRow, int newColumn)
{
    dimension = true;
    data = new double[newRow*newColumn];
    sz = newRow * newColumn;
    row = newRow;
    column = newColumn;
}

DynamicArray::~DynamicArray()
{
    dimension = false;
    delete [] data;
    sz = row = column = 0;
}

double DynamicArray::getValue(int index)
{
    return data[index];
}

double DynamicArray::getValue(int newRow, int newColumn)
{
    if(dimension)
        return data[newRow * column + newColumn];

    return 0;
}

void DynamicArray::Insert(int index, double value)
{
    double *temp;

    temp = new double[index+1];
    for(int count = 0; count < sz; count++)
        temp[count] = data[count];

    data = new double[index+1];

    for(int count = 0; count< sz; count++)
        data[count] = temp[count];

    delete[] temp;
    data[index] = value;
    sz = index+1;
}

void DynamicArray::Insert(int newRow, int newColumn, double value)
{
    row = newRow;
    double * temp = new double[row * column + newColumn];

    for(int count = 0; count < sz; count++)
        temp[count] = data[count];

    temp[sz++] = value;

    data = new double[sz];

    for(int count = 0; count < sz; count++)
        data[count] = temp[count];

    delete [] temp;
}

void DynamicArray::setRow(int newRow)
{
    if(!dimension)
        dimension = true;

    row = newRow;
}

void DynamicArray::setColumn(int newColumn)
{
    if(!dimension)
        dimension = true;

    column = newColumn;
}

int DynamicArray::getColumn()
{
    return column;
}

int DynamicArray::getRow()
{
    return row;
}


void DynamicArray::setDimension(bool newDimension)
{
    if(!dimension && newDimension)
        row = 1;

    dimension = newDimension;
}

bool DynamicArray::getDimension()
{
    return dimension;
}

double DynamicArray::getProduct()
{
    int product = 1;
    for(int count = 0; count < sz; count++)
        product *= data[count];

    return product;
}

double DynamicArray::getSum()
{
    int sum = 0;

    for(int count = 0; count < sz; count++)
        sum += data[count];

    return sum;
}

int DynamicArray::getSize()
{
    return sz;
}

#endif // DYNAMICARRAY_CPP
