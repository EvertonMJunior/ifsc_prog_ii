typedef struct matrix_t Matrix_t;

Matrix_t *matrix_create(int n);
void matrix_destroy(Matrix_t *matrix);
void matrix_insert(Matrix_t *matrix, int i, int j, int value);
int matrix_get(Matrix_t *matrix, int i, int j);
Matrix_t *matrix_sum(Matrix_t *matrix1, Matrix_t *matrix2);
Matrix_t *matrix_multiply(Matrix_t *matrix1, Matrix_t *matrix2);
Matrix_t *matrix_inverse(Matrix_t *matrix);
void matrix_print(Matrix_t *matrix);
