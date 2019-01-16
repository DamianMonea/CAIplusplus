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
        previous = NULL;
        next = NULL;
    }

    void test() {
        cout<<"This is a dense layer"<<endl;
    }

    void setNext(Layer *next) {
        this->next = next;
    }

    void setPrev(Layer *prev) {
        this->previous = prev;
    }

    Layer* getPrev() {
        return this->previous;
    }

    Layer* getNext() {
        return this->next;
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