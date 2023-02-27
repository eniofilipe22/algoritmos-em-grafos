#include <vector>
#include <iostream>
#include <cstdlib>

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
    CoupleVertice sortCouple(unsigned numVertices, Weight weight);
    void putNewEdge(CoupleVertice newEdge);

public:
    void createRadomGraph(unsigned numVertices, unsigned numEdges, Weight weight);
    bool isNeighbor(unsigned v1, unsigned v2) const;
    void traverseAllNeighbors() const;
    int randomInteger(int min, int max)
    {
        return min + (rand() % (max));
    }
};

class AdjacencyMatrix : public Graph
{
private:
    vector<vector<int>> matrix;

    void allocMatrix(unsigned numVertices)
    {
        matrix.resize(numVertices);
        for (int i = 0; i < numVertices; i++)
        {
            matrix[i].resize(i);
        }
    }

    CoupleVertice sortCouple(unsigned numVertices, Weight weight)
    {
        CoupleVertice newCouple;

        newCouple.vertice1 = randomInteger(0, numVertices - 1);
        newCouple.vertice2 = randomInteger(0, numVertices - 1);
        newCouple.weight = randomInteger(weight.min, weight.max);

        return newCouple;
    };

    void putNewEdge(CoupleVertice newEdge)
    {
        if (!isNeighbor(newEdge.vertice1, newEdge.vertice2))
        {
            if (newEdge.vertice1 > newEdge.vertice2)
            {
                matrix[newEdge.vertice1][newEdge.vertice2] = newEdge.weight;
                cout << "edge: v1 -> " << newEdge.vertice1 << " v2 -> " << newEdge.vertice2 << endl;
            }
            if (newEdge.vertice2 > newEdge.vertice1)
            {
                matrix[newEdge.vertice2][newEdge.vertice1] = newEdge.weight;
                cout << "edge: v1 -> " << newEdge.vertice2 << " v2 -> " << newEdge.vertice1 << endl;
            }
        }
    };

public:
    bool isNeighbor(unsigned v1, unsigned v2) const
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

    void createRadomGraph(unsigned numVertices, unsigned numEdges, Weight weight)
    {
        allocMatrix(numVertices);
        for (int eachEdge = 0; eachEdge < numEdges; eachEdge++)
        {
            CoupleVertice possibleEdge = sortCouple(numVertices, weight);
            putNewEdge(possibleEdge);
        }
    }

    void printMatrix() const
    {
        for (int numVertices = 0; numVertices < matrix.size(); numVertices++)
        {
            for (int numNeighbor = 0; numNeighbor < matrix[numVertices].size(); numNeighbor++)
            {
                cout << matrix[numVertices][numNeighbor] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{

    Weight defaultWeight;
    defaultWeight.max = 1;
    defaultWeight.min = 1;

    AdjacencyMatrix adjacencyMatrix;

    adjacencyMatrix.createRadomGraph(10, 7, defaultWeight);
    adjacencyMatrix.printMatrix();

    cout << "ike to executando" << endl;
    return 0;
}