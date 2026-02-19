//
// Created by nox on 2/18/2026.
//

#include "../include/gauss_consecutive.hpp"

void solve_gauss_consecutive(Matrix &m) {
    const int n = m.n;

    for (int i = 0; i < n; i++) {
        for (int k = i + 1; k < n; k++) {
            const double factor = m.data[k][i] / m.data[i][i];
            for (int j = i; j <= n; j++) { // j <= n to include the result column
                m.data[k][j] -= factor * m.data[i][j];
            }
        }
    }
}
