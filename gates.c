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

// AND N gate
int AND_N(int bitsA[], int bitsB[], int n) {
    for (int i = 0; i < n; i++) {
        if (!(bitsA[i] && bitsB[i])) {
            return 0;
        }
    }
    return 1;
}

// OR N gate
int OR_N(int bitsA[], int bitsB[], int n) {
    for (int i = 0; i < n; i++) {
        if (bitsA[i] || bitsB[i]) {
            return 1;
        }
    }
    return 0;
}