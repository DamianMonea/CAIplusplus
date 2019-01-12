#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <fstream>

using namespace std;

class MNISTDigit {

private:
    int label;
    int *values;

public:
    MNISTDigit() {
        values = new int[784];
    }

    int getLabel() {
        return label;
    }

    void setLabel(int newLabel) {
        label = newLabel;
    }

    int* getValues() {
        return values;
    }

    void setValues(int values[]) {
        int i;
        for (i = 1; i < 285; i++)
            this->values[i - 1] = values[i - 1];
    }
};

class CSVReader {

private:
    string source;
public:
    CSVReader(string filename) {
        source = filename;
    }

    void readCSV(MNISTDigit *destination, int destSize) {
        ifstream in(source);
        string line;    
        MNISTDigit aux;
        int i = 0;
        int label = 0;
        int j = 0;
        int auxNr = 0;
        int numbers[784];
        int lineIndex = 0;
        while (in>>line) {
            i = 0;
            label = 0;
            while(line[i] != ',') {
                label = label * 10 + (line[i] - '0');
                i++;
            }
            destination[lineIndex].setLabel(label);
            j = 0;
            auxNr = 0;
            while (line[i] != '\0') {
                if (line[i] != ',') {
                    auxNr = auxNr * 10 + (line[i] - '0');
                } else {
                    numbers[j] = auxNr;
                    auxNr = 0;
                    j++;
                }
                i++;
            }
            destination[lineIndex].setValues(numbers);
            lineIndex += 1;
        }
    }
};