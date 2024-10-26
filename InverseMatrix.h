#ifndef INVERSE_MATRIX_H
#define INVERSE_MATRIX_H

#include <vector>

class InverseMatrix {
private:
    std::vector<std::vector<double>> data;
    int rows, cols;

    void swapRows(int row1, int row2);
    void multiplyRow(int row, double scalar);
    void addMultipleOfRow(int sourceRow, int targetRow, double scalar);

public:
    InverseMatrix(int r, int c);
    void input();
    void display();
    void calculateInverse();
};

#endif
