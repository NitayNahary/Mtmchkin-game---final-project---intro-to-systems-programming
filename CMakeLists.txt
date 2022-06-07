cmake_minimum_required(VERSION 3.21)
project(HW4)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(HW4
        Mtmchkin.h
        test.cpp
        utilities.cpp
        utilities.h Player.cpp Player.h Fighter.h Fighter.cpp Wizard.cpp Wizard.h Rogue.cpp Rouge.h Card.h Vampire.cpp Vampire.h Goblin.cpp Goblin.h Dragon.cpp Dragon.h Exception.h main.cpp Mtmchkin.cpp Queue.h Barfight.cpp Barfight.h Card.cpp Fairy.cpp Fairy.h Merchant.cpp Merchant.h Pitfall.cpp Pitfall.h Treasure.cpp Treasure.h)
