#include <iostream>
#include "models/Anthill.h"
#include "models/Ant.h"
#include "models/Worker.h"
#include "models/QueenAnt.h"
#include "models/Soldier.h"
#include "models/Policeman.h"

extern int ANT_QUEEN_CONSUMED_FOOD;
extern int LARVA_COUNT;
extern int INITIAL_FOOD;

Anthill *initialize() {
    Anthill *anthill = new Anthill(INITIAL_FOOD);
    QueenAnt *queenAnt = new QueenAnt(ANT_QUEEN_CONSUMED_FOOD, LARVA_COUNT);
    anthill->setQueenAnt(queenAnt);
    for (int i = 0; i < 5; ++i) {
        anthill->oneTick();
    }
    return anthill;
}

int main() {
    Anthill *anthill = initialize();

    for (int i = 0; i < 5; ++i) {
        anthill->oneTick();
    }
//    Ant* testHatch = queenAnt->hatchLarva(11, 9, 8);
//    Soldier *testWor = dynamic_cast<Soldier*>(testHatch);
//
//    cout << testWor;
    return 0;
}
