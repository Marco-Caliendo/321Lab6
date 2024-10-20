#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "gates.h"

#define N 8

void get_input(int bits[], const char* signal_name);
void generate_random_bits(int bits[]);
void get_byte(int start, int stop, int sig[], int byte[]);
int calculate_circuit1(int A[N], int B[N]);
int calculate_circuit2(int A[N], int B[N]);

int main() {
    int A[N], B[N];
    int choice;

    srand(time(0));

    printf("Choose input method:\n");
    printf("1. Enter the values for A and B manually\n");
    printf("2. Randomly generate values for A and B\n");
    printf("Enter choice (1 or 2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        get_input(A, "A");
        get_input(B, "B");
    } else if (choice == 2) {
        generate_random_bits(A);
        generate_random_bits(B);
    } else {
        printf("Invalid choice! Exiting...\n");
        return 1;
    }

    //**************************************
    // CHOOSE WHICH CIRCUIT TO SIMULATE HERE
    //**************************************
    // circuit 1 or 2
    int result = calculate_circuit1(A, B);

    printf("Output of the Circuit: ");
    printf("%d\n", result);

    return 0;
}

void get_input(int bits[], const char* signal_name) {
    printf("Enter the values for signal %s (0 or 1):\n", signal_name);
    for (int i = 0; i < N; i++) {
        printf("%s[%d]: ", signal_name, i);
        scanf("%d", &bits[i]);
    }
}

void generate_random_bits(int bits[]) {
    for (int i = 0; i < N; i++) {
        bits[i] = rand() % 2;
    }
}

void get_byte(int start, int stop, int sig[], int byte[])
{
    for (int i = start; i <= stop; i++) {
        byte[i - start] = sig[i];
    }
}

int calculate_circuit1(int A[N], int B[N]) {
    int byteA1[4], byteB1[4], byteA2[4], byteB2[4];
    get_byte(0, 3, A, byteA1);
    get_byte(0, 3, B, byteB1);
    get_byte(4, 7, A, byteA2);
    get_byte(4, 7, B, byteB2);

    return NOT_gate(XNOR_gate(AND_N(byteA1, byteB1, 4), OR_N(byteA2, byteB2, 4)));
}

int calculate_circuit2(int A[N], int B[N])
{
    int byteA_12_15[4], byteB_0_3[4];
    int byteA_8_11[4], byteB_4_7[4];
    int byteA_4_7[4], byteB_8_11[4];
    int byteA_0_3[4], byteB_12_15[4];

    // Extract bytes for the calculations
    get_byte(12, 15, A, byteA_12_15);
    get_byte(0, 3, B, byteB_0_3);
    get_byte(8, 11, A, byteA_8_11);
    get_byte(4, 7, B, byteB_4_7);
    get_byte(4, 7, A, byteA_4_7);
    get_byte(8, 11, B, byteB_8_11);
    get_byte(0, 3, A, byteA_0_3);
    get_byte(12, 15, B, byteB_12_15);

    // Calculate the output using the gates
    return OR_gate(
        OR_gate(
            AND_N(byteA_12_15, byteB_0_3, 4),
            OR_N(byteA_8_11, byteB_4_7, 4)
        ),
        AND_gate(
            OR_N(byteA_4_7, byteB_8_11, 4),
            AND_N(byteA_0_3, byteB_12_15, 4)
        )
    );
}
