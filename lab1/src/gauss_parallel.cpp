//
// Created by nox on 2/18/2026.
//

#include "../include/gauss_parallel.hpp"
#include <thread>

void eliminate_rows(Matrix &m, const int pivot, const int start_row, const int end_row) {
    const int n = m.n;
    for (int k = start_row; k < end_row; k++) {
        const double factor = m.data[k][pivot] / m.data[pivot][pivot];
        for (int j = pivot; j <= n; j++) {
            m.data[k][j] -= factor * m.data[pivot][j];
        }
    }
}

void solve_gauss_parallel(Matrix& m, const int num_threads) {
    int n = m.n;

    for (int i = 0; i < n; i++) {
        std::vector<std::thread> threads;
        int remainingRows = n - (i + 1);

        if (remainingRows <= 0) continue;

        // Determine how many rows each thread handles
        int rowsPerThread = remainingRows / num_threads;
        int extraRows = remainingRows % num_threads;

        int currentStart = i + 1;
        for (int t = 0; t < num_threads; t++) {
            int workSize = rowsPerThread + (t < extraRows ? 1 : 0);
            if (workSize > 0) {
                threads.emplace_back(eliminate_rows, std::ref(m), i, currentStart, currentStart + workSize);
                currentStart += workSize;
            }
        }

        // Join threads before moving to the next pivot row
        for (auto& th : threads) {
            th.join();
        }
    }
}