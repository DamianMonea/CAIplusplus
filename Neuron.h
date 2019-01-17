#include <iostream>

class Neuron {
private:
    float *incomingValues;
    float outGoingValue;
    float *weights;
    Neuron *nextNeurons;
    Neuron *prevNeurons;
public:

    Neuron() {
        nextNeurons = NULL;
        prevNeurons = NULL;
    }
    void setIncomingValuesCount(int n) {
        incomingValues = new float[n];
    }

    void addIncomingValue(int index, float value) {
        incomingValues[index] = value;
    }

    void setNextNeurons(Neuron *next) {
        nextNeurons = next;
    }

    void setPrevNeurons(Neuron *prev) {
        prevNeurons = prev;
    }
};