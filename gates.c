#include "gates.h"

// AND gate
int AND_gate(int a, int b) {
    return a && b;
}

// OR gate
int OR_gate(int a, int b) {
    return a || b;
}

// NOT gate
int NOT_gate(int a) {
    return !a;
}

// NAND gate
int NAND_gate(int a, int b) {
    return !(a && b);
}

// NOR gate
int NOR_gate(int a, int b) {
    return !(a || b);
}

// XOR gate
int XOR_gate(int a, int b) {
    return a ^ b;
}

// XNOR gate
int XNOR_gate(int a, int b) {
    return !(a ^ b);
}