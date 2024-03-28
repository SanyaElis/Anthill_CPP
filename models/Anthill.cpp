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

}

void Anthill::feedEveryone() {
    //feed queen ant
    if (numberOfFood <= 0){//todo kill everyone
        cout << "[log] all ants dead " << endl;
        return;
    }
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
            larvae.erase(larvae.begin() + i);  // Удаление из вектора
        }
    }
    cout << "[log] pests are fed " << endl;

    feedWorkers();
    feedPoliceman();
    feedSoldiers();


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

void Anthill::feedWorkers() {
    int needToEat;
    for (int i = workers.size() - 1; i >= 0; --i) {
        needToEat = workers[i]->eat();
        if (numberOfFood - needToEat > 0) {
            numberOfFood -= needToEat;
            cout << "[log] worker eat " << needToEat << " pieces" << endl;
        } else {
            numberOfFood = 0;
            cout << "[log] worker didn't get enough food" << endl;
            delete workers[i];
            workers.erase(workers.begin() + i);  // Удаление из вектора
        }
    }
    cout << "[log] worker are fed " << endl;
}

void Anthill::feedSoldiers() {
    int needToEat;
    for (int i = soldiers.size() - 1; i >= 0; --i) {
        needToEat = soldiers[i]->eat();
        if (numberOfFood - needToEat > 0) {
            numberOfFood -= needToEat;
            cout << "[log] soldier eat " << needToEat << " pieces" << endl;
        } else {
            numberOfFood = 0;
            cout << "[log] soldier didn't get enough food" << endl;
            delete soldiers[i];
            soldiers.erase(soldiers.begin() + i);
        }
    }
    cout << "[log] soldier are fed " << endl;

}

void Anthill::feedPoliceman() {
    int needToEat;
    for (int i = policeman.size() - 1; i >= 0; --i) {
        needToEat = policeman[i]->eat();
        if (numberOfFood - needToEat > 0) {
            numberOfFood -= needToEat;
            cout << "[log] policeman eat " << needToEat << " pieces" << endl;
        } else {
            numberOfFood = 0;
            cout << "[log] policeman didn't get enough food" << endl;
            delete policeman[i];
            policeman.erase(policeman.begin() + i);
        }
    }
    cout << "[log] policeman are fed " << endl;
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



