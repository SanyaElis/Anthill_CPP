#ifndef TASK_2_WORKER_H
#define TASK_2_WORKER_H

#include "Ant.h"


class Worker : public Ant {
public:
    Worker(int consumedFood, int collectedFoodCount);

    virtual ~Worker();

    string getType() override;

    int getCollectedFoodCount() const;

    int eat() override;

private:
    int collectedFoodCount;
};


#endif
