#include "InverseMatrix.h"
#include <iostream>
#include <iomanip>
#include <cmath>

InverseMatrix::InverseMatrix(int r, int c) : rows(r), cols(c) {
    data.resize(rows, std::vector<double>(cols, 0));
}

void InverseMatrix::swapRows(int row1, int row2) {
    for(int j = 0; j < cols; j++) {
        double temp = data[row1][j];
        data[row1][j] = data[row2][j];
        data[row2][j] = temp;
    }
}

void InverseMatrix::multiplyRow(int row, double scalar) {
    for(int j = 0; j < cols; j++) {
        data[row][j] *= scalar;
    }
}

void InverseMatrix::addMultipleOfRow(int sourceRow, int targetRow, double scalar) {
    for(int j = 0; j < cols; j++) {
        data[targetRow][j] += data[sourceRow][j] * scalar;
    }
}

void InverseMatrix::input() {
    std::cout << "Enter matrix elements:" << std::endl;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            std::cin >> data[i][j];
        }
    }
}

void InverseMatrix::display() {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            std::cout << std::fixed << std::setprecision(4) << data[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

void InverseMatrix::calculateInverse() {
    if(rows != cols) {
        std::cout << "Error: Matrix must be square to have an inverse" << std::endl;
        return;
    }

    std::vector<std::vector<double>> augmented(rows, std::vector<double>(2 * cols, 0));

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            augmented[i][j] = data[i][j];
            if(i == j) {
                augmented[i][j + cols] = 1;
            }
        }
    }

    for(int i = 0; i < rows; i++) {
        int pivotRow = i;
        for(int j = i + 1; j < rows; j++) {
            if(std::abs(augmented[j][i]) > std::abs(augmented[pivotRow][i])) {
                pivotRow = j;
            }
        }

        if(std::abs(augmented[pivotRow][i]) < 1e-10) {
            std::cout << "Error: Matrix is not invertible" << std::endl;
            return;
        }

        if(pivotRow != i) {
            for(int j = 0; j < 2 * cols; j++) {
                double temp = augmented[i][j];
                augmented[i][j] = augmented[pivotRow][j];
                augmented[pivotRow][j] = temp;
            }
        }

        double pivot = augmented[i][i];
        for(int j = 0; j < 2 * cols; j++) {
            augmented[i][j] /= pivot;
        }

        for(int j = 0; j < rows; j++) {
            if(j != i) {
                double factor = augmented[j][i];
                for(int k = 0; k < 2 * cols; k++) {
                    augmented[j][k] -= factor * augmented[i][k];
                }
            }
        }
    }

    std::cout << "\nInverse Matrix:" << std::endl;
    for(int i = 0; i < rows; i++) {
        for(int j = cols; j < 2 * cols; j++) {
            std::cout << std::fixed << std::setprecision(4) << augmented[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}
