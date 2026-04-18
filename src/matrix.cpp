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

    // loop reordering for better cache performance
    for (int i = 0; i < rows; i++) {
        for (int k = 0; k < cols; k++) {
            int temp = data[i][k];  // cache-friendly reuse
            for (int j = 0; j < other.cols; j++) {
                result.data[i][j] += temp * other.data[k][j];
            }
        }
    }

    return result;
}

Matrix Matrix::multiplyBlocked(const Matrix& other, int blockSize) const { //optimisation 2 : tiling
    if (cols != other.rows) {
        throw std::invalid_argument("Matrix dimensions mismatch");
    }

    Matrix result(rows, other.cols);

    for (int i = 0; i < rows; i += blockSize) {
        for (int j = 0; j < other.cols; j += blockSize) {
            for (int k = 0; k < cols; k += blockSize) {

                for (int ii = i; ii < std::min(i + blockSize, rows); ii++) {
                    for (int kk = k; kk < std::min(k + blockSize, cols); kk++) {
                        int temp = data[ii][kk];
                        for (int jj = j; jj < std::min(j + blockSize, other.cols); jj++) {
                            result.data[ii][jj] += temp * other.data[kk][jj];
                        }
                    }
                }

            }
        }
    }

    return result;
}