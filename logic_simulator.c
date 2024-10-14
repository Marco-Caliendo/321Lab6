#include <stdio.h>
#include "gates.h"
#include "logic_simulator_circuit.h"

// Function prototype
void printTruthTable(int gate);

int main() {
    char choice;
    int a, b, result;

    while (1) {
        printf("Choose a gate to simulate:\n");
        printf("1. NOT\n");
        printf("2. AND\n");
        printf("3. NAND\n");
        printf("4. OR\n");
        printf("5. NOR\n");
        printf("6. XOR\n");
        printf("7. XNOR\n");
        printf("Q. Quit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        // Exit if the user types 'Q' or 'q'
        if (choice == 'Q' || choice == 'q') {
            printf("Exiting the program.\n");
            break;
        }

        switch (choice) {
            case '1':
                printf("Selection: NOT gate.\n");
                printf("Enter input (0 or 1): ");
                scanf("%d", &a);
                result = NOT_gate(a);
                printf("NOT(%d) = %d", a, result);
                break;
            case '2':
                printf("Selection: AND gate.\n");
                printf("Enter two inputs (0 or 1): ");
                scanf("%d %d", &a, &b);
                result = AND_gate(a, b);
                printf("AND(%d, %d) = %d", a, b, result);
                break;
            case '3':
                printf("Selection: NAND gate.\n");
                printf("Enter two inputs (0 or 1): ");
                scanf("%d %d", &a, &b);
                result = NAND_gate(a, b);
                printf("NAND(%d, %d) = %d", a, b, result);
                break;
            case '4':
                printf("Selection: OR gate.\n");
                printf("Enter two inputs (0 or 1): ");
                scanf("%d %d", &a, &b);
                result = OR_gate(a, b);
                printf("OR(%d, %d) = %d", a, b, result);
                break;
            case '5':
                printf("Selection: NOR gate.\n");
                printf("Enter two inputs (0 or 1): ");
                scanf("%d %d", &a, &b);
                result = NOR_gate(a, b);
                printf("NOR(%d, %d) = %d", a, b, result);
                break;
            case '6':
                printf("Selection: XOR gate.\n");
                printf("Enter two inputs (0 or 1): ");
                scanf("%d %d", &a, &b);
                result = XOR_gate(a, b);
                printf("XOR(%d, %d) = %d", a, b, result);
                break;
            case '7':
                printf("Selection: XNOR gate.\n");
                printf("Enter two inputs (0 or 1): ");
                scanf("%d %d", &a, &b);
                result = XNOR_gate(a, b);
                printf("XNOR(%d, %d) = %d", a, b, result);
                break;
            default:
                printf("Invalid choice\n");
                continue;
        }

        // Print truth table
        printTruthTable(choice - '0');

        // Print the result of the two circuits
        printf("Result of logic circuit 1: %d\n", circuit1(a,b));
        printf("Result of logic circuit 2: %d\n", circuit2(a,b));
        printf("\n");
    }

    return 0;
}

// Function to print truth table for the selected gate
void printTruthTable(int gate) {
    int a, b;

    printf("\nTruth table:\n");

    switch (gate) {
        case 1: // NOT gate
            printf("A | NOT(A)\n");
            printf("-----------\n");
            for (a = 0; a <= 1; a++) {
                printf("%d | %d\n", a, NOT_gate(a));
            }
            break;
        case 2: // AND gate
            printf("A B | AND(A,B)\n");
            printf("---------------\n");
            for (a = 0; a <= 1; a++) {
                for (b = 0; b <= 1; b++) {
                    printf("%d %d | %d\n", a, b, AND_gate(a, b));
                }
            }
            break;
        case 3: // NAND gate
            printf("A B | NAND(A,B)\n");
            printf("-----------------\n");
            for (a = 0; a <= 1; a++) {
                for (b = 0; b <= 1; b++) {
                    printf("%d %d | %d\n", a, b, NAND_gate(a, b));
                }
            }
            break;
        case 4: // OR gate
            printf("A B | OR(A,B)\n");
            printf("--------------\n");
            for (a = 0; a <= 1; a++) {
                for (b = 0; b <= 1; b++) {
                    printf("%d %d | %d\n", a, b, OR_gate(a, b));
                }
            }
            break;
        case 5: // NOR gate
            printf("A B | NOR(A,B)\n");
            printf("---------------\n");
            for (a = 0; a <= 1; a++) {
                for (b = 0; b <= 1; b++) {
                    printf("%d %d | %d\n", a, b, NOR_gate(a, b));
                }
            }
            break;
        case 6: // XOR gate
            printf("A B | XOR(A,B)\n");
            printf("---------------\n");
            for (a = 0; a <= 1; a++) {
                for (b = 0; b <= 1; b++) {
                    printf("%d %d | %d\n", a, b, XOR_gate(a, b));
                }
            }
            break;
        case 7: // XNOR gate
            printf("A B | XNOR(A,B)\n");
            printf("----------------\n");
            for (a = 0; a <= 1; a++) {
                for (b = 0; b <= 1; b++) {
                    printf("%d %d | %d\n", a, b, XNOR_gate(a, b));
                }
            }
            break;
        default:
            printf("Invalid gate\n");
    }
}
