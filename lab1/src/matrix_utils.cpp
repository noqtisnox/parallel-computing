//
// Created by nox on 2/18/2026.
//

#include "../include/matrix_utils.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

Matrix read_matrix(const std::string &filename) {
    Matrix m;
    std::ifstream file(filename);
    std::string line, cell;

    while (std::getline(file, line)) {
        std::vector<double> row;
        std::stringstream line_stream(line);
        while (std::getline(line_stream, cell, ',')) {
            row.push_back(std::stod(cell));
        }
        m.data.push_back(row);
    }
    m.n = m.data.size();
    return m;
}

void print_matrix(const Matrix &m) {
    for (const auto& row : m.data) {
        for (const double val : row) std::cout << val << "\t";
        std::cout << std::endl;
    }
}

std::vector<double> back_substitution(const Matrix &m) {
    const int n = m.n;
    std::vector<double> x(n);
    for (int i = n - 1; i >= 0; i--) {
        double sum = 0;
        for (int j = i + 1; j < n; j++) {
            sum += m.data[i][j] * x[j];
        }
        x[i] = (m.data[i][n] - sum) / m.data[i][i];
    }
    return x;
}
