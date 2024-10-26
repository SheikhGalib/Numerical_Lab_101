#include "NewtonRaphsonMethod.h"
using namespace std;

double NewtonRaphsonMethod::evaluateEquation(double x) {
    // equation type ax^2 + bx + c
    return coefA * x * x + coefB * x + coefC;
}

double NewtonRaphsonMethod::evaluateDerivative(double x) {
    // derivative of the equation: f'(x) = 2ax + b
    return 2 * coefA * x + coefB;
}

void NewtonRaphsonMethod::newtonRaphsonMethod() {

     cout << "Enter the coefficients for the quadratic equation (ax^2 + bx + c = 0):\n";
     cout << "a: ";  cin >> coefA;
     cout << "b: ";  cin >> coefB;
     cout << "c: ";  cin >> coefC;


     cout << "Enter initial guess x0: ";  cin >> x0;
     cout << "Enter tolerance: ";  cin >> tolerance;
     cout << "Enter maximum iterations: ";  cin >> maxIterations;

    findRoot();
}

void NewtonRaphsonMethod::findRoot() {
    double x1;
    int iteration = 0;

    while (iteration < maxIterations) {
        // Newton-Raphson formula
        x1 = x0 - evaluateEquation(x0) / evaluateDerivative(x0);

        // Check for convergence as no exact root can be evaluated
        if ( abs(evaluateEquation(x1)) <= tolerance) {
             cout << "Root found at: " << x1 << " after " << iteration + 1 << " iterations.\n";
            return;
        }

        // Update the guess
        x0 = x1;
        iteration++;
    }

     cout << "Root approximation after max iterations: " << x1 << "\n";
}
