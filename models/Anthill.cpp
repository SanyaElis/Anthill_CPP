#include "Anthill.h"
#include <iostream>

Anthill::Anthill(float food) : numberOfFood(food) {

}

void Anthill::printState() {
    cout << "==============================================" << endl;

    cout << "[log] warehouse has " << numberOfFood << " pieces" << endl;
    cout << "[log] anthill has " << pests.size() << " pests" << endl;
    cout << "[log] anthill has " << workers.size() << " workers" << endl;
    cout << "[log] anthill has " << policeman.size() << " policeman" << endl;
    cout << "[log] anthill has " << soldiers.size() << " soldiers" << endl;

    cout << "==============================================" << endl;
}

void Anthill::oneTick() {
    //todo цикл по муравьям и паразитам и личинкам
}

void Anthill::feedEveryone() {
    if (numberOfFood < 0){
        cout << "all dead";
    }
}

void Anthill::setQueenAnt(QueenAnt *queenAnt) {
    Anthill::queenAnt = queenAnt;
    cout << "[log] queen got into the anthill" << endl;
}

void Anthill::addAnt(Worker *newAnt) {
    if (newAnt == nullptr) {
        cout << "[error] You didn't hand over the worker" << endl;
        return;
    }
    workers.push_back(newAnt);
    cout << "[log] worker got into the anthill" << endl;
}

void Anthill::addAnt(Soldier *newAnt) {
    if (newAnt == nullptr) {
        cout << "[error] You didn't hand over the soldier" << endl;
        return;
    }
    soldiers.push_back(newAnt);
    cout << "[log] soldier got into the anthill" << endl;
}

void Anthill::addAnt(Policeman *newAnt) {
    if (newAnt == nullptr) {
        cout << "[error] You didn't hand over the policeman" << endl;
        return;
    }
    policeman.push_back(newAnt);
    cout << "[log] policeman got into the anthill" << endl;
}

