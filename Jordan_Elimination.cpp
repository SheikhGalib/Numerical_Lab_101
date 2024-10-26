#include "Jordan_Elimination.h"
#include <iomanip>

using namespace std;

JordanEquation::JordanEquation() : variable_no(0), matrix(nullptr) {}

JordanEquation::~JordanEquation() {
    for (int i = 0; i < variable_no; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void JordanEquation::Create_Equation() {
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

void JordanEquation::Print_Matrix() {
    cout << endl << endl;
    for (int i = 0; i < variable_no; i++) {
        for (int j = 0; j < variable_no + 1; j++) {
            cout << setw(10) << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void JordanEquation::Row_Operation_Gauss(int row, int column) {
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

void JordanEquation::Row_Operation_Jordan(int row, int column) {
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

void JordanEquation::Gauss_Elimination() {
    for (int j = 0; j < variable_no + 1; j++) {
        for (int i = variable_no - 1; i >= 0; i--) {
            if (i > j) {
                Row_Operation_Gauss(i, j);
            }
        }
    }
    Print_Matrix();
}

void JordanEquation::Gauss_Jordan() {
    for (int j = variable_no - 1; j >= 0; j--) {
        for (int i = 0; i < variable_no; i++) {
            if (i < j) {
                Row_Operation_Jordan(i, j);
            }
        }
    }
    Print_Matrix();
}

void JordanEquation::Row_Echelon() {
    for (int i = 0; i < variable_no; i++) {
        for (int j = 0; j < variable_no + 1; j++) {
            if (matrix[i][i] != 0 && i != j) {
                matrix[i][j] /= matrix[i][i];
            }
        }
    }
    for (int i = 0; i < variable_no; i++) {
        matrix[i][i] = 1;
    }
    Print_Matrix();
}

void JordanEquation::Jordan_Elimination() {
    Create_Equation();
    Gauss_Elimination();
    Gauss_Jordan();
    Row_Echelon();
}
