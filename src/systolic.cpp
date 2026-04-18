#include "systolic.h"
#include <iostream>


SystolicArray::SystolicArray(int n) : size(n) {
    grid.resize(n, std::vector<ProcessingElement>(n));
}

//one cycle : each PE computes
void SystolicArray::step() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            grid[i][j].compute();
        }
    }
}


// Run full multiplication
Matrix SystolicArray::run(const Matrix& A, const Matrix& B) {
    Matrix result(size, size);

    // Reset all PEs
    for (auto& row : grid)
        for (auto& pe : row)
            pe.reset();

    // Total cycles needed
    int cycles = 2 * size - 1;

    for (int t = 0; t < 2 * size; t++) {

    // 1️⃣ Compute current state
    step();

    // 2️⃣ Shift A → right
    for (int i = 0; i < size; i++) {
        for (int j = size - 1; j > 0; j--) {
            grid[i][j].a = grid[i][j - 1].a;
        }
    }

    // 3️⃣ Shift B ↓ down
    for (int j = 0; j < size; j++) {
        for (int i = size - 1; i > 0; i--) {
            grid[i][j].b = grid[i - 1][j].b;
        }
    }

    // 4️⃣ Inject A diagonally
    for (int i = 0; i < size; i++) {
        int k = t - i;
        if (k >= 0 && k < size) {
            grid[i][0].a = A.data[i][k];
        } else {
            grid[i][0].a = 0;
        }
    }

    // 5️⃣ Inject B diagonally
    for (int j = 0; j < size; j++) {
        int k = t - j;
        if (k >= 0 && k < size) {
            grid[0][j].b = B.data[k][j];
        } else {
            grid[0][j].b = 0;
        }
    }
}

    // Collect results
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result.data[i][j] = grid[i][j].getResult();
        }
    }

    return result;
}