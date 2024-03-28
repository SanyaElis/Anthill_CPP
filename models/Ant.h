#ifndef TASK_2_ANT_H
#define TASK_2_ANT_H
#include <string>

using namespace std;

class Ant {
public:
    int consumedFood;
    Ant(int consumedFood);
    virtual ~Ant() {}
    virtual int eat() = 0;
    virtual string getType() = 0;
};


#endif //TASK_2_ANT_H
