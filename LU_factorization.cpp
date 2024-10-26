#include "LU_factorization.h"

LUDecomposition::LUDecomposition(const std::vector<std::vector<double>>& matrix)
    : A(matrix), L(matrix.size(), std::vector<double>(matrix.size(), 0)),
      U(matrix.size(), std::vector<double>(matrix.size(), 0)) {

    // Initialize L and U
    int n = A.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                L[i][j] = 1.0;
            } else {
                L[i][j] = 0.0;
            }
            U[i][j] = A[i][j];
        }
    }
}

void LUDecomposition::decompose() {
    int n = A.size();
    for (int k = 0; k < n; k++) {
        for (int i = k + 1; i < n; i++) {
            L[i][k] = U[i][k] / U[k][k];
            for (int j = k; j < n; j++) {
                U[i][j] -= L[i][k] * U[k][j];
            }
        }
    }
}

std::vector<double> LUDecomposition::forwardSubstitution(const std::vector<double>& b) const {
    int n = L.size();
    std::vector<double> y(n);
    for (int i = 0; i < n; i++) {
        y[i] = b[i];
        for (int j = 0; j < i; j++) {
            y[i] -= L[i][j] * y[j];
        }
    }
    return y;
}

std::vector<double> LUDecomposition::backwardSubstitution(const std::vector<double>& y) const {
    int n = U.size();
    std::vector<double> x(n);
    for (int i = n - 1; i >= 0; i--) {
        x[i] = y[i];
        for (int j = i + 1; j < n; j++) {
            x[i] -= U[i][j] * x[j];
        }
        x[i] /= U[i][i];
    }
    return x;
}

std::vector<double> LUDecomposition::solve(const std::vector<double>& b) {
    auto y = forwardSubstitution(b);
    return backwardSubstitution(y);
}

void LUDecomposition::printL() const {
    std::cout << "L Matrix:" << std::endl;
    for (const auto& row : L) {
        for (double val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

void LUDecomposition::printU() const {
    std::cout << "U Matrix:" << std::endl;
    for (const auto& row : U) {
        for (double val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}
