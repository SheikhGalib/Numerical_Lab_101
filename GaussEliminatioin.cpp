#include "GaussEliminatioin.h"
#include <iomanip>

using namespace std;

Gauss_Elimination_Equation::Gauss_Elimination_Equation() : variable_no(0), matrix(nullptr) {}

Gauss_Elimination_Equation::~Gauss_Elimination_Equation() {
    for (int i = 0; i < variable_no; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void Gauss_Elimination_Equation::Create_Equation() {
    cout << "Enter Variable Number: " << endl;
    cin >> variable_no;

    matrix = new double*[variable_no];
    for (int i = 0; i < variable_no; i++) {
        matrix[i] = new double[variable_no + 1];
    }

    for (int i = 0; i < variable_no; i++) {
        for (int j = 0; j < variable_no + 1; j++) {
            cout << "Enter x" << i + 1 << j + 1 << " : " << endl;
            cin >> matrix[i][j];
        }
    }

    Print_Matrix();
}

void Gauss_Elimination_Equation::Print_Matrix() {
    cout << endl << endl;
    for (int i = 0; i < variable_no; i++) {
        for (int j = 0; j < variable_no + 1; j++) {
            cout << setw(10) << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void Gauss_Elimination_Equation::Row_Operation_Gauss(int row, int column) {
    int k;

    for (int i = row - 1; i >= 0; i--) {
        if (matrix[i][column] == 0) {
            continue;
        } else {
            k = row - i;
            break;
        }
    }
    double compliment = (matrix[row][column] / matrix[row - k][column]);

    for (int j = 0; j < variable_no + 1; j++) {
        matrix[row][j] -= matrix[row - k][j] * compliment;
    }
}

void Gauss_Elimination_Equation::Row_Operation_Jordan(int row, int column) {
    int k;

    for (int i = row + 1; i < variable_no; i++) {
        if (matrix[i][column] == 0) {
            continue;
        } else {
            k = i - row;
            break;
        }
    }
    double compliment = (matrix[row][column] / matrix[row + k][column]);

    for (int j = 0; j < variable_no + 1; j++) {
        matrix[row][j] -= matrix[row + k][j] * compliment;
    }
}

void Gauss_Elimination_Equation::Gauss_Elimination() {
    for (int j = 0; j < variable_no + 1; j++) {
        for (int i = variable_no - 1; i >= 0; i--) {
            if (i > j) {
                Row_Operation_Gauss(i, j);
            }
        }
    }
    Print_Matrix();
}

void Gauss_Elimination_Equation::Gauss_Elimination_Solve() {
    Create_Equation();
    Gauss_Elimination();
}
