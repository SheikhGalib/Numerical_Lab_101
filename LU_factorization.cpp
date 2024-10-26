#include "LU_factorization.h"

using namespace std;

void LU_Decomposition(const vector<vector<double>>& A,
                      vector<vector<double>>& L,
                      vector<vector<double>>& U)
{
    int n = A.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                L[i][j] = 1.0;
            }
            else
            {
                L[i][j] = 0.0;
            }
            U[i][j] = A[i][j];
        }
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = k + 1; i < n; i++)
        {
            L[i][k] = U[i][k] / U[k][k];

            for (int j = k; j < n; j++)
            {
                U[i][j] -= L[i][k] * U[k][j];
            }
        }
    }
}

vector<double> Forward_Substitution(const vector<vector<double>>& L,
                                     const vector<double>& b)
{
    int n = L.size();
    vector<double> y(n);

    for (int i = 0; i < n; i++)
    {
        y[i] = b[i];

        for (int j = 0; j < i; j++)
        {
            y[i] -= L[i][j] * y[j];
        }
    }
    return y;
}

vector<double> Backward_Substitution(const vector<vector<double>>& U,
                                      const vector<double>& y)
{
    int n = U.size();
    vector<double> x(n);

    for (int i = n - 1; i >= 0; i--)
    {
        x[i] = y[i];
        for (int j = i + 1; j < n; j++)
        {
            x[i] -= U[i][j] * x[j];
        }

        x[i] /= U[i][i];
    }
    return x;
}
