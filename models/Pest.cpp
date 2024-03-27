#include <iostream>
#include "Pest.h"

using namespace std;

Pest::Pest(int food) : consumedFood(food){}

Pest::~Pest() {
    cout << "[log] Pest dead" << endl;
}

int Pest::stealFood() {
    cout << "[log] Pest want to steal " << consumedFood << " pieces" << endl;
    return consumedFood;
}

