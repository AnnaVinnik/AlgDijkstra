#define MAXPATH 20
#include <stdlib.h>
#include <stdio.h>

int getrand(int min, int max)
{
    return (double)rand() / (RAND_MAX + 1.0) * (max - min) + min;
}

void MatrixFilling(int adjacencyMatrix[MAXPATH][MAXPATH])
{
int i, j;

    for (j = 0; j < MAXPATH; j++){
        for (i = j; i < MAXPATH; i++){
            adjacencyMatrix[j][i] = getrand(0, 10);
        }
    }

    for (j = 0; j < MAXPATH; j++){
        for (i = j; i < MAXPATH; i++){
            adjacencyMatrix[i][j] = adjacencyMatrix[j][i];
        }
    }


    for (i = 0; i < MAXPATH; i++){
        adjacencyMatrix[i][i] = 0;
    }


}

void algDijkstra(int shortestPaths[MAXPATH], int adjacencyMatrix[MAXPATH][MAXPATH], int path[MAXPATH][MAXPATH])
{
int i, j, k;
    for ( i = 0; i < MAXPATH; i++)
        shortestPaths[i] = 100;

    shortestPaths[0] = 0;
    for (j = 0; j < MAXPATH; j++){
        for (i = 0; i < MAXPATH; i++){
            if (adjacencyMatrix[j][i] > 0){
                if (shortestPaths[i] > shortestPaths[j] + adjacencyMatrix[j][i]){
                    shortestPaths[i] = shortestPaths[j] + adjacencyMatrix[j][i];
                    path[i][k] = j;
                    k++;
                }
            }
    k = 1;
        }
    }
}

void printMatrix(int adjacencyMatrix[MAXPATH][MAXPATH])
{
int i, j;
    for (j = 0; j < MAXPATH; j++){
        for (i = 0; i < MAXPATH; i++){
            printf ("%2d ", adjacencyMatrix[j][i]);
        }
        printf("\n");
    }
}

void printPath(int shortestPaths[MAXPATH], int path[MAXPATH][MAXPATH])
{
int i, j;
    for (j = 1; j < MAXPATH; j++){
        printf ("%2d: len ", j);
        printf ("%2d ", shortestPaths[j]);
        printf("path: 0,");
        for (i = 1; path[j][i] != 0; i++){
            printf(" %2d,", path[j][i]);
        }
        printf(" %2d \n", j);
    }
}
