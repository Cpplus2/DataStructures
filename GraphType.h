#ifndef GRAPHTYPE_H
#define GRAPHTYPE_H

#include "Queue.h"

template<class VertexType>
class GraphType
{
    public:
        GraphType();
        GraphType(int);
        ~GraphType();
        void MakeEmpty();
        bool IsEmpty() const;
        bool IsFull() const;
        void AddVertex(VertexType);
        void AddEdge(VertexType, VertexType, int);
        int WeightIs(VertexType, VertexType);
        void GetToVertices(VertexType, Queue<VertexType>&);
        void ClearMarks();
        void MarkVertex(VertexType);
        bool IsMarked(VertexType);

    private:
        int numOfVertices;
        int maxVertices;
        VertexType * vertices;
        int ** edges;
        bool* marks;
};

#include "GraphType.cpp"

#endif // GRAPHTYPE_H
