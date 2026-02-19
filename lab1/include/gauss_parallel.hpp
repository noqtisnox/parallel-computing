//
// Created by nox on 2/18/2026.
//

#ifndef LAB1_GAUSS_PARALLEL_HPP
#define LAB1_GAUSS_PARALLEL_HPP

#include "matrix_utils.hpp"
#include <thread>

void eliminate_rows(Matrix& m, int pivot, int start_row, int end_row);
void solve_gauss_parallel(Matrix& m, int num_threads);

#endif //LAB1_GAUSS_PARALLEL_HPP