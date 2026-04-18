#include "matrix.h"
#include <cstdlib>

Matrix::Matrix(int r, int c) : rows(r), cols(c) {
    data.resize(r, std::vector<int>(c, 0));
}

void Matrix::randomFill(int min, int max) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            data[i][j] = min + rand() % (max - min + 1);
        }
    }
}

void Matrix::print() const {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << data[i][j] << " ";
        }
        std::cout << "\n";
    }
}

Matrix Matrix::multiply(const Matrix& other) const {
    if (cols != other.rows) {
        throw std::invalid_argument("Matrix dimensions mismatch");
    }

    Matrix result(rows, other.cols);

    // Naive triple loop , poor time complexity O(n^3)
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < other.cols; j++) {
            for (int k = 0; k < cols; k++) {
                result.data[i][j] += data[i][k] * other.data[k][j];
            }
        }
    }

    return result;
}