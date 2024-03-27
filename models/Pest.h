#ifndef TASK_2_PEST_H
#define TASK_2_PEST_H


class Pest {
public:
    Pest(int food);

    int stealFood();

    virtual ~Pest();

private:
    int consumedFood;
};

#endif
