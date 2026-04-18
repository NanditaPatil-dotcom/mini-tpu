#ifndef SYSTOLIC_H
#define SYSTOLIC_H

#include <vector>
#include "pe.h"
#include "matrix.h"

class SystolicArray {
public:
    int size;
    std::vector<std::vector<ProcessingElement>> grid;


    SystolicArray(int n);
    void step(); //simulate one clock cycle 

    Matrix run(const Matrix& A, const Matrix& B);
};

#endif