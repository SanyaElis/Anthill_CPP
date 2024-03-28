#include "Soldier.h"
#include <iostream>

using namespace std;


int Soldier::eat() {
    cout << "[log] Soldier want to eat " << consumedFood << " pieces" << endl;
    return consumedFood;
}


int Soldier::getPestsKillCount() const {
    return pestsKillCount;
}

Soldier::Soldier(int consumedFood, int pestsKillCount) : Ant(consumedFood), pestsKillCount(pestsKillCount) {}

Soldier::~Soldier() {
    cout << "[log] Soldier dead" << endl;
}

string Soldier::getType() {
    return "soldier";
}
