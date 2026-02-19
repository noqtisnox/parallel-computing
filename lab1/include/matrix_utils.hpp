//
// Created by nox on 2/18/2026.
//

#ifndef LAB1_MATRIX_UTILS_HPP
#define LAB1_MATRIX_UTILS_HPP

#include <string>
#include <vector>

struct Matrix {
    int n;
    std::vector<std::vector<double>> data;
};

Matrix read_matrix(const std::string& filename);
void print_matrix(const Matrix& m);
std::vector<double> back_substitution(const Matrix& m);

#endif //LAB1_MATRIX_UTILS_HPP