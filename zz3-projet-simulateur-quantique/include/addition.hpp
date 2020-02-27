/**
 * \file addition.hpp
 * \author Thomas Cluzel
 * \date sun. 24 nov. 2019
 * \version 1.0
 * \brief Contains a templated function to add two qubits in a register
 *        of five qubits.
 */

#ifndef ADDITION_HPP
#define ADDITION_HPP

#include "types.hpp"
#include "utilities.hpp"
#include "cnot_toffoli.hpp"

/**
 * \fn template <typename T> Vector<T> addition(const Vector<T>& register_vector)
 * \brief Computes the addition of 2 qubits in a 5 qubits register.
 * \tparam T the type of values in the vector (e.g. int, double, std::complex<double>)
 * \param register_vector a vector of size 32 representing the state of a 5 qubits register (carry, x, y, sum=|0>, next_carry=|0>)
 * \return a vector of size 32, result of the addition
 */
template <typename T>
Vector<T> addition(const Vector<T>& register_vector);

// -- Implementations

template <typename T>
Vector<T> addition(const Vector<T>& register_vector)
{
    // Generate all the gates (once at first call)
    static const Matrix<T> first_toffoli = build_toffoli<T>(5, 1, 2, 4);
    static const Matrix<T> second_toffoli = build_toffoli<T>(5, 0, 1, 4);
    static const Matrix<T> third_toffoli = build_toffoli<T>(5, 0, 2, 4);
    static const Matrix<T> first_Cnot = build_Cnot<T>(5, 0, 3);
    static const Matrix<T> second_Cnot = build_Cnot<T>(5, 1, 3);
    static const Matrix<T> third_Cnot = build_Cnot<T>(5, 2, 3);

    // Compute the circuit (the product of the gates)
    static const Matrix<T> addition = first_toffoli * second_toffoli * third_toffoli * first_Cnot * second_Cnot * third_Cnot;

    return addition * register_vector;
}

#endif // ADDITION_HPP
