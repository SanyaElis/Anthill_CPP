#ifndef TASK_2_POLICEMAN_H
#define TASK_2_POLICEMAN_H

#include "Ant.h"
#include <string>

class Policeman : public Ant {
private:
    double foodIncreasePercentage;
public:
    Policeman(int consumedFood, double increasePercentage);

    int eat() override;

    string getType() override;

    double getFoodIncreasePercentage() const;

    virtual ~Policeman();
};


#endif //TASK_2_POLICEMAN_H
