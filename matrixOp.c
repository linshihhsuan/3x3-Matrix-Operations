#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matrixOp.h"

// C = A + B
void matAdd(int A[SIZE][SIZE], int B[SIZE][SIZE], int C[SIZE][SIZE]) {
	int i, j;
	for(i=0; i<SIZE; i++) {
		for(j=0; j<SIZE; j++) {
			C[i][j] = A[i][j] + B[i][j];
		}
	}
}

// C = A - B
void matSub(int A[SIZE][SIZE], int B[SIZE][SIZE], int C[SIZE][SIZE]) {
	int i, j;
	for(i=0; i<SIZE; i++) {
		for(j=0; j<SIZE; j++) {
			C[i][j] = A[i][j] - B[i][j];
		}
	}
}

// Transpose: B = A^T
void matTranspose(int A[SIZE][SIZE], int B[SIZE][SIZE]) {
	int i, j;
	int temp_i = 0, temp_j = 0;
	for(i=0; i<SIZE; i++) {
		for(j=0; j<SIZE; j++) {
			if(i != j) {
				temp_i = i;
				temp_j = j;
				B[i][j] = A[temp_j][temp_i];
			} else {
				B[i][j] = A[i][j];
			}
		}
	}
}

// Element wise multiplication Ci,j = Ai,j * Bi,j
void matMul_element_wise(int A[SIZE][SIZE], int B[SIZE][SIZE], int C[SIZE][SIZE]) {
	int i, j;
	for(i=0; i<SIZE; i++) {
		for(j=0; j<SIZE; j++) {
			C[i][j] = A[i][j] * B[i][j];
		}
	}
}


// Multiplication: C = A * B
void matMul(int A[SIZE][SIZE], int B[SIZE][SIZE], int C[SIZE][SIZE]) {
	int i, j, k;
	for(i=0; i<SIZE; i++) {
		for(j=0; j<SIZE; j++) {
			C[i][j] = 0;
			for(k=0; k<SIZE; k++) {
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}
}

// Determinant(3x3)
int matDet3x3(int A[SIZE][SIZE]) {
    int det;
    det = A[0][0] * (A[1][1]*A[2][2] - A[1][2]*A[2][1])
		- A[0][1] * (A[1][0]*A[2][2] - A[1][2]*A[2][0])
        + A[0][2] * (A[1][0]*A[2][1] - A[1][1]*A[2][0]);
    return det;
}

// Adjoint: Adj(A) = adj
void matAdjoint3x3(int A[SIZE][SIZE], int adj[SIZE][SIZE]) {

    adj[0][0] =  (A[1][1]*A[2][2] - A[1][2]*A[2][1]);
    adj[1][0] = -(A[1][0]*A[2][2] - A[1][2]*A[2][0]);
    adj[2][0] =  (A[1][0]*A[2][1] - A[1][1]*A[2][0]);

    adj[0][1] = -(A[0][1]*A[2][2] - A[0][2]*A[2][1]);
    adj[1][1] =  (A[0][0]*A[2][2] - A[0][2]*A[2][0]);
    adj[2][1] = -(A[0][0]*A[2][1] - A[0][1]*A[2][0]);

    adj[0][2] =  (A[0][1]*A[1][2] - A[0][2]*A[1][1]);
    adj[1][2] = -(A[0][0]*A[1][2] - A[0][2]*A[1][0]);
    adj[2][2] =  (A[0][0]*A[1][1] - A[0][1]*A[1][0]);
}

// Inverse: inv[]  // Using double for storage is more precise
// Return 1 means success, return 0 means det = 0
int matInverse3x3(int A[SIZE][SIZE], double inv[SIZE][SIZE]) {
	int i, j;
    int det = matDet3x3(A);
    if(det == 0) {
        return 0;  // no inverse
    }

    int adj[SIZE][SIZE] = {0};
    matAdjoint3x3(A, adj);

	// Transform int arr[] to double arr[]
	double adj_double[SIZE][SIZE];
	intMatToDouble(adj, adj_double);

    // inv = adj / det
    for(i=0; i<SIZE; i++) {
        for(j=0; j<SIZE; j++) {
            inv[i][j] = adj_double[i][j] / (double)det;
        }
    }
    return 1;
}

// Print matrix with int type
void printMatrix(int D[SIZE][SIZE]) {
	int i, j;
	printf("Result matrix: \n");
	for(i=0; i<SIZE; i++) {
		for(j=0; j<SIZE; j++) {
			printf("%2d ", D[i][j]);
		}
		printf("\n");
	}
}

// Transform int arr[] to double arr[]
void intMatToDouble(int src[SIZE][SIZE], double dst[SIZE][SIZE]) {
	int m, n;
	for(m=0; m<SIZE; m++) {
		for(n=0; n<SIZE; n++) {
			dst[m][n] = (double)src[m][n];
		}
	}
}

// Print matrix with double type
void printMatrixDouble(double D[SIZE][SIZE]) {
	int i, j;
	for(i=0; i<SIZE; i++) {
		for(j=0; j<SIZE; j++) {
			printf("%.2f ", D[i][j]);
		}
		printf("\n");
	}
}

