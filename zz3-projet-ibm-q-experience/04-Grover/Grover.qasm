// Grover's algorithm

OPENQASM 2.0;
include "qelib1.inc";

qreg q[3];
creg c[3];

gate ccz() q0, q1, q2
{
    h q2;
    ccx q0, q1, q2;
    h q2;
}

// The oracle
// look for |101>
gate uf() q0, q1, q2
{
    x q1;
    ccz q0, q1, q2;
    x q1;
}

// Spread operator
gate us() q0, q1, q2
{
    h q1;
    h q2;
    h q3;
    x q1;
    x q2;
    x q3;
    ccz q0, q1, q2;
    x q1;
    x q2;
    x q3;
    h q1;
    h q2;
    h q3;
}

// Begining of the algorithm
h q;
uf q[0], q[1], q[2];
us q[0], q[1], q[2];
uf q[0], q[1], q[2];
us q[0], q[1], q[2];

measure q -> c;
