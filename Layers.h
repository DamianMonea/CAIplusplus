#include "Neuron.h"

using std::string;
using std::cout;
using std::endl;

enum class layerType{ input, hidden, output};

class Layer{

private:

public:
    virtual void test() { }

    virtual void setPrev(Layer *next) {}

    virtual void setNext(Layer *prev) {}

    virtual Layer* getPrev() { }
    
    virtual Layer* getNext() { }

    virtual void check() { }

    virtual Neuron* getNeurons() { }
};

class Dense : public Layer{
private:
    Layer *previous, *next;
    Neuron *neurons;
    int neuronCount;
public:

    string type = "Dense";
    Dense(int units) {
        neurons = new Neuron[units];
        previous = NULL;
        next = NULL;
    }

    Dense() {
        neurons = NULL;
        previous = NULL;
        next = NULL;
    }

    void test() {
        cout<<"This is a dense layer"<<endl;
    }

    void setNext(Layer *next) {
        int i;
        for (i = 0; i < neuronCount; i++) {
            this->neurons[i].setNextNeurons(next->getNeurons());
        }
        this->next = next;
    }

    void setPrev(Layer *prev) {
        int i;
        for (i = 0; i < neuronCount; i++) {
            this->neurons[i].setPrevNeurons(prev->getNeurons());
        }
        this->previous = prev;
    }

    Layer* getPrev() {
        return this->previous;
    }

    Layer* getNext() {
        return this->next;
    }

    Neuron* getNeurons() {
        return neurons;
    }

    void check() {
        if (previous != NULL) {
            cout<< "Previous: ";
            previous->test();
        }
        test();
        if (next != NULL) {
            cout<< "Next: ";
            next->test(); 
        }

        cout<<endl;
    }
};

class Activation : public Layer {

private:

public:

};