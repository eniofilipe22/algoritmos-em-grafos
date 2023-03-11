#include "SimpleGraphMatrix/SimpleGraphMatrix.h"
#include "DigraphMatrix/DigraphMatrix.h"
#include "SimpleGraphList/SimpleGraphList.h"
#include "DigraphList/DigraphList.h"
#include <vector>
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{

    Weight defaultWeight;
    defaultWeight.max = 1;
    defaultWeight.min = 1;

    cout << "Grafo simples: " << endl;

    SimpleGraphList simpleAdjacencyList;
    simpleAdjacencyList.readFromFile("grafoSimples.txt");
    simpleAdjacencyList.printMatrix();

    cout << endl
         << "Digrafo: " << endl;

    DigraphList digrapghAdjacencyList;
    digrapghAdjacencyList.readFromFile("digrafo.txt");
    digrapghAdjacencyList.printMatrix();

    // cout << "Grafo simples: " << endl;

    // SimpleGraphMatrix simpleAdjacencyMatrix;
    // simpleAdjacencyMatrix.readFromFile("grafoSimples.txt");
    // simpleAdjacencyMatrix.printMatrix();

    // cout << endl
    //      << "Digrafo: " << endl;

    // DigraphMatrix digrapghAdjacencyMatrix;
    // digrapghAdjacencyMatrix.readFromFile("digrafo.txt");
    // digrapghAdjacencyMatrix.printMatrix();

    return 0;
}
