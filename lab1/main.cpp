#include "include/matrix_utils.hpp"
#include <iostream>
#include <chrono>
#include <thread>
#include <iomanip>

void solve_gauss_consecutive(Matrix& m);
void solve_gauss_parallel(Matrix& m, int num_threads);

int main() {
    const std::string filePath = "./data/input.txt";
    Matrix mSeq = read_matrix(filePath);
    Matrix mPar = read_matrix(filePath);

    const int n = mSeq.n;
    const int numThreads = std::thread::hardware_concurrency();

    std::cout << "--- Gauss Elimination Benchmark ---" << "\n";
    std::cout << "Matrix Size: " << n << "x" << n << "\n";
    std::cout << "Available Cores: " << numThreads << "\n\n";

    if (n <= 5) {
        std::cout << "Initial Matrix:\n";
        print_matrix(mSeq);
    }

    const auto start = std::chrono::high_resolution_clock::now();

    solve_gauss_consecutive(mSeq);
    std::vector<double> solSeq = back_substitution(mSeq);

    const auto end = std::chrono::high_resolution_clock::now();
    const std::chrono::duration<double, std::milli> durationSeq = end - start;

    const auto startP = std::chrono::high_resolution_clock::now();

    solve_gauss_parallel(mPar, numThreads);
    std::vector<double> solPar = back_substitution(mPar);

    auto endP = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> durationPar = endP - startP;

    if (n <= 5) {
        std::cout << "Solution (Sequential):\n";
        for (int i = 0; i < solSeq.size(); i++) std::cout << "x" << i << " = " << solSeq[i] << " ";
        std::cout << "\n";
    }

    std::cout << std::fixed << std::setprecision(4);
    std::cout << "\n--- Performance Results ---" << "\n";
    std::cout << "Sequential Time: " << durationSeq.count() << " ms" << "\n";
    std::cout << "Parallel Time:   " << durationPar.count() << " ms" << "\n";

    double speedup = durationSeq.count() / durationPar.count();
    std::cout << "Speedup Factor:  " << speedup << "x" << "\n";

    return 0;
}