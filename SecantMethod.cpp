#include "SecantMethod.h"

double SecantMethod::evaluateEquation(double x) {
    // Evaluates the equation ax^2 + bx + c
    return coefA * x * x + coefB * x + coefC;
}

void SecantMethod::secantMethod() {
    // Get user input for coefficients
    std::cout << "Enter the coefficients for the quadratic equation (ax^2 + bx + c = 0):\n";
    std::cout << "a: "; std::cin >> coefA;
    std::cout << "b: "; std::cin >> coefB;
    std::cout << "c: "; std::cin >> coefC;

    // Get user input for initial guesses, tolerance, and maximum iterations
    std::cout << "Enter initial guesses x0 and x1:\n";
    std::cout << "x0: "; std::cin >> x0;
    std::cout << "x1: "; std::cin >> x1;

    std::cout << "Enter tolerance: "; std::cin >> tolerance;
    std::cout << "Enter maximum iterations: "; std::cin >> maxIterations;

    // Start finding the root
    findRoot();
}

void SecantMethod::findRoot() {
    double x2;
    int iteration = 0;

    while (iteration < maxIterations) {
        // Calculate next point x2 using the Secant Method formula
        x2 = x1 - evaluateEquation(x1) * ((x1 - x0) / (evaluateEquation(x1) - evaluateEquation(x0)));

        // Check for convergence
        if (std::abs(evaluateEquation(x2)) <= tolerance) {
            std::cout << "Root found at: " << x2 << " after " << iteration + 1 << " iterations.\n";
            return;
        }

        // Update guesses for the next iteration
        x0 = x1;
        x1 = x2;
        iteration++;
    }

    std::cout << "Root approximation after max iterations: " << x2 << "\n";
}
