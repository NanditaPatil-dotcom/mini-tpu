#include "pe.h"

ProcessingElement::ProcessingElement() : a(0), b(0), acc(0) {}

void ProcessingElement::compute() {
    acc += a * b;
}