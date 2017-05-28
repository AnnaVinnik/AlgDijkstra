#ifndef DIJKSTRA
#define DIJKSTRA
#define MAXPATH 20

int getrand(int min, int max);
void MatrixFilling(int adjacencyMatrix[MAXPATH][MAXPATH]);
void algDijkstra(int shortestPaths[MAXPATH], int adjacencyMatrix[MAXPATH][MAXPATH], int path[MAXPATH][MAXPATH]);
void printMatrix(int adjacencyMatrix[MAXPATH][MAXPATH]);
void printPath(int shortestPaths[MAXPATH], int path[MAXPATH][MAXPATH]);

#endif
