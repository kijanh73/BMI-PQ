#include <iostream>
#include <stdexcept>
#include "PQ.h"
#include <queue>

SortCriteria BMIAnalysis::currentSortCriteria = BMI;

bool PQ::IsFull() const {
    return false;
}
int PQ::GetLength() const {
    return length;
}

void PQ::MakeEmpty() {
    while (!PriorityQueue.empty()) {
        PriorityQueue.pop();
    }
}
void PQ::PutItem(BMIAnalysis item) {
    PriorityQueue.push(item);
}

bool PQ::HasNextItem() {
    return !PriorityQueue.empty();
}

BMIAnalysis PQ::GetNextItem() {
    BMIAnalysis nextItem = PriorityQueue.top();
    PriorityQueue.pop();
    return nextItem;
}

void PQ::PrintPriorityBMI() {

    std::priority_queue<BMIAnalysis> tempQueue = PriorityQueue;

    std::cout << "Priority Highest BMI: \n";
    while (!tempQueue.empty()) {
        BMIAnalysis curitem = tempQueue.top();
        std::cout << "BMI: " << curitem.bmi << "," << " Age: " << curitem.age << "," << " Height (M): " << curitem.height << "," << " Weight (KG): " << curitem.weight << std::endl;
        tempQueue.pop();
    }
    std::cout << std::endl;

    }

void PQ::PrintPriorityAGE() {

    std::priority_queue<BMIAnalysis> tempQueue = PriorityQueue;

    std::cout << "Priority Highest Age: \n";
    while (!tempQueue.empty()) {
        BMIAnalysis curitem = tempQueue.top();
        std::cout << "Age: " << curitem.age << "," << " BMI: " << curitem.bmi << "," << " Height (M): " << curitem.height << "," << " Weight (KG): " << curitem.weight << std::endl;
        tempQueue.pop();
    }
    std::cout << std::endl;

}

void PQ::PrintPriorityHEIGHT() {

    std::priority_queue<BMIAnalysis> tempQueue = PriorityQueue;

    std::cout << "Priority Highest Height: \n";
    while (!tempQueue.empty()) {
        BMIAnalysis curitem = tempQueue.top();
        std::cout << "Height (M): " << curitem.height << "," << " Age: " << curitem.age << "," << " BMI : " << curitem.bmi << "," << " Weight (KG): " << curitem.weight << std::endl;
        tempQueue.pop();
    }
    std::cout << std::endl;

}

void PQ::PrintPriorityWEIGHT() {

    std::priority_queue<BMIAnalysis> tempQueue = PriorityQueue;

    std::cout << "Priority Highest Weight: \n";
    while (!tempQueue.empty()) {
        BMIAnalysis curitem = tempQueue.top();
        std::cout << "Weight (KG): " << curitem.weight << "," << " Age: " << curitem.age << "," << " Height (M): " << curitem.height << "," << " BMI: " << curitem.bmi << std::endl;
        tempQueue.pop();
    }
    std::cout << std::endl;

}


PQ::PQ() {
    length = 0;
    currentPos = -1;
}

void PQ::SetSortCriteria(SortCriteria attribute) {
    currentSortCriteria = attribute;
}

