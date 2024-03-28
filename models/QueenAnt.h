//
// Created by sanya on 21.03.2024.
//

#ifndef TASK_2_QUEENANT_H
#define TASK_2_QUEENANT_H

#include "Ant.h"

extern int WORKER_AIM;
extern int POLICEMAN_AIM;
extern int SOLDIER_AIM;
extern int WORKER_CONSUMED_FOOD;
extern int POLICEMAN_CONSUMED_FOOD;
extern int SOLDIER_CONSUMED_FOOD;
extern int ANT_QUEEN_CONSUMED_FOOD;
extern int LARVA_CONSUMED_FOOD;
extern int PEST_CONSUMED_FOOD;

extern int LARVA_BIRTH_COUNT;
extern int PEST_KILL_COUNT;
extern int COLLECTED_FOOD_COUNT;
extern float FOOD_INCREASE_PERCENTAGE;


class QueenAnt : public Ant {
private:
    int larvaCount;
public:
    QueenAnt(int consumedFood, int larvaCount);

    int eat() override;

    virtual ~QueenAnt();

    int getLarvaCount() const;

    Ant *hatchLarva(int workerCount, int soldierCount, int policemanCount);
};

#endif
