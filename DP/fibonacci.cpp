#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<unsigned long long>> Matrix;

Matrix multiply(Matrix A, Matrix B) {
    int n = A.size();
    Matrix C(n, vector<unsigned long long>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return C;
}

Matrix power(Matrix A, int p) {
    int n = A.size();
    Matrix result(n, vector<unsigned long long>(n));

    for (int i = 0; i < n; ++i) {
        result[i][i] = 1;
    }

    while (p > 0) {
        if (p & 1) {
            result = multiply(result, A);
        }
        A = multiply(A, A);
        p >>= 1;
    }
   
    return result;
}

unsigned long long fibonacci(int n) {
    if (n <= 1) {
        return n;
    }

    Matrix base = {{1, 1}, {1, 0}};
    Matrix result = power(base, n - 1);

    return result[0][0];
}

int main() {
    uint64_t termino; // 10¹⁹
    while(cin>>termino) {
	

    uint64_t fibo = fibonacci(termino);
    cout << "Término " << termino << ": " << fibo << endl;
}
    return 0;
}

