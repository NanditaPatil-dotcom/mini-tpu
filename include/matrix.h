#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <iostream>

class Matrix {
public:
    int rows, cols;
    std::vector<std::vector<int>> data; //not cache friendly 

    Matrix(int r, int c);
    void randomFill(int min = 0, int max = 5);
    void print() const;

    Matrix multiply(const Matrix& other) const;
    Matrix multiplyBlocked(const Matrix& other, int blockSize) const;
};

#endif