#include <bits/stdc++.h>

#include "BiSectionMethod.h"
#include "FalsePositionMethod.h"
#include "SecantMethod.h"
#include "NewtonRaphsonMethod.h"
#include "RungeKutta.h"
#include "InverseMatrix.h"
#include "GaussEliminatioin.h"
#include "Jacobi_Iterative.h"
#include "LU_factorization.h"
#include "Jordan_Elimination.h"
#include "Gauss_Siedel.h"


using namespace std;

int main()
{
    char jump;
jump1:
    cout << "\t\t\t Numerical Methods " << endl;
    cout << "Choose options from below: " <<endl;
    cout << "1. Solve Linear Equations \t 2. Solve Non-Linear Equations \t 3. Solve Differential Equations \t 4. Matrix Inversion\n";


    int choice;

    cout << "=> ";
    cin >> choice;


    if (choice == 1)
    {
jump2:
        cout << "Choose a method: "<<endl;
        cout << "1. Jacobi iterative method \t 2. Gauss-Seidel iterative method \t 3. Gauss elimination"<<endl;
        cout << "4. Gauss-Jordan elimination \t 5. LU factorization"<<endl;

        int choice1;
        cout << "=> ";
        cin >> choice1;

        if (choice1 == 1)
        {
            // calling class
            // Jacobi-iterative jacobi
            // jacobi.jacobi_iterative();
        }
        else if (choice1 == 2)
        {
            // Calling Class
            // Gauss-Seidel-iterative gs-iter;
            // gs-iter.gauss_seidel_iterative();
        }
        else if (choice1 == 3)
        {
            // Calling Class
            // Gauss-elimination g-eli;
            // g-eli.gauss_elimination();
        }
        else if (choice1 == 4)
        {
            // Calling class
            // Gauss-Jordan-elimination gj-eli;
            // gj-eli.gauss_jordan_elimination();
        }
        else if (choice1 == 5)
        {
            // Calling Class
            // LU-factorization lu-facto;
            // lu-facto.lu_factorization();
        }
        else
        {
            cout << "Choose between 1, 2, 3, 4, 5 options only.";
            cout << "Do you want to continue? (y/n) : ";
            cin >> jump;
            if ( jump == 'y' || jump == 'Y')
                goto jump2;
        }
    }
    else if (choice == 2)
    {
jump3:
        cout << "Choose a method: "<<endl;
        cout << "1. Bi-section method \t 2. False position method"<<endl;
        cout << "3. Secant method \t 4. Newton-Raphson method"<<endl;
        int choice2;
        cout << "=> ";
        cin >> choice2;

        if (choice2 == 1)
        {
            // calling class
            BiSectionMethod bisec;
            bisec.bisectionMethod();
        }
        else if (choice2 == 2)
        {
            // Calling Class
            FalsePositionMethod falsePos;
            falsePos.falsePositionMethod();
        }
        else if (choice2 == 3)
        {
            // Calling Class
            SecantMethod secant;
            secant.secantMethod();
        }
        else if (choice2 == 4)
        {
            // Calling class
            NewtonRaphsonMethod newtonRaphson;
            newtonRaphson.newtonRaphsonMethod();
        }
        else
        {
            cout << "Choose between 1, 2, 3, 4 options only.";
            cout << "Do you want to continue? (y/n) : ";
            cin >> jump;
            if ( jump == 'y' || jump == 'Y')
                goto jump3;
        }
    }
    else if (choice == 3)
    {
jump4:
        cout << "Choose a method: "<<endl;
        cout << "1. Runge-Kutta method"<<endl;
        int choice3;
        cout << "=> ";
        cin >> choice3;

        if (choice3 == 1)
        {
            // Calling class
            RungeKutta rk;
            rk.getInput();
            rk.displayResult();
        }
        else
        {
            cout << "Choose Option 1 only.";
            cout << "Do you want to continue? (y/n) : ";
            cin >> jump;
            if ( jump == 'y' || jump == 'Y')
                goto jump4;
        }

    }
    else if (choice == 4)
    {
jump5:
        cout << "\t Matrix Inversion\n";

        // Calling Matrix inversion Class

        int n;
        cout << "Enter matrix size (n x n): ";
        cin >> n;

        InverseMatrix inversematrix(n, n);
        inversematrix.input();

        cout << "\nOriginal Matrix:" << endl;
        inversematrix.display();

        inversematrix.calculateInverse();

        cout << "Do you want to continue? (y/n) : ";
        cin >> jump;
        if ( jump == 'y' || jump == 'Y')
            goto jump5;
    }
    else
    {
        cout << "Choose between 1, 2, 3, 4 options only.";
        cout << "Do you want to continue? (y/n) : ";
        cin >> jump;
        if ( jump == 'y' || jump == 'Y')
            goto jump1;
        else
            return 0;
    }


    int ending;
    cout << "Enter 0 to exit and 1 to restart the program : ";
    cin >> ending;

    if (ending == 1)
        goto jump1;

    return 0;
}
