
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

    // DigraphList digrapghAdjacencyList;
    // digrapghAdjacencyList.readFromFile("digrafoBF.txt", 12, 15, false);
    // digrapghAdjacencyList.printMatrix();

    // cout << endl
    //      << "BellmanFord" << endl;

    // digrapghAdjacencyList.bellmanFord(0, true, true);
    // digrapghAdjacencyList.bellmanFord(3, false, true);

    randomVertices();

    return 0;
}

void randomVertices()
{
    Weight defaultWeight;
    defaultWeight.max = -5;
    defaultWeight.min = 50;

    fstream fileListOut;
    fileListOut.open("digraphList.csv", ios::out);

    fileListOut << "num_vertices,num_arestas,execution_time,\n";
    for (int n = 1; n <= 1000; n++)
    {

        DigraphList digraphList;
        double maxEdges = ((n * (n - 1) / 2));
        int numEdges = round(maxEdges * 0.2);

        digraphList.createRadomGraph(n, numEdges, defaultWeight);
        digraphList.bellmanFord(0, false, false);

        fileListOut
            << n << ","
            << numEdges << ","
            << digraphList.getBellmanFordInfo().elapsed_time << ",\n";

        cout << "Random Vertice - lista - " << n << "/1000" << endl;
    };

    cout << " FIM :)" << endl;
}