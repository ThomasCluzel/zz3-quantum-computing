/**
 * \file kronecker.hpp
 * \author Thomas Cluzel
 * \date sat. 23 nov. 2019
 * \version 1.0
 * \brief Contains a templated function to compute the Kronecker product of
 *        two matrices.
 */

#ifndef KRONECKER_HPP
#define KRONECKER_HPP

#include "types.hpp"

/**
 * \fn template <typename T> Matrix<T> kronecker(const Matrix<T> & a, const Matrix<T> & b)
 * \brief Computes the Kronecker product \f$ a \otimes b \f$
 * \tparam T the type of values in the matrices (e.g. int, double, std::complex<double>)
 * \param a a matrix
 * \param b a matrix
 * \return the Kronecker product of a and b
 */
template <typename T>
Matrix<T> kronecker(const Matrix<T> & a, const Matrix<T> & b);

// -- Implementations

template <typename T>
Matrix<T> kronecker(const Matrix<T> & a, const Matrix<T> & b)
{
    using namespace boost::numeric::ublas;

    unsigned a_rows = a.size1();
    unsigned a_columns = a.size2();
    unsigned b_rows = b.size1();
    unsigned b_columns = b.size2();
    Matrix<T> result(a_rows * b_rows, a_columns * b_columns);

    for(unsigned i = 0; i < a_rows; i++)
    {
        for(unsigned j = 0; j < a_columns; j++)
        {
            for(unsigned k = 0; k < b_rows; k++)
            {
                for(unsigned l = 0; l < b_columns; l++)
                {
                    result(i * b_rows + k, j * b_columns + l) = a(i, j) * b(k, l);
                }
            }
        }
    }

    return result;
}

#endif // KRONECKER_HPP
