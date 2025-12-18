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

// transpose: B = A^T
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

// multiplication: C = A * B
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

// determinant
int matDet3x3(int A[SIZE][SIZE]) {
    int det;
    det = A[0][0] * (A[1][1]*A[2][2] - A[1][2]*A[2][1])
		- A[0][1] * (A[1][0]*A[2][2] - A[1][2]*A[2][0])
        + A[0][2] * (A[1][0]*A[2][1] - A[1][1]*A[2][0]);
    return det;
}

// adjoint: Adj(A) = adj  // adjunct matrix
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

int matInverse3x3(int A[SIZE][SIZE], double inv[SIZE][SIZE]) {
	int i, j;
    int det = matDet3x3(A);
    if(det == 0) {
        return 0;  // no inverse
    }

    int adj[SIZE][SIZE] = {0};
    matAdjoint3x3(A, adj);

    // inv = adj / det
    for(i=0; i<SIZE; i++) {
        for(j=0; j<SIZE; j++) {
            inv[i][j] = adj[i][j] / (double)det;
        }
    }
    return 1;
}

// print matrix
void printMatrixDouble(double D[SIZE][SIZE]) {
	int i, j;
	for(i=0; i<SIZE; i++) {
		for(j=0; j<SIZE; j++) {
			printf("%4f ", D[i][j]);
		}
		printf("\n");
	}
}

void printMatrix(int D[SIZE][SIZE]) {
	int i, j;
	for(i=0; i<SIZE; i++) {
		for(j=0; j<SIZE; j++) {
			printf("%d ", D[i][j]);
		}
		printf("\n");
	}
}