#include <iostream>
#include "models/Anthill.h"
#include "models/Ant.h"
#include "models/QueenAnt.h"

extern int ANT_QUEEN_CONSUMED_FOOD;
extern int LARVA_COUNT;
extern int INITIAL_FOOD;

Anthill *initialize() {
    Anthill *anthill = new Anthill(INITIAL_FOOD);
    QueenAnt *queenAnt = new QueenAnt(ANT_QUEEN_CONSUMED_FOOD, LARVA_COUNT);
    anthill->setQueenAnt(queenAnt);
    return anthill;
}

int main() {
    Anthill *anthill = initialize();

    int ticks;

    while (true) {

        std::cout << "Enter the number of ticks (enter 0 to exit): ";
        std::cin >> ticks;

        if (std::cin.fail()) {
            std::cout << "Input error! Please enter a number." << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        } else if (ticks == 0) {
            std::cout << "You entered 0. End of simulation" << std::endl;
            break;
        } else {
            std::cout << "You have entered the number of ticks: " << ticks << std::endl;
            for (int i = 0; i < ticks; ++i) {
                anthill->oneTick();
            }
        }
    }
    delete anthill;
    return 0;
}
