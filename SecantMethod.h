#ifndef SECANTMETHOD_H
#define SECANTMETHOD_H

#include <iostream>
#include <cmath>

class SecantMethod {
public:
    SecantMethod() {}

    // Public method to start the Secant Method process
    void secantMethod();

private:
    double tolerance;
    int maxIterations;
    double x0, x1;      // Initial guesses
    double coefA, coefB, coefC;  // Coefficients for the quadratic equation

    // Core method to perform Secant Method
    void findRoot();

    // Evaluates the quadratic equation ax^2 + bx + c
    double evaluateEquation(double x);
};

#endif

