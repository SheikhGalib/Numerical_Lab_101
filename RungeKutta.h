#ifndef RUNGEKUTTA_H
#define RUNGEKUTTA_H

class RungeKutta {
private:
    double x0, y0, x, h;

public:
    // Constructor
    RungeKutta();

    // Member functions
    void getInput();
    double func(double x, double y);
    double calculate();
    void displayResult();
};

#endif

