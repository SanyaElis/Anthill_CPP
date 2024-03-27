#ifndef TASK_2_POLICEMAN_H
#define TASK_2_POLICEMAN_H

#include "Ant.h"

class Policeman : public Ant {
private:
    double foodIncreasePercentage;
public:
    Policeman(int consumedFood, double increasePercentage);

    int eat() override;

    virtual ~Policeman();

    double getFoodIncreasePercentage() const;
};


#endif //TASK_2_POLICEMAN_H
