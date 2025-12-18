#include <stdio.h>
#include <stdlib.h>
#include "matrixOp.h"

int main() {
	int i, j;
	int A[SIZE][SIZE], B[SIZE][SIZE], C[SIZE][SIZE];
	// matrixA
	for(i=0; i<SIZE; i++) {
		for(j=0; j<SIZE; j++) {
			scanf("%d", &A[i][j]);
		}
	}
	// matrixB
	for(i=0; i<SIZE; i++) {
		for(j=0; j<SIZE; j++) {
			scanf("%d", &B[i][j]);
		}
	}
	
	matMul(A, B, C);
	
	return 0;
}