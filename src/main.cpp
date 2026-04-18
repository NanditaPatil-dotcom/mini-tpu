#include <iostream>
#include "matrix.h"
#include "systolic.h"


int main() {
    int n = 2;

    Matrix A(n, n);
    Matrix B(n, n);

    A.randomFill();
    B.randomFill();

    std::cout << "Matrix A:\n";
    A.print();

    std::cout << "\nMatrix B:\n";
    B.print();

    // Naive result
    Matrix C1 = A.multiply(B);

    // Systolic result
    SystolicArray sa(n);
    Matrix C2 = sa.run(A, B);

    std::cout << "\nNaive Result:\n";
    C1.print();

    std::cout << "\nSystolic Result:\n";
    C2.print();

    return 0;
}