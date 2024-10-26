#include "NewtonRaphsonMethod.h"

double NewtonRaphsonMethod::evaluateEquation(double x) {
    // Evaluates the equation ax^2 + bx + c
    return coefA * x * x + coefB * x + coefC;
}

double NewtonRaphsonMethod::evaluateDerivative(double x) {
    // Evaluates the derivative of the equation: f'(x) = 2ax + b
    return 2 * coefA * x + coefB;
}

void NewtonRaphsonMethod::newtonRaphsonMethod() {
    // Get user input for coefficients
    std::cout << "Enter the coefficients for the quadratic equation (ax^2 + bx + c = 0):\n";
    std::cout << "a: "; std::cin >> coefA;
    std::cout << "b: "; std::cin >> coefB;
    std::cout << "c: "; std::cin >> coefC;

    // Get user input for initial guess, tolerance, and maximum iterations
    std::cout << "Enter initial guess x0: "; std::cin >> x0;
    std::cout << "Enter tolerance: "; std::cin >> tolerance;
    std::cout << "Enter maximum iterations: "; std::cin >> maxIterations;

    // Start finding the root
    findRoot();
}

void NewtonRaphsonMethod::findRoot() {
    double x1;
    int iteration = 0;

    while (iteration < maxIterations) {
        // Calculate next point x1 using the Newton-Raphson formula
        x1 = x0 - evaluateEquation(x0) / evaluateDerivative(x0);

        // Check for convergence
        if (std::abs(evaluateEquation(x1)) <= tolerance) {
            std::cout << "Root found at: " << x1 << " after " << iteration + 1 << " iterations.\n";
            return;
        }

        // Update the guess for the next iteration
        x0 = x1;
        iteration++;
    }

    std::cout << "Root approximation after max iterations: " << x1 << "\n";
}
