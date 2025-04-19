#include "matrix.h"
#include <stdio.h>

static void print_matrix(const char *label, const Matrix *m)
{
    printf("%s\n", label);
    for (size_t i = 0; i < m->r; ++i) {
        printf("[ ");
        for (size_t j = 0; j < m->c; ++j)
            printf("%6.0f ", m_get(m, i, j));
        puts("]");
    }
    putchar('\n');
}

int main(void)
{
    /* A ------------------------------------------------------------ */
    Matrix A = m_create(2, 2);
    double a_vals[4] = { 6, 4,
                         8, 3 };
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            m_set(&A, i, j, a_vals[i * 2 + j]);

    /* B ------------------------------------------------------------ */
    Matrix B = m_create(2, 3);
    double b_vals[6] = { 1, 2, 3,
                         4, 5, 6 };
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 3; ++j)
            m_set(&B, i, j, b_vals[i * 3 + j]);

    /* C ------------------------------------------------------------ */
    Matrix C = m_create(2, 3);
    double c_vals[6] = { 2, 4, 6,
                         1, 3, 5 };
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 3; ++j)
            m_set(&C, i, j, c_vals[i * 3 + j]);

    /* D = A + (3B) * Cᵀ ------------------------------------------- */
    Matrix B3   = m_scale(&B, 3);
    Matrix CT   = m_transpose(&C);
    Matrix PROD = m_mul(&B3, &CT);
    Matrix D    = m_add(&A, &PROD);
    print_matrix("Result D =", &D);

    /* Extra tests -------------------------------------------------- */
    Matrix E = m_mul(&A, &B);
    print_matrix("E =", &E);

    Matrix BT = m_transpose(&B);
    Matrix F  = m_mul(&C, &BT);
    print_matrix("F =", &F);

    Matrix G = m_add(&B, &C);
    print_matrix("G =", &G);

    /* tidy --------------------------------------------------------- */
    m_free(&A);  m_free(&B);  m_free(&C);
    m_free(&B3); m_free(&CT); m_free(&PROD); m_free(&D);
    m_free(&E);  m_free(&BT); m_free(&F);    m_free(&G);
    return 0;
}
