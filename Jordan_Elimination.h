#ifndef JORDAN_ELIMINATION_H
#define JORDAN_ELIMINATION_H

#include <iostream>

class JordanEquation {
public:
    int variable_no;
    double **matrix;

    JordanEquation();
    ~JordanEquation();

    void Create_Equation();
    void Print_Matrix();
    void Row_Operation_Gauss(int row, int column);
    void Row_Operation_Jordan(int row, int column);
    void Gauss_Elimination();
    void Gauss_Jordan();
    void Row_Echelon();
    void Jordan_Elimination();
};

#endif
