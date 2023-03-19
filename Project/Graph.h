#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <chrono>

using namespace std;

struct BFS_info
{
    double elapsed_time;
    int num_vertices_reached;
};

struct DFS_info
{
    double elapsed_time;
    int num_vertices_reached;
};

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
    DFS_info dfsInfo;
    BFS_info bfsInfo;

public:
    virtual void createRadomGraph(unsigned numVertices, unsigned numEdges, Weight weight) = 0;
    virtual bool isNeighbor(unsigned v1, unsigned v2) const = 0;
    virtual void readFromFile(string fileName) = 0;
    virtual vector<unsigned> traverseAllNeighbors(unsigned vertice) const = 0;
    virtual int getNumVertices() const = 0;
    int randomInteger(int min, int max);
    void BFS(unsigned vertice);
    void DFS(unsigned vertice);

    DFS_info getDFSInfo();
    BFS_info getBFSInfo();
    void setReachedVerticesBFS(int numVertices);
    void setReachedVerticesDFS(int numVertices);
    void setElapsedTimeDFS(double elapsedTime);
    void setElapsedTimeBFS(double elapsedTime);
};

DFS_info Graph::getDFSInfo()
{
    return dfsInfo;
};

BFS_info Graph::getBFSInfo()
{
    return bfsInfo;
};

void Graph::setReachedVerticesBFS(int numVertices)
{
    bfsInfo.num_vertices_reached = numVertices;
};

void Graph::setReachedVerticesDFS(int numVertices)
{
    dfsInfo.num_vertices_reached = numVertices;
};

void Graph::setElapsedTimeBFS(double elapsedTime)
{
    bfsInfo.elapsed_time = elapsedTime;
};

void Graph::setElapsedTimeDFS(double elapsedTime)
{
    dfsInfo.elapsed_time = elapsedTime;
};

int Graph::randomInteger(int min, int max)
{
    return min + (rand() % (max));
};

void Graph::BFS(unsigned initialVertice)
{
    chrono::time_point<chrono::system_clock> start, end;
    start = chrono::system_clock::now();

    int countReachedVertices = 1;
    vector<bool> discovered(getNumVertices(), false);
    discovered[initialVertice] = true;
    vector<vector<unsigned>> layers;
    layers.resize(1);
    int currentLayer = 0;
    layers[currentLayer].push_back(initialVertice);
    while (layers[currentLayer].size() > 0)
    {
        layers.resize(layers.size() + 1);
        for (unsigned vertice : layers[currentLayer])
        {
            vector<unsigned> neighbors = traverseAllNeighbors(vertice);
            for (unsigned neighbor : neighbors)
            {
                if (!discovered[neighbor])
                {
                    countReachedVertices++;
                    discovered[neighbor] = true;
                    layers[currentLayer + 1].push_back(neighbor);
                }
            }
        }
        currentLayer++;
    }

    end = chrono::system_clock::now();
    chrono::duration<double> elapsed_seconds = end - start;
    setElapsedTimeBFS(elapsed_seconds.count());
    setReachedVerticesBFS(countReachedVertices);

    cout << "BFS" << endl;
    for (vector<unsigned> layer : layers)
    {
        for (unsigned v : layer)
        {
            cout << v << " ";
        }
        cout << endl;
    }
};

void Graph::DFS(unsigned initialVertice)
{

    cout << "DFS" << endl;
    chrono::time_point<chrono::system_clock> start, end;
    start = chrono::system_clock::now();

    int countReachedVertices = 0;

    vector<bool> explored(getNumVertices(), false);
    vector<unsigned> stack;
    stack.push_back(initialVertice);
    while (stack.size() > 0)
    {
        unsigned toExplorer = stack.back();
        stack.pop_back();
        if (!explored[toExplorer])
        {
            cout << toExplorer << endl;
            explored[toExplorer] = true;
            countReachedVertices++;
            vector<unsigned> neighbors = traverseAllNeighbors(toExplorer);

            for (int it = neighbors.size() - 1; it >= 0; it--)
            {
                stack.push_back(neighbors[it]);
            }
        }
    }
    end = chrono::system_clock::now();
    chrono::duration<double> elapsed_seconds = end - start;
    setElapsedTimeDFS(elapsed_seconds.count());
    setReachedVerticesDFS(countReachedVertices);
}

#endif