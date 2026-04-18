#include "pe.h"

ProcessingElement::ProcessingElement() : a(0), b(0), acc(0) {}

void ProcessingElement::setInputs(int a_in, int b_in) {
    a = a_in;
    b = b_in;
}

void ProcessingElement::compute() {
    acc += a * b;  // MAC operation
}

int ProcessingElement::getResult() const {
    return acc;
}

void ProcessingElement::reset() {
    acc = 0;
}