#ifndef MATRIX_OP_H  // Include Guards
#define MATRIX_OP_H

#define SIZE 3  // Set a 3x3 matrix

// basic operations: C = A + B,  C = A - B
void matAdd(int A[SIZE][SIZE], int B[SIZE][SIZE], int C[SIZE][SIZE]);
void matSub(int A[SIZE][SIZE], int B[SIZE][SIZE], int C[SIZE][SIZE]);

// transpose: B = A^T
void matTranspose(int A[SIZE][SIZE], int B[SIZE][SIZE]);

// multiplication: C = A * B
void matMul(int A[SIZE][SIZE], int B[SIZE][SIZE], int C[SIZE][SIZE]);

// determinant
int matDet3x3(int A[SIZE][SIZE]);

// adjoint: Adj(A) = adj  // adjunct matrix
void matAdjoint3x3(int A[SIZE][SIZE], int adj[SIZE][SIZE]);

// inverse: inv[]  // Using double for storage is more precise
// return 1 means success, return 0 means det = 0
int matInverse3x3(int A[SIZE][SIZE], double inv[SIZE][SIZE]);

// print matrix
void printMatrixInt(int D[SIZE][SIZE]);
void printMatrixDouble(double A[SIZE][SIZE]);

#endif
