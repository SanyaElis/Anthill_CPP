//
// Created by sanya on 26.03.2024.
//
#include <iostream>
#include "Worker.h"

using namespace std;


int Worker::eat() {
    return consumedFood;
}

Worker::Worker(int consumedFood, int collectedFoodCount) : Ant(consumedFood), collectedFoodCount(collectedFoodCount) {}

int Worker::getCollectedFoodCount() const {
    return collectedFoodCount;
}

Worker::~Worker() {
    cout << "[log] Worker dead" << endl;
}

string Worker::getType() {
    return "worker";
}



