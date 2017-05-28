#include <stdio.h>
#define MAXPATH 5

int main()
{
int adjacencyMatrix[MAXPATH][MAXPATH] = {{0, 2, 5, 0, 4}, {2, 0, 3, 0, 0}, {5, 3, 0, 3, 0}, {0, 0, 3, 0, 2}, {4, 0, 0, 2, 0}};
int shortestPaths[MAXPATH] = {};
int first, i, j;
    for ( i = 0; i < MAXPATH; i++)
        shortestPaths[i] = 1000;

    //Заполнение матрицы
   /* printf("Заполнение матрицы");
    for (j = 0; j < MAXPATH; j++){
        for (i = 0; i < MAXPATH; i++){
            scanf("%d", &adjacencyMatrix[j][i]);
        }
    }*/
shortestPaths[0] = 0;
    first = adjacencyMatrix[0][0]; //Обозначаем исходную точку
    for (j = 0; j < MAXPATH; j++){
        for (i = 0; i < MAXPATH; i++){
            if (adjacencyMatrix[j][i] > 0){
                if (shortestPaths[i] > shortestPaths[j] + adjacencyMatrix[j][i]){
                    shortestPaths[i] = shortestPaths[j] + adjacencyMatrix[j][i];
                }
            }
        }
    }


    for (j = 0; j < MAXPATH; j++){
        for (i = 0; i < MAXPATH; i++){
            printf ("%d", adjacencyMatrix[j][i]);
        }
        printf("\n");
    }
    for (i = 0; i < MAXPATH + 1; i++){
        printf ("%d: ", i);
        printf ("%d\n", shortestPaths[i]);
    }

    return 0;
}
