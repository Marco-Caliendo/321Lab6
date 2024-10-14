#include "gates.h"

int circuit1(int a, int b)
{
    int result1 = OR_gate(AND_gate(a,b),AND_gate(NOT_gate(a),NOT_gate(b)));
    return result1;
}


int circuit2(int a, int b)
{
    int result2 = OR_gate(AND_gate(NOT_gate(a),b), AND_gate(a,NOT_gate(b)));
    return result2;
}
