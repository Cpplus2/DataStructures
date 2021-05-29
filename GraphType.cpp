#ifndef GRAPHTYPE_CPP
#define GRAPHTYPE_CPP

#include "GraphType.h"

template<class VertexType>
GraphType<VertexType>::GraphType()
{
    numOfVertices = 0;
    maxVertices = 50;
    vertices = new VertexType[50];
    edges = new int*[50];

    for(int count = 0; count < 50; count++)
        edges[count] = new int[50];

    marks = new bool[50];
}

template<class VertexType>
GraphType<VertexType>::GraphType(int maximum)
{
    numOfVertices = 0;
    maxVertices = maximum;
    vertices = new VertexType[50];
    edges = new int* [maximum];

    for(int count = 0; count < maximum; count++)
        edges[count] = new int[50];

    marks = new bool[50];
}

template<class VertexType>
GraphType<VertexType>::~GraphType()
{
    delete [] vertices;
    delete [] marks;
    for(int count = 0; count < maxVertices; count++)
        delete [] edges[count];

    delete [] edges;
}

const int NULL_EDGE = 0;
template<class VertexType>
void GraphType<VertexType>::AddVertex(VertexType vertex)
{
    vertices[numOfVertices] = vertex;

    for(int index = 0; index < numOfVertices; index++)
    {
        edges[numOfVertices][index] = NULL_EDGE;
        edges[index][numOfVertices] = NULL_EDGE;
    }
    numOfVertices++;
}

template<class VertexType>
int IndexIs(VertexType* vertices, VertexType vertex)
{
    int index = 0;

    while(vertex != vertices[index])
        index++;

    return index;
}

template<class VertexType>
void GraphType<VertexType>::AddEdge(VertexType fromVertex, VertexType toVertex, int weight)
{
    int row = IndexIs(vertices, fromVertex);
    int column = IndexIs(vertices, toVertex);

    edges[row][column];
}

template<class VertexType>
int GraphType<VertexType>::WeightIs(VertexType fromVertex, VertexType toVertex)
{
    int row = IndexIs(vertices, fromVertex);
    int column = IndexIs(vertices, toVertex);

    return edges[row][column];
}

template<class VertexType>
void GraphType<VertexType>::GetToVertices(VertexType vertex, Queue<VertexType>& adjVertices)
{
    int fromIndex, toIndex;

    fromIndex = IndexIs(vertices, vertex);
    for(toIndex = 0; toIndex < numOfVertices; toIndex++)
        if(edges[fromIndex][toIndex] != NULL_EDGE)
            adjVertices.Enqueue(vertices[toIndex]);
}

#endif // GRAPHTYPE_CPP

