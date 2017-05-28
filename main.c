#include <stdio.h>
#include "dijkstraAlg.h"
#define MAXPATH 20

int main()
{
int adjacencyMatrix[MAXPATH][MAXPATH];
int shortestPaths[MAXPATH] = {};
int path[MAXPATH][MAXPATH] = {};


    MatrixFilling(adjacencyMatrix);

    algDijkstra(shortestPaths, adjacencyMatrix, path);

    printMatrix(adjacencyMatrix);

    printPath(shortestPaths, path);


    return 0;
}
