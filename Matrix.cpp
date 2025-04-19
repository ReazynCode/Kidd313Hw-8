#include "Matrix.hpp"
#include <iomanip>
#include <stdexcept>

/* constructors */
Matrix::Matrix(std::size_t r, std::size_t c, double val)
    : r_(r), c_(c), data_(r * c, val) {}

Matrix::Matrix(std::initializer_list<std::initializer_list<double>> rows)
    : r_(rows.size()), c_(rows.begin()->size()), data_(r_ * c_)
{
    std::size_t i = 0;
    for (auto& row : rows) {
        if (row.size() != c_) throw std::invalid_argument("ragged init‑list");
        std::size_t j = 0;
        for (double x : row) data_[i * c_ + j++] = x;
        ++i;
    }
}

/* element access */
double Matrix::operator()(std::size_t i, std::size_t j) const
{ return data_[i * c_ + j]; }

double& Matrix::operator()(std::size_t i, std::size_t j)
{ return data_[i * c_ + j]; }

/* ops */
Matrix Matrix::operator+(const Matrix& rhs) const
{
    if (r_ != rhs.r_ || c_ != rhs.c_) throw std::invalid_argument("dim +");
    Matrix out(r_, c_);
    for (std::size_t k = 0; k < data_.size(); ++k)
        out.data_[k] = data_[k] + rhs.data_[k];
    return out;
}

Matrix Matrix::operator*(double k) const
{
    Matrix out(*this);
    for (double& x : out.data_) x *= k;
    return out;
}

Matrix operator*(double k, const Matrix& m) { return m * k; }

Matrix Matrix::operator*(const Matrix& rhs) const
{
    if (c_ != rhs.r_) throw std::invalid_argument("dim *");
    Matrix out(r_, rhs.c_);
    for (std::size_t i = 0; i < r_; ++i)
        for (std::size_t j = 0; j < rhs.c_; ++j)
            for (std::size_t k = 0; k < c_; ++k)
                out(i,j) += (*this)(i,k) * rhs(k,j);
    return out;
}

Matrix Matrix::transposed() const
{
    Matrix out(c_, r_);
    for (std::size_t i = 0; i < r_; ++i)
        for (std::size_t j = 0; j < c_; ++j)
            out(j,i) = (*this)(i,j);
    return out;
}

/* stream dump – matches requested style */
std::ostream& operator<<(std::ostream& os, const Matrix& m)
{
    for (std::size_t i = 0; i < m.rows(); ++i) {
        os << '[';
        for (std::size_t j = 0; j < m.cols(); ++j)
            os << std::setw(6) << m(i,j);
        os << "]\n";
    }
    return os;
}
