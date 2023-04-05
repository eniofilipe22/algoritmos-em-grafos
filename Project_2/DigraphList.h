#ifndef DIGRAPH_LIST_H
#define DIGRAPH_LIST_H
#include "AdjacencyList.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <queue>
using namespace std;

int MAX = INT32_MAX;

struct BellmanFordInfo
{
    vector<int> distance;
    vector<int> pi;
    double elapsed_time;
};

class DigraphList : public AdjacencyList
{
private:
    BellmanFordInfo bellmanFordInfo;
    void putNewEdge(CoupleVertice newEdge);

public:
    bool isNeighbor(unsigned v1, unsigned v2) const;
    vector<unsigned> traverseAllNeighbors(unsigned vertice) const;
    bool bellmanFord(unsigned initialVertice, bool printInfo, bool printTimeExecution);
    void initializeUniqueSource(unsigned initialVertice);
    void stretching(CoupleVertice coupleVertice);
    BellmanFordInfo getBellmanFordInfo();
    void printDistance();
    void printDistanceHeader();
    void printPi();
};

BellmanFordInfo DigraphList::getBellmanFordInfo()
{
    return this->bellmanFordInfo;
}

void DigraphList::putNewEdge(CoupleVertice newEdge)
{
    if (!isNeighbor(newEdge.vertice1, newEdge.vertice2))
    {
        matrix[newEdge.vertice1].push_back(newEdge);
        // cout << "edge: v1 -> " << newEdge.vertice1 << " v2 -> " << newEdge.vertice2 << endl;
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

vector<unsigned> DigraphList::traverseAllNeighbors(unsigned vertice) const
{
    vector<unsigned> allNeighbors;
    for (CoupleVertice neighbor : matrix[vertice])
    {
        allNeighbors.push_back(neighbor.vertice2);
    }
    return allNeighbors;
};

bool DigraphList::bellmanFord(unsigned initialVertice, bool printInfo, bool printTimeExecution)
{
    chrono::time_point<chrono::system_clock> start, end;
    start = chrono::system_clock::now();
    // inicialização
    initializeUniqueSource(initialVertice);

    // relaxamento
    if (printInfo)
    {
        this->printDistanceHeader();
        this->printDistance();
    }
    for (int i = 1; i < this->getNumVertices(); i++)
    {
        for (int j = 0; j < this->getNumVertices(); j++)
        {
            for (CoupleVertice neighbor : matrix[j])
            {
                this->stretching(neighbor);
            }
        }
        if (printInfo)
        {
            this->printDistance();
        }
    }
    if (printInfo)
    {
        cout << endl
             << "Pi" << endl;
        this->printDistanceHeader();
        this->printPi();
    }
    // testando ciclo
    end = chrono::system_clock::now();
    chrono::duration<double> elapsed_seconds = end - start;
    bellmanFordInfo.elapsed_time = elapsed_seconds.count();

    if (printTimeExecution)
    {
        cout << endl
             << "Algorithm execution time: " << elapsed_seconds.count() << "s" << endl;
    }

    for (int i = 0; i < this->getNumVertices(); i++)
    {
        for (CoupleVertice neighbor : matrix[i])
        {
            if (this->bellmanFordInfo.distance[neighbor.vertice2] > this->bellmanFordInfo.distance[neighbor.vertice1] + neighbor.weight)
            {
                return false;
            }
        }
    }

    return true;
}

void DigraphList::initializeUniqueSource(unsigned initialVertice)
{
    this->bellmanFordInfo.distance.resize(this->getNumVertices(), MAX);
    this->bellmanFordInfo.pi.resize(this->getNumVertices(), -1);
    this->bellmanFordInfo.distance[initialVertice] = 0;
}

void DigraphList::stretching(CoupleVertice coupleVertice)
{
    if (!(this->bellmanFordInfo.distance[coupleVertice.vertice1] == MAX))
    {
        if (this->bellmanFordInfo.distance[coupleVertice.vertice2] > this->bellmanFordInfo.distance[coupleVertice.vertice1] + coupleVertice.weight)
        {
            this->bellmanFordInfo.distance[coupleVertice.vertice2] = this->bellmanFordInfo.distance[coupleVertice.vertice1] + coupleVertice.weight;
            this->bellmanFordInfo.pi[coupleVertice.vertice2] = coupleVertice.vertice1;
        }
    }
};

void DigraphList::printDistanceHeader()
{
    for (int i = 0; i < this->bellmanFordInfo.distance.size(); i++)
    {
        cout << i << "\t|"
             << " ";
    }
    cout << endl;
}

void DigraphList::printDistance()
{
    for (int distance : this->bellmanFordInfo.distance)
    {
        if (distance == MAX)
        {
            cout << "inf \t|"
                 << " ";
        }
        else
        {
            cout << distance << "\t|"
                 << " ";
        }
    }
    cout << endl;
}

void DigraphList::printPi()
{
    for (int pi : this->bellmanFordInfo.pi)
    {
        if (pi == -1)
        {
            cout << "ini \t|"
                 << " ";
        }
        else
        {
            cout << pi << "\t|"
                 << " ";
        }
    }
    cout << endl;

    cout << "Caminhos de cada vertice ate o inicial: " << endl;
    for (int i = 0; i < this->getNumVertices(); i++)
    {
        int aux = i;
        cout << i << ": ";
        while (aux != -1)
        {
            if (bellmanFordInfo.pi[aux] != -1)
            {
                cout << "" << bellmanFordInfo.pi[aux] << " -> ";
            }
            aux = bellmanFordInfo.pi[aux];
        }
        cout << "ini" << endl;
    }
}

#endif