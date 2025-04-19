#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <initializer_list>
#include <vector>
#include <cstddef>
#include <ostream>

class Matrix {
public:
    Matrix(std::size_t r, std::size_t c, double val = 0.0);
    Matrix(std::initializer_list<std::initializer_list<double>> rows);

    /* element access */
    double  operator()(std::size_t i, std::size_t j) const;
    double& operator()(std::size_t i, std::size_t j);

    /* dimensions */
    std::size_t rows() const { return r_; }
    std::size_t cols() const { return c_; }

    /* basic ops */
    Matrix operator+(const Matrix& rhs) const;
    Matrix operator*(const Matrix& rhs) const;      // mat × mat
    Matrix operator*(double k) const;               // mat × scalar
    Matrix transposed() const;

private:
    std::size_t         r_, c_;
    std::vector<double> data_;
};

/* scalar × matrix */
Matrix operator*(double k, const Matrix& m);

/* pretty print */
std::ostream& operator<<(std::ostream& os, const Matrix& m);

#endif
