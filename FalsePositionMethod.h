#ifndef FALSEPOSITIONMETHOD_H
#define FALSEPOSITIONMETHOD_H

#include <iostream>
#include <cmath>

class FalsePositionMethod {
public:
    FalsePositionMethod() {}

    // Public method to start the False Position Method process
    void falsePositionMethod();

private:
    double tolerance;
    int maxIterations;
    double a, b;        // Interval [a, b]
    double coefA, coefB, coefC;  // Coefficients for the quadratic equation

    // Core method to perform False Position Method
    void findRoot();

    // Evaluates the quadratic equation ax^2 + bx + c
    double evaluateEquation(double x);
};

#endif
