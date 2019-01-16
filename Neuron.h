#include <iostream>

class Neuron {
private:
    float *incomingValues;
    float outGoingValue;
    float *weights;
    
public:
    void setIncomingValuesCount(int n) {
        incomingValues = new float[n];
    }
};