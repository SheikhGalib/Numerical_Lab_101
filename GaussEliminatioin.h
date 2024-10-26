#ifndef GAUSSELIMINATIOIN_H
#define GAUSSELIMINATIOIN_H

#include <iostream>

class Gauss_Elimination_Equation {
public:
    int variable_no;
    double **matrix;

    Gauss_Elimination_Equation();
    ~Gauss_Elimination_Equation();

    void Create_Equation();
    void Print_Matrix();
    void Row_Operation_Gauss(int row, int column);
    void Row_Operation_Jordan(int row, int column);
    void Gauss_Elimination();
    void Gauss_Elimination_Solve();
};

#endif
