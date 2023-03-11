#ifndef DIGRAPH_LIST_H
#define DIGRAPH_LIST_H
#include "../AdjacencyList/AdjacencyList.h"
#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class DigraphList : public AdjacencyList
{
private:
    void putNewEdge(CoupleVertice newEdge);

public:
    bool isNeighbor(unsigned v1, unsigned v2) const;
};

void DigraphList::putNewEdge(CoupleVertice newEdge)
{
    if (!isNeighbor(newEdge.vertice1, newEdge.vertice2))
    {
        matrix[newEdge.vertice1].push_back(newEdge);
        cout << "edge: v1 -> " << newEdge.vertice1 << " v2 -> " << newEdge.vertice2 << endl;
    }
};

bool DigraphList::isNeighbor(unsigned v1, unsigned v2) const
{
    bool isNeighbor = false;
    for (CoupleVertice edge : matrix[v1])
    {
        if (edge.vertice2 == v2)
        {
            isNeighbor = true;
            break;
        }
    }
    return isNeighbor;
};

#endif