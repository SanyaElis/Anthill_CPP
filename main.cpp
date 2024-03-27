#include <iostream>
#include "models/Anthill.h"
#include "models/Ant.h"
#include "models/Worker.h"
#include "models/QueenAnt.h"
#include "models/Soldier.h"
#include "models/Policeman.h"

void test(Worker *worker){
    cout << endl <<"Worker";
}

void test(QueenAnt *queenAnt){
    cout << "QueenAnt";
}

int main() {
    std::cout << "Hello, World!" << std::endl;
//    Ant ant1 = new QueenAnt(23, 34);
    Anthill* anthill = new Anthill(23);
    anthill->printState();
    anthill->addAnt(new Soldier(24, 10));
    anthill->addAnt(new Worker(22, 10));
    anthill->printState();
//    test(new Worker(24, 11));
//    test(wor);
    Ant* wor1 = new Worker(34, 34);
    QueenAnt *queenAnt = new QueenAnt(23,23);
    anthill->setQueenAnt(queenAnt);
    Ant* testHatch = queenAnt->hatchLarva(11, 9, 8);
    Soldier *testWor = dynamic_cast<Soldier*>(testHatch);
    delete wor1;
    cout << testWor;
    return 0;
}
