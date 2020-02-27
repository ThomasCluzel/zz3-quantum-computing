#include "types.hpp"
#include "kronecker.hpp"
#include "cnot_toffoli.hpp"
#include "utilities.hpp"

#include <sstream>
#include <cassert>

int main()
{
    // Instanciate Cnot and Toffoli gates
    Matrix<int> cnot(4, 4);
    cnot(0, 0) = 1;
    cnot(1, 1) = 1;
    cnot(2, 3) = 1;
    cnot(3, 2) = 1;

    Matrix<int> toffoli(8, 8);
    for(int i=0; i<6; i++)
        toffoli(i, i) = 1;
    toffoli(6, 7) = 1;
    toffoli(7, 6) = 1;

    // Generate Cnot and Toffoli gates
    Matrix<int> cnot_gen = build_Cnot<int>(2, 0, 1);
    Matrix<int> toffoli_gen = build_toffoli<int>(3, 0, 1, 2);

    std::ostringstream oss;
    oss << cnot;
    assert(oss.str() == "[4,4]((1,0,0,0),(0,1,0,0),(0,0,0,1),(0,0,1,0))" &&
        "Cnot badly instanciated");
    oss.str("");
    oss.clear();
    oss << toffoli;
    assert(oss.str() == "[8,8]((1,0,0,0,0,0,0,0),(0,1,0,0,0,0,0,0),"
        "(0,0,1,0,0,0,0,0),(0,0,0,1,0,0,0,0),(0,0,0,0,1,0,0,0),"
        "(0,0,0,0,0,1,0,0),(0,0,0,0,0,0,0,1),(0,0,0,0,0,0,1,0))" &&
        "Toffoli badly instanciated");

    // check generated gates
    assert(cnot == cnot_gen && "Cnot generated is not as expected");
    assert(toffoli == toffoli_gen && "Toffoli generated is not as expected");

    Matrix<int> cnot_3 = build_Cnot<int>(3, 1, 2);
    Matrix<int> cnot_3_computed = kronecker(build_identity_matrix<int>(2), cnot);
    assert(cnot_3 == cnot_3_computed && "Cnot in (3, 3) matrix not correct");

    return 0;
}
