#ifndef TASK_2_LARVA_H
#define TASK_2_LARVA_H


class Larva {
public:
    Larva(int food, int ticks);

    void liveOneTick();

    int eat();

    bool timeToBurn();
private:
    int consumedFood;

    int ticksToBurn;

    int ticksAlive = 0;
};


#endif
