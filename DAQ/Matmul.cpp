#include <bits/stdc++.h>
using namespace std;

using Matrix = vector<vector<int>>;

// Add two matrices
Matrix add(const Matrix &A, const Matrix &B) {
    int n = A.size();
    Matrix C(n, vector<int>(n));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

// Subtract two matrices
Matrix subtract(const Matrix &A, const Matrix &B) {
    int n = A.size();
    Matrix C(n, vector<int>(n));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
    return C;
}

// Recursive divide & conquer multiplication
Matrix multiply(const Matrix &A, const Matrix &B) {
    int n = A.size();
    Matrix C(n, vector<int>(n, 0));

    if(n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }

    int k = n/2;

    Matrix A11(k, vector<int>(k)), A12(k, vector<int>(k)),
           A21(k, vector<int>(k)), A22(k, vector<int>(k));
    Matrix B11(k, vector<int>(k)), B12(k, vector<int>(k)),
           B21(k, vector<int>(k)), B22(k, vector<int>(k));

    for(int i = 0; i < k; i++) {
        for(int j = 0; j < k; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j+k];
            A21[i][j] = A[i+k][j];
            A22[i][j] = A[i+k][j+k];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j+k];
            B21[i][j] = B[i+k][j];
            B22[i][j] = B[i+k][j+k];
        }
    }

    Matrix C11 = add(multiply(A11, B11), multiply(A12, B21));
    Matrix C12 = add(multiply(A11, B12), multiply(A12, B22));
    Matrix C21 = add(multiply(A21, B11), multiply(A22, B21));
    Matrix C22 = add(multiply(A21, B12), multiply(A22, B22));


    for(int i = 0; i < k; i++) {
        for(int j = 0; j < k; j++) {
            C[i][j]       = C11[i][j];
            C[i][j+k]     = C12[i][j];
            C[i+k][j]     = C21[i][j];
            C[i+k][j+k]   = C22[i][j];
        }
    }

    return C;
}

int main() {
    Matrix A = {{1, 2}, {3, 4}};
    Matrix B = {{5, 6}, {7, 8}};

    Matrix C = multiply(A, B);

    cout << "Result Matrix:" << endl;
    for(auto &row : C) {
        for(auto x : row) cout << x << " ";
        cout << endl;
    }
    return 0;
}
