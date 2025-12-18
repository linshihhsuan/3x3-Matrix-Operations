#include <stdio.h>
#include <stdlib.h>
#include "matrixOp.h"

int main() {
	int i, j;
	int A[SIZE][SIZE], B[SIZE][SIZE], C[SIZE][SIZE];
	double dst[SIZE][SIZE];

    // Input matrixA
    printf("Enter A (3x3): ");
	for(i=0; i<SIZE; i++) {
		for(j=0; j<SIZE; j++) {
			scanf("%d", &A[i][j]);
		}
	}

	// Input matrixB
    printf("Enter B (3x3): ");
	for(i=0; i<SIZE; i++) {
		for(j=0; j<SIZE; j++) {
			scanf("%d", &B[i][j]);
		}
	}
	
	matMul(A, B, C);
	printMatrix(C);
	intMatToDouble(C, dst);  // Transform int C[][] to double dst[][]
	printMatrixDouble(dst);
	
	return 0;
}