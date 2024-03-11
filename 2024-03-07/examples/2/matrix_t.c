#include "matrix_t.h"

#include <stdlib.h>
#include <stdio.h>

struct matrix_t
{
    int n;
};

Matrix_t *matrix_create(int n)
{
    Matrix_t *matrix = malloc(sizeof(Matrix_t));
    matrix->n = n;
    return matrix;
}
