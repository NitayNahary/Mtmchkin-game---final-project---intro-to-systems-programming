cmake_minimum_required(VERSION 3.20)
project(HW4)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(HW4
        Mtmchkin.h
        test.cpp
        utilities.cpp
        utilities.h Classes/Player.cpp Classes/Player.h Classes/Fighter.h Classes/Fighter.cpp Classes/Wizard.cpp Classes/Wizard.h Classes/Rouge.cpp Classes/Rouge.h Cards/Card.h Cards/Vampire.cpp Cards/Vampire.h Cards/Goblin.cpp Cards/Goblin.h Cards/Dragon.cpp Cards/Dragon.h Exception.h main.cpp Mtmchkin.cpp Queue.h Cards/Barfight.cpp Cards/Barfight.h Cards/Card.cpp Cards/Fairy.cpp Cards/Fairy.h Cards/Merchant.cpp Cards/Merchant.h Cards/Pitfall.cpp Cards/Pitfall.h Cards/Treasure.cpp Cards/Treasure.h)
