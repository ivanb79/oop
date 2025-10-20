#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
	int rows;
	int cols;
	double** data;
} Matrix;

Matrix* matrix_create(int rows, int cols) {
	Matrix* m = (Matrix*)malloc(sizeof(Matrix));
	m->rows = rows;
	m->cols = cols;
	m->data = (double**)malloc(rows * sizeof(double*));
	for (int i = 0; i < rows; ++i) {
		m->data[i] = (double*)calloc(cols, sizeof(double));
	}
	return m;
}

void matrix_delete(Matrix* m) {
	for (int i = 0; i < m->rows; ++i) {
		free(m->data[i]);
	}
	free(m->data);
	free(m);
}

void matrix_input(Matrix* m) {
	for (int i = 0; i < m->rows; ++i) {
		for (int j = 0; j < m->cols; ++j) {
			printf("Unesi element [%d][%d]: ", i, j);
			scanf("%lf", &m->data[i][j]);
		}
	}
}

void matrix_generate(Matrix* m, double a, double b) {
	for (int i = 0; i < m->rows; ++i) {
		for (int j = 0; j < m->cols; ++j) {
			double scale = rand() / (double)RAND_MAX;
			m->data[i][j] = a + scale * (b - a);
		}
	}
}

void matrix_print(Matrix* m) {
	for (int i = 0; i < m->rows; ++i) {
		for (int j = 0; j < m->cols; ++j) {
			printf("%10.4lf ", m->data[i][j]);
		}
		printf("\n");
	}
}

Matrix* matrix_add(Matrix* a, Matrix* b) {
	if (a->rows != b->rows || a->cols != b->cols) return NULL;

	Matrix* res = matrix_create(a->rows, a->cols);
	for (int i = 0; i < a->rows; ++i) {
		for (int j = 0; j < a->cols; ++j) {
			res->data[i][j] = a->data[i][j] + b->data[i][j];
		}
	}
	return res;
}

Matrix* matrix_sub(Matrix* a, Matrix* b) {
	if (a->rows != b->rows || a->cols != b->cols) return NULL;

	Matrix* res = matrix_create(a->rows, a->cols);
	for (int i = 0; i < a->rows; ++i) {
		for (int j = 0; j < a->cols; ++j) {
			res->data[i][j] = a->data[i][j] - b->data[i][j];
		}
	}
	return res;
}

Matrix* matrix_mul(Matrix* a, Matrix* b) {
	if (a->cols != b->rows) return NULL;

	Matrix* res = matrix_create(a->rows, b->cols);
	for (int i = 0; i < a->rows; ++i) {
		for (int j = 0; j < b->cols; ++j) {
			for (int k = 0; k < a->cols; ++k) {
				res->data[i][j] += a->data[i][k] * b->data[k][j];
			}
		}
	}
	return res;
}

Matrix* matrix_transpose(Matrix* m) {
	Matrix* t = matrix_create(m->cols, m->rows);
	for (int i = 0; i < m->rows; ++i) {
		for (int j = 0; j < m->cols; ++j) {
			t->data[j][i] = m->data[i][j];
		}
	}
	return t;
}

int main() {
	srand((unsigned int)time(NULL));

	Matrix* A = matrix_create(2, 3);
	Matrix* B = matrix_create(2, 3);

	matrix_generate(A, 1.0, 5.0);
	matrix_generate(B, 1.0, 5.0);

	printf("Matrica A:\n");
	matrix_print(A);
	printf("\nMatrica B:\n");
	matrix_print(B);

	Matrix* C = matrix_add(A, B);
	printf("\nZbroj A + B:\n");
	matrix_print(C);

	Matrix* D = matrix_transpose(A);
	printf("\nTransponirana matrica A:\n");
	matrix_print(D);

	matrix_delete(A);
	matrix_delete(B);
	matrix_delete(C);
	matrix_delete(D);

	return 0;
}
