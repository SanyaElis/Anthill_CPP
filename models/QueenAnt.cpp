#include <iostream>
#include "QueenAnt.h"
#include "Worker.h"
#include "Soldier.h"
#include "Policeman.h"

using namespace std;


int QueenAnt::eat() {
    cout << "[log] Queen want to eat " << consumedFood << " pieces" << endl;
    return consumedFood;
}

QueenAnt::QueenAnt(int consumedFood, int larvaCount) : Ant(consumedFood), larvaCount(larvaCount) {}

int QueenAnt::getLarvaCount() const {
    return larvaCount;
}

Ant *QueenAnt::hatchLarva(int workerCount, int soldierCount, int policemanCount) {//todo написать пропорцию
    double koefWorker = (double) workerCount / WORKER_AIM;
    double koefSoldier = (double) soldierCount / SOLDIER_AIM;
    double koefPoliceman = (double) policemanCount / POLICEMAN_AIM;
    if (koefWorker <= koefPoliceman && koefWorker <= koefSoldier) {
        return new Worker(WORKER_CONSUMED_FOOD, COLLECTED_FOOD_COUNT);
    }
    if (koefPoliceman <= koefWorker && koefPoliceman <= koefSoldier) {
        return new Policeman(POLICEMAN_CONSUMED_FOOD, FOOD_INCREASE_PERCENTAGE);
    }
    if (koefSoldier <= koefPoliceman && koefSoldier <= koefWorker) {
        return new Soldier(SOLDIER_CONSUMED_FOOD, PEST_KILL_COUNT);
    }
    return new Worker(WORKER_CONSUMED_FOOD, COLLECTED_FOOD_COUNT);
}

QueenAnt::~QueenAnt() {
    cout << "[log] Queen dead" << endl;
}

