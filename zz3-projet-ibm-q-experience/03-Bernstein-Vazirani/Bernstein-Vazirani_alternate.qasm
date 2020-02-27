// Bernstein-Vazirani algorithm
// Variant with Cnot gates instead of Z gates and an ancilla qubit

OPENQASM 2.0;
include "qelib1.inc";

qreg q[5];
creg c[5];

// An unknown number represented as a quantum circuit
// here number = 1101
gate number() q0, q1, q2, q3, q4
{
	cx q0, q4;
    cx q2, q4;
    cx q3, q4;
}

x q[4];
h q;

// call to the oracle
number q[0], q[1], q[2], q[3], q[4];

h q[0];
h q[1];
h q[2];
h q[3];

measure q[0] -> c[0];
measure q[1] -> c[1];
measure q[2] -> c[2];
measure q[3] -> c[3];
