#include <stdio.h>
#include <stdlib.h>
#include "time.h"

#define AROWS 3
#define ACOLS 4
#define BROWS 4
#define BCOLS 5
#define CROWS 3
#define CCOLS 5
#define N 3

class Matrix
{
private:
    int rows, cols;
    static int *data;
    static int free;
    int start, finish;
    int terms;

public:
    Matrix(int rows, int cols) : rows(rows), cols(cols)
    {
        start = free;
        finish = free + rows * cols - 1;
        terms = rows * cols;

        free += terms;
    }
    ~Matrix() {}

    int get_data();
    int show_data();
    int sort_data();
    int addMatrix(Matrix &);
    // A row == B col, A col == B row  C row == B row, C col == A col
    int MultiplyMatrix(Matrix &matrixA, Matrix &matrixB);
};

int Matrix::free = 0;
int *Matrix::data = new int[100];

int Matrix::get_data()
{
    for (int i = 0; i < cols; i++)
        for (int j = 0; j < rows; j++)
        {
            data[start + i * rows + j] = rand() % (N * N);
        }
    return 1;
}

int Matrix::show_data()
{
    printf("\n");
    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
            printf("%d ", data[start + i * rows + j]);
        printf("\n");
    }
}

void mergeSort(int *data, int *tmp, int left, int right)
{
    if (left >= right)
        return;
    int mid = (left + right) / 2;
    mergeSort(data, tmp, left, mid);
    mergeSort(data, tmp, mid + 1, right);
    int l = left, r = mid + 1, t = 0;
    while (l <= mid && r <= right)
    {
        if (data[l] < data[r])
            tmp[t++] = data[l++];
        else
            tmp[t++] = data[r++];
    }
    if (r > right)
    {
        while (l <= mid)
            tmp[t++] = data[l++];
    }
    else
    {
        while (r <= right)
            tmp[t++] = data[r++];
    }
    for (int i = 0; i < right - left + 1; i++)
        data[left + i] = tmp[i];
}

int Matrix::sort_data()
{
    int *tmp = new int[rows * cols];
    mergeSort(data, tmp, start, finish);
    delete (tmp);
}
int Matrix::addMatrix(Matrix &) {}

// A row == B col, A col == B row  C row == B row, C col == A col
int Matrix::MultiplyMatrix(Matrix &matrixA, Matrix &matrixB)
{
    printf("\n");
    int ar = matrixA.rows, ac = matrixA.cols;
    int br = matrixB.rows, bc = matrixB.cols;
    int as = matrixA.start, bs = matrixB.start;
    int sum;
    for (int col = 0; col < ac; col++)
    {
        for (int row = 0; row < br; row++)
        {
            sum = 0;
            for (int k = 0; k < bc; k++)
            {
                sum += matrixA.data[as + col * ar + k] * matrixB.data[bs + k * br + row];
            }
            data[start + col * br + row] = sum;
        }
    }
    return 1;
}

int main()
{
    Matrix matrixA(AROWS, ACOLS);
    Matrix matrixA1(AROWS, ACOLS);
    Matrix matrixB(BROWS, BCOLS);
    Matrix matrixC(CROWS, CCOLS);

    srand(time(NULL));

    matrixA.get_data();
    matrixA.show_data();
    matrixB.get_data();
    matrixB.show_data();

    matrixC.MultiplyMatrix(matrixB, matrixA);
    matrixC.show_data();

    matrixA.sort_data();
    matrixA.show_data();
    matrixB.sort_data();
    matrixB.show_data();

    system("pause");
    return 0;
}
