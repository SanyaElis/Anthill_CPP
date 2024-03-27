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
#include <list>

using namespace std;


class Anthill {

private:
    float numberOfFood;
    int ticks = 0;
    vector<Worker *> workers;
    vector<Soldier *> soldiers;
    vector<Policeman *> policeman;
    vector<Pest *> pests;//todo добалять в конструкторе отдельный генератор
    list<Larva *> larvae;//todo прописать добавление и вылупление (метод, который стучится к королеве)
    QueenAnt *queenAnt;

    void feedEveryone();

public:
    Anthill(float food);

    void printState();

    void setQueenAnt(QueenAnt *queenAnt);

    void addAnt(Worker *newAnt);

    void addAnt(Soldier *newAnt);

    void addAnt(Policeman *newAnt);

    void oneTick();//todo

};


#endif
