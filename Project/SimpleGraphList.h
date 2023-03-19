#ifndef SIMPLE_GRAPH_LIST_H
#define SIMPLE_GRAPH_LIST_H
#include "AdjacencyList.h"
#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class SimpleGraphList : public AdjacencyList
{
private:
    void putNewEdge(CoupleVertice newEdge);

public:
    bool isNeighbor(unsigned v1, unsigned v2) const;
    vector<unsigned> traverseAllNeighbors(unsigned vertice) const;
};

void SimpleGraphList::putNewEdge(CoupleVertice newEdge)
{
    if (!isNeighbor(newEdge.vertice1, newEdge.vertice2))
    {
        matrix[newEdge.vertice1].push_back(newEdge);
        // cout << "edge: v1 -> " << newEdge.vertice1 << " v2 -> " << newEdge.vertice2 << endl;
        CoupleVertice inverseEdge;
        inverseEdge.weight = newEdge.weight;
        inverseEdge.vertice1 = newEdge.vertice2;
        inverseEdge.vertice2 = newEdge.vertice1;
        matrix[inverseEdge.vertice1].push_back(inverseEdge);
    }
};

bool SimpleGraphList::isNeighbor(unsigned v1, unsigned v2) const
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
    if (!isNeighbor)
    {
        for (CoupleVertice edge : matrix[v2])
        {
            if (edge.vertice2 == v1)
            {
                isNeighbor = true;
                break;
            }
        }
    }
    return isNeighbor;
};

vector<unsigned> SimpleGraphList::traverseAllNeighbors(unsigned vertice) const
{
    vector<unsigned> allNeighbors;
    for (CoupleVertice neighbor : matrix[vertice])
    {
        allNeighbors.push_back(neighbor.vertice2);
    }
    return allNeighbors;
};

#endif