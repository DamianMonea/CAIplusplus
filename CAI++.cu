#include <iostream>
#include <math.h>
#include <string>
#include <Python.h>
#include <fstream>
#include <stdlib.h>
#include "NeuralNet.h"
#include "MNIST.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;

#define TEST_SIZE 10000
#define TRAIN_SIZE 60000

// namespace plt = matplotlibcpp;

int main() {
    ofstream command;
    ofstream content;
    command.open("COMMAND.txt");
    content.open("CONTENT.txt");
    char plotter[] = "util.py";
    FILE *fp;

    string trainSetName = "mnist_train.csv";

    CSVReader *reader = new CSVReader(trainSetName);
    MNISTDigit *test, *train;
    train = new MNISTDigit[TRAIN_SIZE];
    reader->readCSV(train, TRAIN_SIZE);

    command<<"DISPLAY_DIGIT";
    // content<< train[0].getLabel()<<",";
    for (int i = 0; i < 784; i++) {
        content<< train[0].getValues()[i] <<",";
    }

    // command.open("COMMAND.txt");
    // content.open("CONTENT.txt");
    // command<<"DISPLAY_DIGIT";
    // content<< train[2].getLabel<<",";
    // for (int i = 0; i < 784; i++) {
    //     content<< train[2].getValues()[i] <<",";
    // }
    
    return 0;
}