#include "FalsePositionMethod.h"
using namespace std;

double FalsePositionMethod::evaluateEquation(double x) {
    // equation type ax^2 + bx + c
    return coefA * x * x + coefB * x + coefC;
}

void FalsePositionMethod::falsePositionMethod() {

     cout << "Enter the coefficients for the quadratic equation (ax^2 + bx + c = 0):\n";
     cout << "a: ";  cin >> coefA;
     cout << "b: ";  cin >> coefB;
     cout << "c: ";  cin >> coefC;


     cout << "Enter interval [a, b] for the root search:\n";
     cout << "a: ";  cin >> a;
     cout << "b: ";  cin >> b;

     cout << "Enter tolerance: ";  cin >> tolerance;
     cout << "Enter maximum iterations: ";  cin >> maxIterations;

    // initial interval function
    if (evaluateEquation(a) * evaluateEquation(b) >= 0) {
         cout << "Invalid interval: The function must have different signs at a and b.\n";
        return;
    }

    findRoot();
}

void FalsePositionMethod::findRoot() {
    double c = a;
    int iteration = 0;

    while (iteration < maxIterations) {
        // False Position formula
        c = b - (evaluateEquation(b) * (b - a)) / (evaluateEquation(b) - evaluateEquation(a));

        // convergence or exact root
        if ( abs(evaluateEquation(c)) <= tolerance) {
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

