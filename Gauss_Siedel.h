#ifndef GAUSS_SIEDEL_H
#define GAUSS_SIEDEL_H

#include <iostream>
#include <cmath>

class eqn {
public:
    double ca, cb, cc, cd, ce, c;

    void create_eqn(int a, int b, int c, int d, int e, int f);
};

class Gauss_Siedel_Equation {
public:
    eqn e1, e2, e3, e4, e5;
    double er1, er2, er3, er4, er5, erm;

    void assign_val(void);
    int Gauss_Siedel(double a, double b, double c, double d, double e);
    void Gauss_Siedel_Solve(void);
};

#endif
