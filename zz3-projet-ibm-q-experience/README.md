# IBM Q Experience - test

This repository contains the circuits run on [IBM Q Experience](https://quantum-computing.ibm.com/)
in [OpenQASM](https://github.com/Qiskit/openqasm) and Python notebooks
using [Qiskit](https://qiskit.org/documentation/).

The following circuits have been tested:
1. Simple quantum entanglement
1. Addition of two qubits with a previous carry
1. Quantum "Guess the number": Bernstein-Vazirani algorithm
1. Grover's search algorithm
1. Inversion of a simple function using Grover's algorithm

## Simple quantum entanglement

Implementation of the circuit presented in part II.A of the report.

## Addition of two qubits with a previous carry

Implementation of the circuit presented in appendices 1 and 2 of the report.

Results obtained with a real quantum computer were surprising. (see Python notebook)

## Quantum "Guess the number"

Two examples of the Bernstein-Vazirani algorithm to guess a secret number with
only one query to the oracle function. The first example uses Z gates and the second
uses CNOT gates and an ancilla qubit.

The notebook lets the user choose the secret number. The results are simulated
in perfect condition and with noise. The result obtained from an execution on
a real device is enhanced to reduce the noise.

## Grover's search algorithm

One implementation in OpenQASM and two implementations in the Qiskit notebook
with Z gates and with CNOT gates.

## Grover's algorithm to inverse a simple function

A notebook describing how to inverse functions using Grover's algorithm.
The addition presented in the second folder is used as example.


## Miscellaneous information

The file "qelib1.inc" is available on [Github](https://github.com/Qiskit/openqasm/blob/master/examples/generic/qelib1.inc).
"QE" means "Quantum Experience".
It defines all the available gates based on `U(theta,phi,lambda)` and `CX`, the two hardware primitives.

--------------------------------------------------------------------------------
Thomas Cluzel - ZZ3 F2 - 2020
