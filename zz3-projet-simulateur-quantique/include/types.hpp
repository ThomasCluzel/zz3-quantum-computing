/**
 * \file types.hpp
 * \author Thomas Cluzel
 * \date sat. 23 nov. 2019
 * \version 1.0
 * \brief Contains the types the program uses.
 */

#ifndef TYPES_HPP
#define TYPES_HPP

#include <complex>
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>

using Complex = std::complex<double>;
template <typename T>
using Vector = boost::numeric::ublas::vector<T>;
template <typename T>
using Matrix = boost::numeric::ublas::matrix<T>;

#endif // TYPES_HPP
