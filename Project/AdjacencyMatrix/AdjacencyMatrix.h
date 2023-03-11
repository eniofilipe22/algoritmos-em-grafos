#ifndef ADJACENCY_MATRIX_H
#define ADJACENCY_MATRIX_H
#include "../Graph/Graph.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
using namespace std;

class AdjacencyMatrix : public Graph
{
protected:
    vector<vector<int>> matrix;

    virtual void allocMatrix(unsigned numVertices) = 0;
    virtual void putNewEdge(CoupleVertice newEdge) = 0;

    CoupleVertice sortCouple(unsigned numVertices, Weight weight);

public:
    void createRadomGraph(unsigned numVertices, unsigned numEdges, Weight weight);
    void readFromFile(string fileName);
    virtual void printMatrix() const = 0;
};

CoupleVertice AdjacencyMatrix::sortCouple(unsigned numVertices, Weight weight)
{
    CoupleVertice newCouple;

    newCouple.vertice1 = randomInteger(0, numVertices - 1);
    newCouple.vertice2 = randomInteger(0, numVertices - 1);
    newCouple.weight = randomInteger(weight.min, weight.max);

    return newCouple;
};

void AdjacencyMatrix::createRadomGraph(unsigned numVertices, unsigned numEdges, Weight weight)
{
    allocMatrix(numVertices);
    for (int eachEdge = 0; eachEdge < numEdges; eachEdge++)
    {
        CoupleVertice possibleEdge = sortCouple(numVertices, weight);
        putNewEdge(possibleEdge);
    }
};

void AdjacencyMatrix::readFromFile(string fileName)
{
    fstream fileToRead;
    fileToRead.open(fileName, ios::in);
    if (!fileToRead.good())
    {
        cout << "Erro ao abrir arquivo" << endl;
    }
    else
    {
        char linha[100];
        int numVertices = 0;
        Weight defaultWeight;

        // numero de vertices
        fileToRead.getline(linha, 2, '\n');
        numVertices = atoi(linha);

        allocMatrix(numVertices);

        for (int line = 0; line < numVertices; line++)
        {
            for (int collumn = 0; collumn < numVertices; collumn++)
            {
                CoupleVertice newCouple;
                int value;
                if (collumn == numVertices - 1)
                {
                    fileToRead.getline(linha, 2, '\n');
                }
                else
                {
                    fileToRead.getline(linha, 2, ' ');
                }

                value = atoi(linha);
                if (value > 0)
                {
                    newCouple.vertice1 = line;
                    newCouple.vertice2 = collumn;
                    newCouple.weight = value;
                    putNewEdge(newCouple);
                }
            }
        }
    }
};

#endif