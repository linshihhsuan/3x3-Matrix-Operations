#ifndef MATRIX_OP_H  // Include Guards
#define MATRIX_OP_H

#define SIZE 3  // Set a 3x3 matrix

// C = A + B,  C = A - B
void matAdd(int A[SIZE][SIZE], int B[SIZE][SIZE], int C[SIZE][SIZE]);
void matSub(int A[SIZE][SIZE], int B[SIZE][SIZE], int C[SIZE][SIZE]);

// Transpose: B = A^T
void matTranspose(int A[SIZE][SIZE], int B[SIZE][SIZE]);

// Element wise multiplication Ci,j = Ai,j * Bi,j
void matMul_element_wise(int A[SIZE][SIZE], int B[SIZE][SIZE], int C[SIZE][SIZE]);

// Multiplication: C = A * B
void matMul(int A[SIZE][SIZE], int B[SIZE][SIZE], int C[SIZE][SIZE]);

// Determinant
int matDet3x3(int A[SIZE][SIZE]);

// Adjoint: Adj(A) = adj
void matAdjoint3x3(int A[SIZE][SIZE], int adj[SIZE][SIZE]);

// Inverse: inv[]  // Using double for storage is more precise
// Return 1 means success, return 0 means det = 0
int matInverse3x3(int A[SIZE][SIZE], double inv[SIZE][SIZE]);

// Print matrix with int type
void printMatrix(int D[SIZE][SIZE]);

// Transform int arr[] to double arr[]
void intMatToDouble(int src[SIZE][SIZE], double dst[SIZE][SIZE]);

// Print matrix with double type
void printMatrixDouble(double D[SIZE][SIZE]);

#endif
