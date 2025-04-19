#include "matrix.h"
#include <stdlib.h>

static size_t idx(const Matrix *m, size_t i, size_t j) { return i * m->c + j; }

/* ctor / dtor ----------------------------------------------------------- */
Matrix m_create(size_t r, size_t c) {
    Matrix m = { r, c, calloc(r * c, sizeof(double)) };
    return m;
}
void m_free(Matrix *m) { free(m->data); m->data = NULL; }

/* element helpers ------------------------------------------------------- */
double m_get(const Matrix *m, size_t i, size_t j) { return m->data[idx(m, i, j)]; }
void   m_set(Matrix *m, size_t i, size_t j, double v) { m->data[idx(m, i, j)] = v; }

/* operations ------------------------------------------------------------ */
Matrix m_add(const Matrix *a, const Matrix *b) {
    Matrix o = m_create(a->r, a->c);
    for (size_t k = 0; k < a->r * a->c; ++k)
        o.data[k] = a->data[k] + b->data[k];
    return o;
}

Matrix m_scale(const Matrix *a, double scalar) {
    Matrix o = m_create(a->r, a->c);
    for (size_t k = 0; k < a->r * a->c; ++k)
        o.data[k] = a->data[k] * scalar;
    return o;
}

Matrix m_transpose(const Matrix *a) {
    Matrix o = m_create(a->c, a->r);
    for (size_t i = 0; i < a->r; ++i)
        for (size_t j = 0; j < a->c; ++j)
            m_set(&o, j, i, m_get(a, i, j));
    return o;
}

Matrix m_mul(const Matrix *a, const Matrix *b) {
    Matrix o = m_create(a->r, b->c);
    for (size_t i = 0; i < a->r; ++i)
        for (size_t j = 0; j < b->c; ++j)
            for (size_t k = 0; k < a->c; ++k)
                o.data[idx(&o, i, j)] += m_get(a, i, k) * m_get(b, k, j);
    return o;
}
