/**
 * \file cnot_toffoli.hpp
 * \author Thomas Cluzel
 * \date sat. 23 nov. 2019
 * \version 1.0
 * \brief Contains templated functions to generate Cnot and Toffoli gates
 *        for a qubit register of any size.
 */

#ifndef CNOT_TOFFOLI_HPP
#define CNOT_TOFFOLI_HPP

#include "types.hpp"

/**
 * \fn template <typename T> Matrix<T> build_identity_matrix(const unsigned size)
 * \brief Generate a mutable indentity matrix of order ``size``.
 * \tparam T the type of values in the matrix (e.g. int, double, std::complex<double>)
 * \return an identity matrix of order ``size``
 */
template <typename T>
Matrix<T> build_identity_matrix(const unsigned size);

/**
 * \fn template <typename T> Matrix<T> build_Cnot(const unsigned nb_qubits, const unsigned index_qubit_ket1, const unsigned index_qubit_swap)
 * \brief Generate a mutable matrix of order ``nb_qubits`` that apply the Cnot gate to qubits ``index_qubit_ket1`` and qubit ``index_qubit_swap``.
 * \tparam T the type of values in the matrix (e.g. int, double, std::complex<double>)
 * \param nb_qubits the number of qubits in the register (its size)
 * \param index_qubit_ket1 the index of the test qubit (if this qubit is in |1> state the other will change), between 0 and nb_qubits - 1
 * \param index_qubit_swap the index of the qubit that may be changed by the gate, between 0 and nb_qubits - 1
 * \return a matrix of order 2^``nb_qubits``
 */
template <typename T>
Matrix<T> build_Cnot(const unsigned nb_qubits, const unsigned index_qubit_ket1, const unsigned index_qubit_swap);

/**
 * \fn template <typename T> Matrix<T> build_toffoli(const unsigned nb_qubits, const unsigned index_first_qubit_ket1, const unsigned index_second_qubit_ket1, const unsigned index_qubit_swap)
 * \brief Generate a mutable matrix of order ``nb_qubits`` that apply the Toffoli gate to qubits ``index_qubit_ket1``, ``index_second_qubit_ket1`` and ``index_qubit_swap``.
 * \tparam T the type of values in the matrix (e.g. int, double, std::complex<double>)
 * \param nb_qubits the number of qubits in the register (its size)
 * \param index_first_qubit_ket1 the index of the first test qubit (if this qubit is in |1> state it apply Cnot to the others), between 0 and nb_qubits - 1
 * \param index_second_qubit_ket1 the index of the second test qubit (if this qubit is in |1> state it apply Cnot to the others), between 0 and nb_qubits - 1
 * \param index_qubit_swap the index of the qubit that may be changed by the gate, between 0 and nb_qubits - 1
 * \return a matrix of order 2^``nb_qubits``
 */
template <typename T>
Matrix<T> build_toffoli(const unsigned nb_qubits, const unsigned index_first_qubit_ket1, const unsigned index_second_qubit_ket1, const unsigned index_qubit_swap);

// -- Implementations

template <typename T>
Matrix<T> build_identity_matrix(const unsigned size)
{
    Matrix<T> id(size, size);
    id.clear();
    for(unsigned i = 0; i < id.size1(); i++)
        id(i, i) = 1;
    return id;
}

template <typename T>
Matrix<T> build_Cnot(const unsigned nb_qubits, const unsigned index_qubit_ket1, const unsigned index_qubit_swap)
{
    unsigned weight_qubit_ket1 = nb_qubits - index_qubit_ket1 - 1;
    unsigned a = 1 << weight_qubit_ket1;
    unsigned weight_qubit_swap = nb_qubits - index_qubit_swap - 1;
    unsigned b = 1 << weight_qubit_swap;

    unsigned order = 1 << nb_qubits;
    Matrix<T> result = build_identity_matrix<T>(order);

    for(unsigned i = 0; i <order; i++)
    {
        if(i&a) // state must be swap
        {
            result(i, i) = 0;
            if(i&b) // swap 1 to 0
                result(i, i - b) = 1;
            else // swap 0 to 1
                result(i, i + b) = 1;
        }
    }

    return result;
}

template <typename T>
Matrix<T> build_toffoli(const unsigned nb_qubits, const unsigned index_first_qubit_ket1, const unsigned index_second_qubit_ket1, const unsigned index_qubit_swap)
{
    // process with endianness
    unsigned weight_first_qubit_ket1 = nb_qubits - index_first_qubit_ket1 - 1;
    unsigned a = 1 << weight_first_qubit_ket1;
    unsigned weight_second_qubit_ket1 = nb_qubits - index_second_qubit_ket1 - 1;
    unsigned b = 1 << weight_second_qubit_ket1;
    unsigned weight_qubit_swap = nb_qubits - index_qubit_swap - 1;
    unsigned c = 1 << weight_qubit_swap;

    unsigned order = 1 << nb_qubits;
    Matrix<T> result = build_identity_matrix<T>(order);

    for(unsigned i = 0; i <order; i++)
    {
        if(i&a && i&b) // state must be swap
        {
            result(i, i) = 0;
            if(i&c) // swap 1 to 0
                result(i, i - c) = 1;
            else // swap 0 to 1
                result(i, i + c) = 1;
        }
    }

    return result;
}

#endif // CNOT_TOFFOLI_HPP