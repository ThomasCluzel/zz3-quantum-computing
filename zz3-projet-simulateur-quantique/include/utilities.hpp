/**
 * \file utilities.hpp
 * \author Thomas Cluzel
 * \date sat. 23 nov. 2019
 * \version 1.0
 * \brief Contains useful templated fonctions that should be part uBLAS.
 */

#ifndef UTILITIES_HPP
#define UTILITIES_HPP

#include "types.hpp"

/**
 * \fn template <typename T> bool operator==(const Matrix<T> & a, const Matrix<T> & b)
 * \brief Tests the equality of two matrices (the uBLAS library miss this function)
 * \tparam T the type of values in the matrices (e.g. int, double, std::complex<double>)
 * \param a a matrix
 * \param b a matrix
 * \return true if the matrices are equal, false otherwise
 */
template <typename T>
bool operator==(const Matrix<T> & a, const Matrix<T> & b);

/**
 * \fn template <typename T> Vector<T> operator*(const Matrix<T>& a, const Vector<T>& b)
 * \brief Defines the default product of a matrix and a vector: the matrix product.
 * \tparam T the type of values in the vector and the matrix (e.g. int, double, std::complex<double>)
 * \param a a matrix
 * \param b a vector
 * \return a vector equal to \f$ ab \f$
 */
template <typename T>
Vector<T> operator*(const Matrix<T>& a, const Vector<T>& b);

/**
 * \fn template <typename T> Matrix<T> operator*(const Matrix<T>& a, const Matrix<T>& b)
 * \brief Defines the default product of two matrices: the matrix product.
 * \tparam T the type of values in the matrices (e.g. int, double, std::complex<double>)
 * \param a a matrix
 * \param b a matrix
 * \return a matrix equal to \f$ ab \f$
 */
template <typename T>
Matrix<T> operator*(const Matrix<T>& a, const Matrix<T>& b);

/**
 * \fn template <typename T> unsigned get_index_of_1(const Vector<T>& v)
 * \brief Given a vector of 0s and one 1, return the index of the 1.
 * \tparam T the type of values in the vector (e.g. int, double, std::complex<double>)
 * \param v a vector
 * \return an index
 */
template <typename T>
unsigned get_index_of_1(const Vector<T>& v);

// -- Implementations

template <typename T>
bool operator==(const Matrix<T> & a, const Matrix<T> & b)
{
    if(a.size1() != b.size1() || a.size2() != b.size2())
        return false;

    for (unsigned i = 0; i < a.size1(); i++)
    {
        for (unsigned j = 0; j < a.size2(); j++)
        {
            if(a(i, j) != b(i, j))
                return false;
        }
    }

    return true;
}

template <typename T>
Vector<T> operator*(const Matrix<T>& a, const Vector<T>& b)
{
    return boost::numeric::ublas::prod(a, b);
}

template <typename T>
Matrix<T> operator*(const Matrix<T>& a, const Matrix<T>& b)
{
    return boost::numeric::ublas::prod(a, b);
}

template <typename T>
unsigned get_index_of_1(const Vector<T>& v)
{
    unsigned i;
    for(i = 0; i < v.size() && v[i] != 1; i++);
    return i;
}

#endif // UTILITIES_HPP
