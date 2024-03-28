#ifndef TASK_2_SOLDIER_H
#define TASK_2_SOLDIER_H

#include "Ant.h"

class Soldier : public Ant {
public:
    int eat() override;

    Soldier(int consumedFood, int pestsKillCount);

    string getType() override;

    virtual ~Soldier();

    int getPestsKillCount() const;


private:
    int pestsKillCount;
};


#endif