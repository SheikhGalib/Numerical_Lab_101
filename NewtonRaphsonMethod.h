#ifndef NEWTONRAPHSONMETHOD_H
#define NEWTONRAPHSONMETHOD_H

#include <iostream>
#include <cmath>

class NewtonRaphsonMethod {
public:
    NewtonRaphsonMethod() {}

    // Public method to start the Newton-Raphson Method process
    void newtonRaphsonMethod();

private:
    double tolerance;
    int maxIterations;
    double x0;           // Initial guess
    double coefA, coefB, coefC;  // Coefficients for the quadratic equation

    // Core method to perform Newton-Raphson Method
    void findRoot();

    // Evaluates the quadratic equation ax^2 + bx + c
    double evaluateEquation(double x);

    // Evaluates the derivative of the equation, which is 2ax + b
    double evaluateDerivative(double x);
};

#endif
