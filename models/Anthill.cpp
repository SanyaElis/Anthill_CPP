#include "Anthill.h"
#include <iostream>

Anthill::Anthill(double food) : numberOfFood(food) {
    createPests(INITIAL_PEST_COUNT);
}

void Anthill::printState() {
    cout << "==============================================" << endl;

    cout << "[log] anthill warehouse has " << numberOfFood << " pieces" << endl;
    cout << "[log] anthill has " << pests.size() << " pests" << endl;
    cout << "[log] anthill has " << workers.size() << " workers" << endl;
    cout << "[log] anthill has " << policeman.size() << " policeman" << endl;
    cout << "[log] anthill has " << soldiers.size() << " soldiers" << endl;
    cout << "[log] anthill has " << larvae.size() << " larvae" << endl;

    cout << "==============================================" << endl;
}

void Anthill::oneTick() {
    feedEveryone();

    for (Larva *larva: larvae) {
        larva->liveOneTick();
    }
    for (Worker *worker: workers) {
        numberOfFood += worker->getCollectedFoodCount();
    }
    for (Policeman *police: policeman) {
        numberOfFood *= police->getFoodIncreasePercentage();
    }

    createLarvae(queenAnt->getLarvaCount());

    for (Soldier *soldier: soldiers) {
        killPests(soldier->getPestsKillCount());
    }
    printState();
}

void Anthill::feedEveryone() {
    if (isAlive()) {
        cout << "[log] all ants dead " << endl;
        return;
    }
    //feed queen ant
    int needToEat = queenAnt->eat();
    if (numberOfFood - needToEat > 0) {
        numberOfFood -= needToEat;
        cout << "[log] queen ant eat " << needToEat << " pieces" << endl;
    } else {
        cout << "[log] queen didn't get enough food" << endl;
        numberOfFood = 0;
        delete queenAnt;
    }
    feedPests();

    for (int i = larvae.size() - 1; i >= 0; --i) {
        needToEat = larvae[i]->eat();
        if (numberOfFood - needToEat > 0) {
            numberOfFood -= needToEat;
            cout << "[log] larva eat " << needToEat << " pieces" << endl;
        } else {
            numberOfFood = 0;
            cout << "[log] larva didn't get enough food" << endl;
            delete larvae[i];
            larvae.erase(larvae.begin() + i);
        }
    }
    cout << "[log] pests are fed " << endl;
    feedAnts(workers);
    feedAnts(policeman);
    feedAnts(soldiers);
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

void Anthill::feedPests() {
    int needToEat;
    for (int i = pests.size() - 1; i >= 0; --i) {
        needToEat = pests[i]->stealFood();
        if (numberOfFood - needToEat > 0) {
            numberOfFood -= needToEat;
            cout << "[log] pest stole " << needToEat << " pieces" << endl;
        } else {
            numberOfFood = 0;
            cout << "[log] pest didn't get enough food" << endl;
            delete pests[i];
            pests.erase(pests.begin() + i);
        }
    }
    cout << "[log] pests are fed " << endl;
}

void Anthill::createLarvae(int amountOfLarvae) {
    for (int i = 0; i < amountOfLarvae; i++) {
        larvae.push_back(new Larva(LARVA_CONSUMED_FOOD, LARVA_BIRTH_COUNT));
    }
}

void Anthill::createPests(int amountOfPests) {
    for (int i = 0; i < amountOfPests; i++) {
        pests.push_back(new Pest(PEST_CONSUMED_FOOD));
    }
}

bool Anthill::isAlive() {
    return queenAnt == nullptr;
}

void Anthill::killPests(int numberToKill) {
    if (numberToKill < 0) {
        cout << "[error] number of pests to remove should be non-negative" << endl;
        return;
    }
    if (pests.empty()) {
        cout << "[log] all pests dead" << endl;
        return;
    }
    if (numberToKill > pests.size()) {
        numberToKill = (int) pests.size();
    }
    for (int i = 0; i < numberToKill; ++i) {
        delete pests.back();
        pests.pop_back();
    }

}

template<typename T>
void Anthill::feedAnts(vector<T *> &ants) {
    int needToEat;
    if (ants.empty()) {
        return;
    }
    for (int i = ants.size() - 1; i >= 0; --i) {
        needToEat = ants[i]->eat();
        if (numberOfFood - needToEat > 0) {
            numberOfFood -= needToEat;
            cout << "[log] " << ants[i]->getType() << " eat " << needToEat << " pieces" << endl;
        } else {
            numberOfFood = 0;
            cout << "[log] " << ants[i]->getType() << " didn't get enough food" << endl;
            delete ants[i];
            ants.erase(ants.begin() + i);
        }
    }
    if (!ants.empty()) {
        cout << "[log] " << ants[0]->getType() << " are fed" << endl;
    }
}





