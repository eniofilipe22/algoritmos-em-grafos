#ifndef SIMPLE_GRAPH_MATRIX_H
#define SIMPLE_GRAPH_MATRIX_H
#include "AdjacencyMatrix.h"
#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class SimpleGraphMatrix : public AdjacencyMatrix
{
private:
    void allocMatrix(unsigned numVertices);
    void putNewEdge(CoupleVertice newEdge);

public:
    bool isNeighbor(unsigned v1, unsigned v2) const;
    void printMatrix() const;
    vector<unsigned> traverseAllNeighbors(unsigned vertice) const;
    // void readFromFile(string fileName);
};

void SimpleGraphMatrix::allocMatrix(unsigned numVertices)
{
    matrix.resize(numVertices);

    for (int i = 0; i < numVertices; i++)
    {
        matrix[i].resize(i);
    }
};

void SimpleGraphMatrix::putNewEdge(CoupleVertice newEdge)
{
    if (!isNeighbor(newEdge.vertice1, newEdge.vertice2))
    {
        if (newEdge.vertice1 > newEdge.vertice2)
        {
            matrix[newEdge.vertice1][newEdge.vertice2] = newEdge.weight;
            // cout << "edge: v1 -> " << newEdge.vertice1 << " v2 -> " << newEdge.vertice2 << endl;
        }
        if (newEdge.vertice2 > newEdge.vertice1)
        {
            matrix[newEdge.vertice2][newEdge.vertice1] = newEdge.weight;
            // cout << "edge: v1 -> " << newEdge.vertice2 << " v2 -> " << newEdge.vertice1 << endl;
        }
    }
};

bool SimpleGraphMatrix::isNeighbor(unsigned v1, unsigned v2) const
{
    if (v1 > v2)
    {
        return matrix[v1][v2] > 0;
    }
    if (v2 > v1)
    {
        return matrix[v2][v1] > 0;
    }
    return false;
};

void SimpleGraphMatrix::printMatrix() const
{
    for (int numLine = 0; numLine < getNumVertices(); numLine++)
    {
        cout << "linha " << numLine << " : ";
        int stopped = 0;
        for (int numCollum = 0; numCollum < matrix[numLine].size(); numCollum++)
        {
            stopped = numCollum + 1;
            cout << matrix[numLine][numCollum] << " ";
        }
        for (int numCollum = stopped; numCollum < getNumVertices(); numCollum++)
        {
            if (numLine == numCollum)
            {
                cout << 0 << " ";
            }
            else
            {
                cout << matrix[numCollum][numLine] << " ";
            }
        }
        cout << endl;
    }
};

vector<unsigned> SimpleGraphMatrix::traverseAllNeighbors(unsigned vertice) const
{
    vector<unsigned> allNeighbors;
    for (unsigned lineVerification = 0; lineVerification < vertice; lineVerification++)
    {
        if (matrix[vertice][lineVerification] > 0)
        {
            allNeighbors.push_back(lineVerification);
        }
    }
    for (unsigned collumnVerification = vertice + 1; collumnVerification < getNumVertices(); collumnVerification++)
    {
        if (matrix[collumnVerification][vertice] > 0)
        {
            allNeighbors.push_back(collumnVerification);
        }
    }
    return allNeighbors;
};

#endif