#ifndef LU_FACTORIZATION_H
#define LU_FACTORIZATION_H


#include <vector>
#include <iostream>

class LUDecomposition {
public:
    LUDecomposition(const std::vector<std::vector<double>>& matrix);

    void decompose();
    std::vector<double> solve(const std::vector<double>& b);
    void printL() const;
    void printU() const;

private:
    std::vector<std::vector<double>> A;
    std::vector<std::vector<double>> L;
    std::vector<std::vector<double>> U;

    std::vector<double> forwardSubstitution(const std::vector<double>& b) const;
    std::vector<double> backwardSubstitution(const std::vector<double>& y) const;
};

#endif
