#include "BiSectionMethod.h"

double BiSectionMethod::evaluateEquation(double x) {
    // Evaluates the equation ax^2 + bx + c
    return coefA * x * x + coefB * x + coefC;
}

void BiSectionMethod::bisectionMethod() {
    // Get user input for coefficients
    std::cout << "Enter the coefficients for the quadratic equation (ax^2 + bx + c = 0):\n";
    std::cout << "a: "; std::cin >> coefA;
    std::cout << "b: "; std::cin >> coefB;
    std::cout << "c: "; std::cin >> coefC;

    // Get user input for interval, tolerance, and maximum iterations
    std::cout << "Enter interval [a, b] for the root search:\n";
    std::cout << "a: "; std::cin >> a;
    std::cout << "b: "; std::cin >> b;

    std::cout << "Enter tolerance: "; std::cin >> tolerance;
    std::cout << "Enter maximum iterations: "; std::cin >> maxIterations;

    // Validate initial interval for the function
    if (evaluateEquation(a) * evaluateEquation(b) >= 0) {
        std::cout << "Invalid interval: The function must have different signs at a and b.\n";
        return;
    }

    // Start finding the root
    findRoot();
}

void BiSectionMethod::findRoot() {
    double c = a;
    int iteration = 0;

    while (iteration < maxIterations) {
        c = (a + b) / 2;  // Midpoint

        // Check for convergence or exact root
        if (isConverged(a, b) || evaluateEquation(c) == 0.0) {
            std::cout << "Root found at: " << c << " after " << iteration + 1 << " iterations.\n";
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

    std::cout << "Root approximation after max iterations: " << c << "\n";
}

bool BiSectionMethod::isConverged(double a, double b) {
    return std::abs(b - a) / 2 < tolerance;
}

