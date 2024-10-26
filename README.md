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
