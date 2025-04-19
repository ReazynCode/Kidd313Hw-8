#ifndef MATRIX_H
#define MATRIX_H
#include <stddef.h>

typedef struct {
    size_t r, c;
    double *data;
} Matrix;

/* ctor / dtor */
Matrix m_create(size_t r, size_t c);
void   m_free(Matrix *m);

/* element helpers */
double m_get(const Matrix *m, size_t i, size_t j);
void   m_set(Matrix *m, size_t i, size_t j, double v);

/* operations */
Matrix m_add      (const Matrix *a, const Matrix *b);
Matrix m_scale    (const Matrix *a, double scalar);
Matrix m_transpose(const Matrix *a);
Matrix m_mul      (const Matrix *a, const Matrix *b);

#endif
