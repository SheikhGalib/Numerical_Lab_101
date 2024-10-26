#include "BiSectionMethod.h"
using namespace std;

double BiSectionMethod::evaluateEquation(double x) {
    //equation ax^2 + bx + c
    return coefA * x * x + coefB * x + coefC;
}

void BiSectionMethod::bisectionMethod() {

    cout << "Enter the coefficients for the quadratic equation (ax^2 + bx + c = 0):\n";
     cout << "a: ";  cin >> coefA;
     cout << "b: ";  cin >> coefB;
     cout << "c: ";  cin >> coefC;

    // Taking User Input
     cout << "Enter interval [a, b] for the root search:\n";
     cout << "a: ";  cin >> a;
     cout << "b: ";  cin >> b;

     cout << "Enter tolerance: ";  cin >> tolerance;
     cout << "Enter maximum iterations: ";  cin >> maxIterations;

    //initial interval function
    if (evaluateEquation(a) * evaluateEquation(b) >= 0) {
         cout << "Invalid interval: The function must have different signs at a and b.\n";
        return;
    }

    findRoot();
}

void BiSectionMethod::findRoot() {
    double c = a;
    int iteration = 0;

    while (iteration < maxIterations) {
        c = (a + b) / 2;  // Midpoint

        // convergence or exact root
        if (isConverged(a, b) || evaluateEquation(c) == 0.0) {
             cout << "Root found at: " << c << " after " << iteration + 1 << " iterations.\n";
            return;
        }

        // Update interval
        if (evaluateEquation(c) * evaluateEquation(a) < 0) {
            b = c;
        } else {
            a = c;
        }
        iteration++;
    }

     cout << "Root approximation after max iterations: " << c << "\n";
}

bool BiSectionMethod::isConverged(double a, double b) {
    return  abs(b - a) / 2 < tolerance;
}

