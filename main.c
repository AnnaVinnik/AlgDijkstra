#include <stdio.h>
#define MAXPATH 3

int main()
{
int adjacencyMatrix[MAXPATH][MAXPATH];
int shortestPaths[MAXPATH] = {};
int first, i, j;
    for ( i = 0; i < MAXPATH; i++)
        shortestPaths[i] = 1000;

    //Заполнение матрицы
    printf("Заполнение матрицы");
    for (j = 0; j < MAXPATH; j++){
        for (i = 0; i < MAXPATH; i++){
            scanf("%d", &adjacencyMatrix[j][i]);
        }
    }
shortestPaths[0] = 0;
    first = adjacencyMatrix[0][0]; //Обозначаем исходную точку
    for (j = 0; j < MAXPATH; j++){
printf("!");
        for (i = 0; i < MAXPATH - 1; i++){
printf(":)");
            if (adjacencyMatrix[j][i] > 0){
printf("=)");
                if (shortestPaths[i + 1] > shortestPaths[j] + adjacencyMatrix[j][i]){
                    shortestPaths[i + 1] = shortestPaths[j] + adjacencyMatrix[j][i];
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
