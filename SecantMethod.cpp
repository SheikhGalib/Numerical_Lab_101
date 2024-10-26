#include "SecantMethod.h"
using namespace std;

double SecantMethod::evaluateEquation(double x) {
    // equation type ax^2 + bx + c
    return coefA * x * x + coefB * x + coefC;
}

void SecantMethod::secantMethod() {

     cout << "Enter the coefficients for the quadratic equation (ax^2 + bx + c = 0):\n";
     cout << "a: ";  cin >> coefA;
     cout << "b: ";  cin >> coefB;
     cout << "c: ";  cin >> coefC;

     cout << "Enter initial guesses x0 and x1:\n";
     cout << "x0: ";  cin >> x0;
     cout << "x1: ";  cin >> x1;

     cout << "Enter tolerance: ";  cin >> tolerance;
     cout << "Enter maximum iterations: ";  cin >> maxIterations;

    findRoot();
}

void SecantMethod::findRoot() {
    double x2;
    int iteration = 0;

    while (iteration < maxIterations) {
        // Secant Method formula
        x2 = x1 - evaluateEquation(x1) * ((x1 - x0) / (evaluateEquation(x1) - evaluateEquation(x0)));

        // Check for convergence as no exact root
        if ( abs(evaluateEquation(x2)) <= tolerance) {
             cout << "Root found at: " << x2 << " after " << iteration + 1 << " iterations.\n";
            return;
        }

        // Update guesses
        x0 = x1;
        x1 = x2;
        iteration++;
    }

     cout << "Root approximation after max iterations: " << x2 << "\n";
}
