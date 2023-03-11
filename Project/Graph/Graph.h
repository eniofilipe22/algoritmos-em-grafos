#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>

using namespace std;

class Weight
{
public:
    unsigned min;
    unsigned max;
};

class CoupleVertice
{
public:
    unsigned vertice1;
    unsigned vertice2;
    unsigned weight;
};

class Graph
{
private:
    virtual CoupleVertice sortCouple(unsigned numVertices, Weight weight) = 0;
    virtual void putNewEdge(CoupleVertice newEdge) = 0;

public:
    virtual void createRadomGraph(unsigned numVertices, unsigned numEdges, Weight weight) = 0;
    virtual bool isNeighbor(unsigned v1, unsigned v2) const = 0;
    virtual void readFromFile(string fileName) = 0;
    // virtual void traverseAllNeighbors() const = 0;
    int randomInteger(int min, int max);
};

int Graph::randomInteger(int min, int max)
{
    return min + (rand() % (max));
};

#endif