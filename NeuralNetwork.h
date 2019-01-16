#include <iostream>
#include "Layers.h"

class NeuralNetwork {

private:
    Layer *input, *output;
    Layer **layers;
    int layerCount;
public:

    NeuralNetwork(int numberOfLayers) {
        layers = new Layer*[numberOfLayers];
        layerCount = 0;
    }

    void addLayer(Dense newLayer) {
        layers[layerCount] = &newLayer;
        layerCount += 1;
    }

    void testAll() {
        int i;
        for (i = 0; i < layerCount; i++) {
            layers[i]->check();
        }
    }

    void build() {
        int i;
        input = layers[0];
        output = layers[layerCount - 1];
        for (i = 1; i < layerCount; i++) {
            layers[i]->setPrev(layers[i-1]);
            layers[i-1]->setNext(layers[i]);
        }
    }

    void train() {

    }
};