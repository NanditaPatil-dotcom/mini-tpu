#include "matrix.h"

int main() {
    Matrix A(2, 3);
    Matrix B(3, 2);

    A.randomFill();
    B.randomFill();

    std::cout << "Matrix A:\n";
    A.print();

    std::cout << "\nMatrix B:\n";
    B.print();

    Matrix C1 = A.multiply(B);
    Matrix C2 = A.multiplyBlocked(B, 2);

    std::cout << "\nNaive:\n";
    C1.print();
    std::cout << "\nBlocked:\n";
    C2.print();

    return 0;
}