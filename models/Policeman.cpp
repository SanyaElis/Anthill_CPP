#include "Policeman.h"
#include <iostream>

using namespace std;

Policeman::Policeman(int consumedFood, double increasePercentage) : Ant(consumedFood),
                                                                    foodIncreasePercentage(increasePercentage) {}

int Policeman::eat() {
    cout << "[log] Policeman want to eat " << consumedFood << " pieces" << endl;
    return consumedFood;
}

double Policeman::getFoodIncreasePercentage() const {
    return foodIncreasePercentage;
}

Policeman::~Policeman() {
    cout << "[log] Policeman dead" << endl;
}

string Policeman::getType() {
    return "policeman";
}

