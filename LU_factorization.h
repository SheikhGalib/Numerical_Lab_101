#ifndef LU_FACTORIZATION_H
#define LU_FACTORIZATION_H

#include <vector>
#include <iostream>

void LU_Decomposition(const std::vector<std::vector<double>>& A,
                      std::vector<std::vector<double>>& L,
                      std::vector<std::vector<double>>& U);

std::vector<double> Forward_Substitution(const std::vector<std::vector<double>>& L,
                                         const std::vector<double>& b);

std::vector<double> Backward_Substitution(const std::vector<std::vector<double>>& U,
                                           const std::vector<double>& y);

#endif
