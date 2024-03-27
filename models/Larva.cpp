#include <iostream>
#include "Larva.h"

using namespace std;

Larva::Larva(int food, int ticks) : consumedFood(food), ticksToBurn(ticks) {}

bool Larva::timeToBurn() {
    return ticksToBurn <= ticksAlive;
}

void Larva::liveOneTick() {
    ticksAlive++;
}

int Larva::eat() {
    cout << "[log] Larva want to eat " << consumedFood << " pieces" << endl;
    return consumedFood;
}
