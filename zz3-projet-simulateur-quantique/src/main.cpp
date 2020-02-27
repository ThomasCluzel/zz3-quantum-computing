/**
 * \file main.cpp
 * \author Thomas Cluzel
 * \date Mon Jan 13 09:28:37 CET 2020
 * \version 1.0
 * \brief Runs an example of implementation of a quantum processor simulator.
 *        It computes the results of an addition of two qubits.
 */

#include <iostream>
#include <bitset>

#include "types.hpp"
#include "addition.hpp"

/**
 * \fn int main()
 * \return 0 or an error has occurred
 * \brief Entrypoint of the program.
 */
int main()
{
    // 1) We compute 1 + 0 without carry (only manipulate pure states)
    Vector<int> register_vector(32);
    register_vector.clear();
    register_vector[0b01000] = 1;

    register_vector = addition(register_vector);
    std::bitset<5> register_binary_value(get_index_of_1(register_vector));

    std::cout << "(carry, x, y, sum, next_carry)"
              << std:: endl
              << "1 + 0 without previous carry = "
              << register_binary_value
              << std:: endl;

    // 2) We compute (0.9|0> + 0.1|1>) + (0.8|0> + 0.2|1>) without carry
    Vector<Complex> ket_zero_coef(5, 1);
    Vector<Complex> ket_one_coef(ket_zero_coef.size());
    Vector<Complex> register_vector_complex(32);

    // Initialization of the coefficients
    ket_zero_coef[3] = 0.9;
    ket_one_coef[3] = 0.1;
    ket_zero_coef[2] = 0.8;
    ket_one_coef[2] = 0.2;

    // Initialization of the register
    for(unsigned i=0; i<register_vector_complex.size(); i++)
    {
        Complex prod = 1;
        for(unsigned j=0; j<ket_zero_coef.size(); j++)
        {
            prod *= (((i>>j)&1) == 0) ? ket_zero_coef[j] : ket_one_coef[j];
        }
        // Sanitize the product
        if(prod.real() < 1e-300 && prod.imag() < 1e-300)
            prod = 0;
        register_vector_complex[i] = std::move(prod);
    }

    std::cout << std::endl
              << "(0.9|0> + 0.1|1>) + (0.8|0> + 0.2|1>)"
              << std::endl
              << "Before addition"
              << std::endl
              << register_vector_complex
              << std::endl;
    register_vector_complex = addition(register_vector_complex);
    std::cout << "After addition"
              << std::endl
              << register_vector_complex
              << std::endl;

    return 0;
}
