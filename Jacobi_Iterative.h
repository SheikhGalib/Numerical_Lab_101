#ifndef JACOBI_ITERATIVE_H
#define JACOBI_ITERATIVE_H

#include <cmath>

class Iterative {
public:
    double ca, cb, cc, cd, ce, c;

    void create_eqn(int a, int b, int c, int d, int e, int f);
};

class Jacobi_Iterative_Equation {
public:
    Iterative e1, e2, e3, e4, e5;
    double er1, er2, er3, er4, er5, erm;

    void assign_val(void);
    int Jacobi(double a, double b, double c, double d, double e);
    void Jacobi_Iterative_Solve(void);
};

#endif
