#include <iostream>
#include "pe.h"

int main() {
    ProcessingElement pe;

    // simulate multiple cycles
    pe.setInputs(2, 3);
    pe.compute();   // acc = 6

    pe.setInputs(4, 5);
    pe.compute();   // acc = 6 + 20 = 26

    std::cout << "Accumulated Result: " << pe.getResult() << std::endl;

    return 0;
}