#include <stdio.h>
#include <stdlib.h>
#define MAXPATH 20

int getrand(int min, int max)
{
    return (double)rand() / (RAND_MAX + 1.0) * (max - min) + min;
}

int main()
{
int adjacencyMatrix[MAXPATH][MAXPATH];
int shortestPaths[MAXPATH] = {};
int first, i, j, k;
int path[MAXPATH][MAXPATH] = {};
    for ( i = 0; i < MAXPATH; i++)
        shortestPaths[i] = 100;

    //Заполнение матрицы
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


    shortestPaths[0] = 0;
    first = adjacencyMatrix[0][0]; //Обозначаем исходную точку
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

    for (j = 0; j < MAXPATH; j++){
        for (i = 0; i < MAXPATH; i++){
            printf ("%2d ", adjacencyMatrix[j][i]);
        }
        printf("\n");
    }
    for (j = 1; j < MAXPATH; j++){
        printf ("%2d: len ", j);
        printf ("%d ", shortestPaths[j]);
        printf("path: 0;");
        for (i = 1; path[j][i] != 0; i++){
            printf(" %d;", path[j][i]);
        }
        printf(" %d \n", j);
    }


    return 0;
}
