# Numerical_Lab_101
This is a repository with the project files of assignment to make a functioning Equation Solving Program.
# Numerical Methods Solver

This project is an application for solving mathematical equations and systems using several numerical methods. It includes solutions for **linear equations**, **non-linear equations**, and **differential equations**, as well as functionality for **matrix inversion**. The algorithms implemented are efficient for systems up to 5 equations and are ideal for applications in scientific computing.

## Table of Contents
- [Algorithms](#algorithms)
  - [Solution of Linear Equations](#solution-of-linear-equations)
  - [Solution of Non-linear Equations](#solution-of-non-linear-equations)
  - [Solution of Differential Equations](#solution-of-differential-equations)
  - [Matrix Inversion](#matrix-inversion)
- [Examples](#examples)
- [Compilation and Usage](#compilation-and-usage)

## Algorithms

### Solution of Linear Equations
The following methods are implemented for solving systems of linear equations (with a minimum of 5 equations):
1. **Jacobi Iterative Method**: Iterative method based on approximating solutions using initial guesses.
2. **Gauss-Seidel Iterative Method**: Modified Jacobi method that improves convergence by using updated values within iterations.
3. **Gauss Elimination**: Direct method of transforming the matrix into an upper triangular matrix to solve for variables.
4. **Gauss-Jordan Elimination**: Further refinement of Gauss Elimination that reduces the matrix to row echelon form.
5. **LU Factorization**: Factorizes the matrix into a product of a lower and an upper triangular matrix, useful for solving multiple right-hand sides.

### Solution of Non-linear Equations
For non-linear equations (like polynomials or transcendental equations), the following root-finding methods are provided:
1. **Bisection Method**: A bracketing method that narrows down the interval containing the root by repeatedly bisecting it.
2. **False Position Method**: Similar to Bisection but more efficient, using the function values to estimate the root position.
3. **Secant Method**: Non-bracketing method that uses two initial guesses and does not require derivative calculation.
4. **Newton-Raphson Method**: An iterative approach that requires the function's derivative, known for fast convergence near the root.

### Solution of Differential Equations
For solving first-order ordinary differential equations:
1. **Runge-Kutta Method (4th Order)**: An efficient method for approximating solutions to ODEs. It provides high accuracy with a reasonable computational cost.

### Matrix Inversion
A matrix inversion functionality is provided, using the Gauss-Jordan method to invert a square matrix. This is helpful in many linear algebra applications.

## Examples

Here are some example equations and instructions on how to use the application to solve them.

### Linear Equation Example (Gauss Elimination)
Given a system:

3x + 4y + 2z = 1 <br>
2x + y + 3z = 2 <br>
x + 5y + 2z = 3 <br>

To solve, input the coefficients and constants into the system when prompted, and the application will output solutions using your selected method.

### Non-linear Equation Example (Newton-Raphson)
Solve \( f(x) = 3x^2 + 2x - 5 \) using Newton-Raphson.
1. Input the coefficients as `a=3`, `b=2`, `c=-5`.
2. Set an initial guess, tolerance, and maximum iterations when prompted.
3. The application outputs the approximate root of \( f(x) = 0 \).

### Differential Equation Example (Runge-Kutta)
For an ODE \( y' = x + y \) with \( y(0) = 1 \):
1. Input initial values for `x0`, `y0`, the desired `x` at which to find `y`, and a step size `h`.
2. The application will output the value of \( y \) at the specified `x`.

## Compilation and Usage

### Using `g++` Command
clone this git repository. then going to the folder that has these files. Open Command line / terminal.
To compile and run the application from the command line using `g++`:
```bash
g++ main.cpp BiSectionMethod.cpp FalsePositionMethod.cpp Gauss_Siedel.cpp GaussEliminatioin.cpp InverseMatrix.cpp Jacobi_Iterative.cpp Jordan_Elimination.cpp LU_factorization.cpp NewtonRaphsonMethod.cpp RungeKutta.cpp SecantMethod.cpp -o numerical
```
```bash
./numerical
```

### Using Code::Blocks
1. Open `Code::Blocks`.
2. Import the project file via git, set up the `main.cpp` as the entry point, and build the project.


