#include <iostream>
#include <cmath>
#include "RungeKutta.h"
using namespace std;

RungeKutta::RungeKutta() : x0(0), y0(0), x(0), h(0) {}

void RungeKutta::getInput() {
    cout << "Enter initial x0: ";
    cin >> x0;
    cout << "Enter initial y0: ";
    cin >> y0;
    cout << "Enter x at which to find y: ";
    cin >> x;
    cout << "Enter step size h: ";
    cin >> h;
}

double RungeKutta::func(double x, double y) {
    return x + y;
}

double RungeKutta::calculate() {
    int steps = (int)((x - x0) / h);
    for (int i = 0; i < steps; i++) {
        double k1 = h * func(x0, y0);
        double k2 = h * func(x0 + h / 2, y0 + k1 / 2);
        double k3 = h * func(x0 + h / 2, y0 + k2 / 2);
        double k4 = h * func(x0 + h, y0 + k3);
        y0 += (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        x0 += h;
    }
    return y0;
}

void RungeKutta::displayResult() {
    cout << "The value of y at x is: " << calculate() << endl;
}

