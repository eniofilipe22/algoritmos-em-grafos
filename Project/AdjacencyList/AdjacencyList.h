#ifndef ADJACENCY_LIST_H
#define ADJACENCY_LIST_H
#include "../Graph/Graph.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
using namespace std;

class AdjacencyList : public Graph
{
protected:
    vector<vector<CoupleVertice>> matrix;

    void allocMatrix(unsigned numVertices);
    virtual void putNewEdge(CoupleVertice newEdge) = 0;

    CoupleVertice sortCouple(unsigned numVertices, Weight weight);

public:
    void createRadomGraph(unsigned numVertices, unsigned numEdges, Weight weight);
    void readFromFile(string fileName);
    void printMatrix() const;
};

CoupleVertice AdjacencyList::sortCouple(unsigned numVertices, Weight weight)
{
    CoupleVertice newCouple;

    newCouple.vertice1 = randomInteger(0, numVertices - 1);
    newCouple.vertice2 = randomInteger(0, numVertices - 1);
    newCouple.weight = randomInteger(weight.min, weight.max);

    return newCouple;
};

void AdjacencyList::createRadomGraph(unsigned numVertices, unsigned numEdges, Weight weight)
{
    allocMatrix(numVertices);
    for (int eachEdge = 0; eachEdge < numEdges; eachEdge++)
    {
        CoupleVertice possibleEdge = sortCouple(numVertices, weight);
        putNewEdge(possibleEdge);
    }
};

void AdjacencyList::readFromFile(string fileName)
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

void AdjacencyList::allocMatrix(unsigned numVertices)
{
    matrix.resize(numVertices);
};

void AdjacencyList::printMatrix() const
{
    for (int numLine = 0; numLine < matrix.size(); numLine++)
    {
        cout << "linha " << numLine << " : ";

        for (CoupleVertice edge : matrix[numLine])
        {
            cout << edge.vertice1 << " -> " << edge.vertice2 << ", Peso: " << edge.weight << " || ";
        }
        cout << endl;
    }
};
#endif