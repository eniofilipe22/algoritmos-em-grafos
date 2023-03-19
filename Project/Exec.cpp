#include "SimpleGraphMatrix.h"
#include "DigraphMatrix.h"
#include "SimpleGraphList.h"
#include "DigraphList.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <math.h>
#include <chrono>
#include <time.h>

using namespace std;

void randomVertices();

int main()
{

    Weight defaultWeight;
    defaultWeight.max = 1;
    defaultWeight.min = 1;

    cout << "Lista" << endl;
    cout << "Grafo simples: " << endl;

    SimpleGraphList simpleAdjacencyList;
    simpleAdjacencyList.readFromFile("grafoSimples.txt");
    // simpleAdjacencyList.printMatrix();

    cout << endl;

    simpleAdjacencyList.BFS(0);
    simpleAdjacencyList.DFS(0);

    cout
        << endl
        << "Digrafo: " << endl;

    DigraphList digrapghAdjacencyList;
    digrapghAdjacencyList.readFromFile("digrafo.txt");
    // digrapghAdjacencyList.printMatrix();

    cout << endl;

    digrapghAdjacencyList.BFS(0);
    digrapghAdjacencyList.DFS(0);

    cout << "Matriz" << endl;
    cout << "Grafo simples: " << endl;

    SimpleGraphMatrix simpleAdjacencyMatrix;
    simpleAdjacencyMatrix.readFromFile("grafoSimples.txt");
    // simpleAdjacencyMatrix.printMatrix();

    simpleAdjacencyMatrix.BFS(0);
    simpleAdjacencyMatrix.DFS(0);

    cout << endl
         << "Digrafo: " << endl;

    DigraphMatrix digrapghAdjacencyMatrix;
    digrapghAdjacencyMatrix.readFromFile("digrafo.txt");
    // digrapghAdjacencyMatrix.printMatrix();

    cout << endl;

    digrapghAdjacencyMatrix.BFS(0);
    digrapghAdjacencyMatrix.DFS(0);

    // randomVertices();

    return 0;
}

void randomVertices()
{
    Weight defaultWeight;
    defaultWeight.max = 1;
    defaultWeight.min = 1;

    fstream fileListOut;
    fileListOut.open("simpleGraphListOut.csv", ios::out);

    fileListOut << "num_vertices,num_arestas,execution_BFS,reached_vertices_BFS,execution_DFS,reached_vertices_DFS,\n";
    for (int n = 1; n <= 1000; n++)
    {

        SimpleGraphList simpleAdjacencyList;
        double maxEdges = ((n * (n - 1) / 2));
        int numEdges = round(maxEdges * 0.25);

        simpleAdjacencyList.createRadomGraph(n, numEdges, defaultWeight);
        simpleAdjacencyList.BFS(0);
        simpleAdjacencyList.DFS(0);

        fileListOut << n << ","
                    << numEdges << ","
                    << simpleAdjacencyList.getBFSInfo().elapsed_time << ","
                    << simpleAdjacencyList.getBFSInfo().num_vertices_reached << ","
                    << simpleAdjacencyList.getDFSInfo().elapsed_time << ","
                    << simpleAdjacencyList.getDFSInfo().num_vertices_reached << ",\n";

        cout << "Random Vertice - lista - " << n << "/1000" << endl;
    };

    fstream fileMatrixOut;
    fileMatrixOut.open("simpleGraphMatrixOut.csv", ios::out);

    fileMatrixOut << "num_vertices,num_arestas,execution_BFS,reached_vertices_BFS,execution_DFS,reached_vertices_DFS,\n";
    for (int n = 1; n <= 1000; n++)
    {

        SimpleGraphMatrix simpleAdjacencyMatrix;
        double maxEdges = ((n * (n - 1) / 2));
        int numEdges = round(maxEdges * 0.25);

        simpleAdjacencyMatrix.createRadomGraph(n, numEdges, defaultWeight);
        simpleAdjacencyMatrix.BFS(0);
        simpleAdjacencyMatrix.DFS(0);

        fileMatrixOut << n << ","
                      << numEdges << ","
                      << simpleAdjacencyMatrix.getBFSInfo().elapsed_time << ","
                      << simpleAdjacencyMatrix.getBFSInfo().num_vertices_reached << ","
                      << simpleAdjacencyMatrix.getDFSInfo().elapsed_time << ","
                      << simpleAdjacencyMatrix.getDFSInfo().num_vertices_reached << ",\n";
        cout << "Random Vertice - matriz - " << n << "/1000" << endl;
    };

    fstream fileListRandomEdgesOut;
    fileListRandomEdgesOut.open("simpleGraphRandomEdgesListOut.csv", ios::out);

    fileListRandomEdgesOut << "num_vertices,num_arestas,execution_BFS,reached_vertices_BFS,execution_DFS,reached_vertices_DFS,\n";
    for (int n = 1; n <= 100; n++)
    {

        SimpleGraphList simpleAdjacencyList;
        double maxEdges = ((1000 * (1000 - 1) / 2));
        int numEdges = round(maxEdges * (double(n) / 100));

        simpleAdjacencyList.createRadomGraph(1000, numEdges, defaultWeight);
        simpleAdjacencyList.BFS(0);
        simpleAdjacencyList.DFS(0);

        fileListRandomEdgesOut << 1000 << ","
                               << numEdges << ","
                               << simpleAdjacencyList.getBFSInfo().elapsed_time << ","
                               << simpleAdjacencyList.getBFSInfo().num_vertices_reached << ","
                               << simpleAdjacencyList.getDFSInfo().elapsed_time << ","
                               << simpleAdjacencyList.getDFSInfo().num_vertices_reached << ",\n";

        cout << "Random Aresta - lista - " << n << "/100" << endl;
    };

    fstream fileMatrixRandomEdgesOut;
    fileMatrixRandomEdgesOut.open("simpleGraphRandomEdgesMatrixOut.csv", ios::out);

    fileMatrixRandomEdgesOut << "num_vertices,num_arestas,execution_BFS,reached_vertices_BFS,execution_DFS,reached_vertices_DFS,\n";
    for (int n = 1; n <= 100; n++)
    {

        SimpleGraphMatrix simpleAdjacencyMatrix;
        double maxEdges = ((1000 * (1000 - 1) / 2));
        int numEdges = round(maxEdges * (double(n) / 100));

        simpleAdjacencyMatrix.createRadomGraph(1000, numEdges, defaultWeight);
        simpleAdjacencyMatrix.BFS(0);
        simpleAdjacencyMatrix.DFS(0);

        fileMatrixRandomEdgesOut << 1000 << ","
                                 << numEdges << ","
                                 << simpleAdjacencyMatrix.getBFSInfo().elapsed_time << ","
                                 << simpleAdjacencyMatrix.getBFSInfo().num_vertices_reached << ","
                                 << simpleAdjacencyMatrix.getDFSInfo().elapsed_time << ","
                                 << simpleAdjacencyMatrix.getDFSInfo().num_vertices_reached << ",\n";

        cout << "Random Aresta - matriz - " << n << "/100" << endl;
    };

    cout << " FIM :)" << endl;
}