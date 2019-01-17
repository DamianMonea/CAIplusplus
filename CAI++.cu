#include <iostream>
#include <math.h>
#include <string>
#include <Python.h>
#include <fstream>
#include <bits/stdc++.h> 
#include "NeuralNetwork.h"
#include "Objects.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;

#define TEST_SIZE 10000
#define TRAIN_SIZE 60000

int main() {
    ofstream content;
    char plotter[] = "util.py";    
    string trainSetName = "mnist_train.csv";

    CSVReader *reader = new CSVReader(trainSetName);
    MNISTDigit *test, *train;
    train = new MNISTDigit[TRAIN_SIZE];
    reader->readCSV(train, TRAIN_SIZE);
    char *digitPlot = new char[30];
    strcpy(digitPlot, "python util.py DISPLAY_DIGIT");

    NeuralNetwork *model = new NeuralNetwork(3);
    model->addLayer(Dense(784));
    model->addLayer(Dense(100));
    model->addLayer(Dense(10));
    model->build();
    model->testAll();
    model->train();

    // string runCommand;
    // int index;
    // int *values, i;
    // bool exit = false;
    // while(exit == false) {
    //     cin>>runCommand;
    //     if (runCommand.compare("DISPLAY_DIGIT") == 0) {
    //         cout<<"Index: ";
    //         cin>>index;
    //         values = train[index - 1].getValues();
    //         content.open("CONTENT.txt");
    //         for (i = 0; i < 784; i++) {
    //             content<<values[i]<<',';
    //         }
    //         content.close();
    //         system(digitPlot);
    //     }
    //     if (runCommand.compare("EXIT") == 0) {
    //         exit = true;
    //     }
    // }    
    
    return 0;
}