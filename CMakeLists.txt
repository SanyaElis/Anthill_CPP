cmake_minimum_required(VERSION 3.21)
project(task_2)

set(CMAKE_CXX_STANDARD 14)

add_executable(task_2 params.cpp main.cpp models/QueenAnt.cpp models/QueenAnt.h models/Ant.cpp models/Ant.h models/Pest.cpp models/Pest.h models/Larva.cpp models/Larva.h models/Policeman.cpp models/Policeman.h models/Soldier.cpp models/Soldier.h models/Worker.cpp models/Worker.h models/Anthill.cpp models/Anthill.h tests/test.cpp tests/test.h)
