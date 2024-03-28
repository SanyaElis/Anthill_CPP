#ifndef TASK_2_ANTHILL_H
#define TASK_2_ANTHILL_H

#include "Ant.h"
#include "QueenAnt.h"
#include "Worker.h"
#include "Soldier.h"
#include "Policeman.h"
#include "Pest.h"
#include "Larva.h"
#include <vector>

using namespace std;


extern int INITIAL_PEST_COUNT;
extern int INITIAL_WORKER_COUNT;
extern int INITIAL_POLICEMAN_COUNT;
extern int INITIAL_SOLDIER_COUNT;


class Anthill {

private:
    double numberOfFood;
    vector<Worker *> workers;
    vector<Soldier *> soldiers;
    vector<Policeman *> policeman;
    vector<Pest *> pests;
    vector<Larva *> larvae;
    QueenAnt *queenAnt;

    void feedEveryone();

    void createLarvae(int amountOfLarvae);

    void createPests(int amountOfPests);

    void createWorkers(int amountOfWorkers);

    void createPoliceman(int amountOfPoliceman);

    void createSoldiers(int amountOfSoldiers);

    void feedPests();

    template<typename T>
    void feedAnts(std::vector<T *> &ants);

    void killPests(int numberToKill);

    void hatchAntFromLarva();

public:

    Anthill(double food);

    void printState();

    void setQueenAnt(QueenAnt *queenAnt);

    void addAnt(Worker *newAnt);

    void addAnt(Soldier *newAnt);

    void addAnt(Policeman *newAnt);

    void oneTick();

    virtual ~Anthill();

    bool isAlive();

};


#endif
