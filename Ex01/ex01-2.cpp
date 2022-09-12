#include <stdio.h>
#include <stdlib.h>
#include "time.h"
#define AROWS 4
#define ACOLS 4
#define BROWS 4
#define BCOLS 4
#define CROWS 4
#define CCOLS 4

int get_data(int (*p)[ACOLS], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            p[i][j] = rand() % (n * n);
    return 1;
}

void show_data(int (*p)[ACOLS], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%3d ", p[i][j]);
        printf("\n");
    }
    printf("\n");
}

void multiply(int matrixA[][ACOLS], int matrixB[][BCOLS], int matrixC[][CCOLS])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
            matrixC[i][j] = matrixA[i][j] * matrixB[i][j];
    }
}

int main()
{
    int matrixA[AROWS][ACOLS];
    int matrixB[BROWS][BCOLS];
    int matrixC[CROWS][CCOLS];

    srand(time(NULL));
    get_data(matrixA, AROWS);
    show_data(matrixA, AROWS);
    get_data(matrixB, BROWS);
    show_data(matrixB, BROWS);

    multiply(matrixA, matrixB, matrixC);
    show_data(matrixC, AROWS);
    system("pause");
    return 0;
}