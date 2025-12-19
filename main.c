#include <stdio.h>
#include <stdlib.h>
#include "matrixOp.h"

int main() {
	int i, j;
	int A[SIZE][SIZE], B[SIZE][SIZE], C[SIZE][SIZE], D[SIZE][SIZE];
	double dst[SIZE][SIZE];
	double inv[SIZE][SIZE];

    // Input matrixA  // 1 2 3 0 1 4 5 6 0
    printf("Enter A (3x3): ");
	for(i=0; i<SIZE; i++) {
		for(j=0; j<SIZE; j++) {
			scanf("%d", &A[i][j]);
		}
	}

	// Input matrixB  // 1 2 3 4 -1 -2 -3 -4 -5
    printf("Enter B (3x3): ");
	for(i=0; i<SIZE; i++) {
		for(j=0; j<SIZE; j++) {
			scanf("%d", &B[i][j]);
		}
	}
	
	// Implement inverse matrix
	if(matInverse3x3(A, inv) == 1) {
		printf("Inverse matrix A:\n");
		printMatrixDouble(inv);
	} else {
		printf("No inverse matrix\n");
	}

	// Implement add, sub matrix
	matAdd(A, B, C);
	matSub(A, B, D);
	printf("A + B:\n");
	printMatrix(C);
	printf("A - B:\n");
	printMatrix(D);

	// Implement transpose matrix
	matTranspose(A, C);
	printf("A ^ T:\n");
	printMatrix(C);

	// Implement element wise multiplication matrix
	matMul_element_wise(A, B, C);
	printf("A(i,j) * B(i,j):\n");
	printMatrix(C);

	// Implement multiplication matrix
	matMul(A, B, C);
	printf("A * B:\n");
	printMatrix(C);
	
	return 0;
}