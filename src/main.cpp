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

    Matrix C = A.multiply(B);

    std::cout << "\nResult (A x B):\n";
    C.print();

    return 0;
}