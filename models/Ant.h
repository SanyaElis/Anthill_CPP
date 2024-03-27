#ifndef TASK_2_ANT_H
#define TASK_2_ANT_H


class Ant {
public:
    int consumedFood;
    Ant(int consumedFood);
    virtual ~Ant() {}
    virtual int eat() = 0;
};


#endif //TASK_2_ANT_H
