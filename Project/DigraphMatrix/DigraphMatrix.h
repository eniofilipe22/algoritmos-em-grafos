#ifndef DIGRAPH_MATRIX_H
#define DIGRAPH_MATRIX_H
#include "../AdjacencyMatrix/AdjacencyMatrix.h"
#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class DigraphMatrix : public AdjacencyMatrix
{
private:
    void allocMatrix(unsigned numVertices);
    void putNewEdge(CoupleVertice newEdge);

public:
    bool isNeighbor(unsigned v1, unsigned v2) const;
    void printMatrix() const;
};

void DigraphMatrix::allocMatrix(unsigned numVertices)
{
    matrix.resize(numVertices);

    for (int i = 0; i < numVertices; i++)
    {
        matrix[i].resize(numVertices);
    }
};

void DigraphMatrix::putNewEdge(CoupleVertice newEdge)
{
    if (!isNeighbor(newEdge.vertice1, newEdge.vertice2))
    {
        matrix[newEdge.vertice1][newEdge.vertice2] = newEdge.weight;
        cout << "edge: v1 -> " << newEdge.vertice1 << " v2 -> " << newEdge.vertice2 << endl;
    }
};

bool DigraphMatrix::isNeighbor(unsigned v1, unsigned v2) const
{
    return matrix[v1][v2] > 0;
};

void DigraphMatrix::printMatrix() const
{
    for (int numVertices = 0; numVertices < matrix.size(); numVertices++)
    {
        cout << "linha " << numVertices << " : ";
        for (int numNeighbor = 0; numNeighbor < matrix[numVertices].size(); numNeighbor++)
        {
            cout << matrix[numVertices][numNeighbor] << " ";
        }
        cout << endl;
    }
};

#endif