#include "types.hpp"
#include "addition.hpp"
#include "utilities.hpp"

#include <cassert>

int main()
{
    Vector<int> register_vector(32); // 2^5 = 32 (carry, x, y, sum=|0>, next_carry=|0>)

    // Test each possible addition and its result (from 0 + 0 + 0 to 1 + 1 + 1)
    for(unsigned i = 0; i < 8; i++)
    {
        register_vector.clear();
        register_vector[i<<2] = 1; // a possible addition

        auto result = addition(register_vector); // compute the result with the quantum algo

        unsigned expected_result = ((i>>2)&1) + ((i>>1)&1) + (i&1); // compute the result with the classic algo
        expected_result = (expected_result>>1) + ((expected_result&1)<<1); // in the vector the sum is stored before the next carry
        unsigned index_result = get_index_of_1(result);

        assert(index_result == ((i<<2) + expected_result) && "The addition is incorrect.");
    }

    return 0;
}