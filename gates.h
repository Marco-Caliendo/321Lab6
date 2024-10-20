#ifndef GATES_H
#define GATES_H

// Prototypes for the logical gates
int AND_gate(int a, int b);
int OR_gate(int a, int b);
int NOT_gate(int a);
int NAND_gate(int a, int b);
int NOR_gate(int a, int b);
int XOR_gate(int a, int b);
int XNOR_gate(int a, int b);
int AND_N(int bitsA[], int bitsB[], int n);
int OR_N(int bitsA[], int bitsB[], int n);

#endif //GATES_H
