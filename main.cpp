#include "PQ.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

std::vector<BMIAnalysis> csvtoVector(string csvfile) {
    std::vector<BMIAnalysis> data;
    ifstream ReadFile(csvfile);
    string line, curvalue;
    getline(ReadFile, line);
    while (getline(ReadFile,line)) {
        stringstream ss(line);
        int fielditer=0;
        BMIAnalysis newrec;
        while(getline(ss, curvalue, ',')){
            switch (fielditer) {
                case 0: newrec.age=stoi(curvalue); break;
                case 1: newrec.height=stod(curvalue); break;
                case 2: newrec.weight=stod(curvalue); break;
                case 3: newrec.bmi=stod(curvalue); break;
            }
            fielditer++;
        }
        data.push_back(newrec);
    }
    return data;
}

int main(int argc, char** argv) {
    std::vector<BMIAnalysis> data = csvtoVector("bmi.csv");

    int userChoice;

    std::cout << "Choose an option:" << std::endl;
    std::cout << "1. Print by BMI" << std::endl;
    std::cout << "2. Print by Age" << std::endl;
    std::cout << "3. Print by Height" << std::endl;
    std::cout << "4. Print by Weight" << std::endl;

    std::cout << "Enter your choice (1-4): ";
    std::cin >> userChoice;

    SortCriteria chosenCriteria;

    switch (userChoice) {
        case 1:
            chosenCriteria = BMI;
            break;
        case 2:
            chosenCriteria = AGE;
            break;
        case 3:
            chosenCriteria = HEIGHT;
            break;
        case 4:
            chosenCriteria = WEIGHT;
            break;
        default:
            std::cout << "Invalid choice. Please enter a number between 1 and 4." << std::endl;
            return 1;
    }


    BMIAnalysis::SetSortCriteria(chosenCriteria);

    PQ BMIAnalysis;
    for (const auto& item : data) {
        BMIAnalysis.PutItem(item);
    }

    switch (chosenCriteria) {
        case BMI:
            BMIAnalysis.PrintPriorityBMI();
            break;
        case AGE:
            BMIAnalysis.PrintPriorityAGE();
            break;
        case HEIGHT:
            BMIAnalysis.PrintPriorityHEIGHT();
            break;
        case WEIGHT:
            BMIAnalysis.PrintPriorityWEIGHT();
            break;
    }

    return 0;
}