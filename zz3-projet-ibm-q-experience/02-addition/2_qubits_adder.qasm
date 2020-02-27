OPENQASM 2.0;
include "qelib1.inc";

// Subroutine add
// Performs the addition of x and y and the carry c
//   and stores the result in sum and the next carry in nextC
gate add c, x, y, sum, nextC  {
  ccx x, y, nextC;
  ccx c, x, nextC;
  ccx c, y, nextC;
  cx c, sum;
  cx x, sum;
  cx y, sum;
}

qreg q[5];
creg c[5];

// Change the initial state of the quantum register
x q[1];
x q[2];

add q[0], q[1], q[2], q[3], q[4];

measure q -> c;
