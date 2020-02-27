#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>

#include <sstream>
#include <cassert>

std::string main_test () {
    using namespace boost::numeric::ublas;
    matrix<double> m (3, 3);
    for (unsigned i = 0; i < m.size1 (); ++ i)
        for (unsigned j = 0; j < m.size2 (); ++ j)
            m (i, j) = 3 * i + j;

    std::ostringstream oss;
    oss << m;

    return oss.str();
}

int main ()
{
    std::string res = main_test();
    assert(res == "[3,3]((0,1,2),(3,4,5),(6,7,8))" && "Error: wrong output");

    return 0;
}