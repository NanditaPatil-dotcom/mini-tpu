#ifndef PE_H
#define PE_H

class ProcessingElement {
public:
    int a, b, acc; //MAC unit

    ProcessingElement();

    void setInputs(int a_in, int b_in);
    void compute();

    int getResult() const;
    void reset();
};

#endif