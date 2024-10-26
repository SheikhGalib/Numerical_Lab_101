#ifndef BISECTIONMETHOD_H
#define BISECTIONMETHOD_H

#include <iostream>
#include <cmath>

class BiSectionMethod {
public:
    BiSectionMethod() {}

    // Public method to start the Bisection Method process
    void bisectionMethod();

private:
    double tolerance;
    int maxIterations;
    double a, b;        // Interval [a, b]
    double coefA, coefB, coefC;  // Coefficients for the quadratic equation

    // Core method to perform Bisection Method
    void findRoot();

    // Function to check if root is within tolerance
    bool isConverged(double a, double b);

    // Evaluates the quadratic equation ax^2 + bx + c
    double evaluateEquation(double x);
};

#endif
