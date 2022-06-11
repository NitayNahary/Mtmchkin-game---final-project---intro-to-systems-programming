cmake_minimum_required(VERSION 3.20)
project(HW4)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(HW4
        Mtmchkin.h
        utilities.cpp
        utilities.h Players/Player.cpp Players/Player.h Players/Fighter.h Players/Fighter.cpp Players/Wizard.cpp Players/Wizard.h Players/Rogue.cpp Players/Rogue.h Cards/Card.h Cards/Vampire.cpp Cards/Vampire.h Cards/Goblin.cpp Cards/Goblin.h Cards/Dragon.cpp Cards/Dragon.h Exception.h main.cpp Mtmchkin.cpp Queue.h Cards/Barfight.cpp Cards/Barfight.h Cards/Card.cpp Cards/Fairy.cpp Cards/Fairy.h Cards/Merchant.cpp Cards/Merchant.h Cards/Pitfall.cpp Cards/Pitfall.h Cards/Treasure.cpp Cards/Treasure.h)
