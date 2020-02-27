// Bernstein-Vazirani algorithm

OPENQASM 2.0;
include "qelib1.inc";

qreg q[5];
creg c[5];

// An unknown number represented as a quantum circuit
// here number = 10011
gate number() q0, q1, q2, q3, q4
{
	z q0;
    z q1;
    z q4;
}

h q;
number q[0], q[1], q[2], q[3], q[4];
h q;

measure q -> c;
