#include <iostream>
#include <math.h>
#include <string>
#include "NeuralNet.h"
#include "MNIST.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;

#define TEST_SIZE 10000
#define TRAIN_SIZE 60000

int main() {
    string trainSetName = "mnist_train.csv";
    CSVReader *reader = new CSVReader(trainSetName);
    MNISTDigit *test, *train;
    train = new MNISTDigit[TRAIN_SIZE];
    reader->readCSV(train, TRAIN_SIZE);
    
    return 0;
}