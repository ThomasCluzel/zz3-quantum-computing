#include "types.hpp"
#include "kronecker.hpp"
#include "utilities.hpp"

#include <cassert>

int main ()
{
    Matrix<int> m(2, 2);
    m(0, 1) = 1;
    m(1, 0) = 1;
    Matrix<int> identity(2, 2);
    identity(0, 0) = 1;
    identity(1, 1) = 1;

    Matrix<int> expected(4, 4);
    expected(0, 1) = 1;
    expected(1, 0) = 1;
    expected(2, 3) = 1;
    expected(3, 2) = 1;

    auto result = kronecker(identity, m);

    assert(result == expected && "kronecker product not computed correctly");

    return 0;
}