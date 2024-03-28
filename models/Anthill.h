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

extern int LARVA_CONSUMED_FOOD;
extern int LARVA_BIRTH_COUNT;
extern int INITIAL_PEST_COUNT;


class Anthill {

private:
    double numberOfFood;
    int ticks = 0;
    vector<Worker *> workers;
    vector<Soldier *> soldiers;
    vector<Policeman *> policeman;
    vector<Pest *> pests;//todo добалять в конструкторе отдельный генератор
    vector<Larva *> larvae;//todo прописать добавление и вылупление (метод, который стучится к королеве)
    QueenAnt *queenAnt;

    void feedEveryone();

    void feedWorkers();

    void feedSoldiers();

    void feedPoliceman();

    void createLarvae(int amountOfLarvae);

    void createPests(int amountOfPests);

    void feedPests();

public:
    Anthill(double food);

    void printState();

    void setQueenAnt(QueenAnt *queenAnt);

    void addAnt(Worker *newAnt);

    void addAnt(Soldier *newAnt);

    void addAnt(Policeman *newAnt);

    void oneTick();//todo

};


#endif
