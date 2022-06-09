cmake_minimum_required(VERSION 3.20)
project(HW4)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(HW4
        Mtmchkin.h
        utilities.cpp
        utilities.h Players/Player.cpp Players/Player.h Players/Fighter.h Players/Fighter.cpp Players/Wizard.cpp Players/Wizard.h Players/Rogue.cpp Players/Rogue.h Cards/nonBattleMonsters/Card.h Cards/battleMonsters/Vampire.cpp Cards/battleMonsters/Vampire.h Cards/battleMonsters/Goblin.cpp Cards/battleMonsters/Goblin.h Cards/battleMonsters/Dragon.cpp Cards/battleMonsters/Dragon.h Exception.h main.cpp Mtmchkin.cpp Queue.h Cards/nonBattleMonsters/Barfight.cpp Cards/nonBattleMonsters/Barfight.h Cards/nonBattleMonsters/Card.cpp Cards/nonBattleMonsters/Fairy.cpp Cards/nonBattleMonsters/Fairy.h Cards/nonBattleMonsters/Merchant.cpp Cards/nonBattleMonsters/Merchant.h Cards/nonBattleMonsters/Pitfall.cpp Cards/nonBattleMonsters/Pitfall.h Cards/nonBattleMonsters/Treasure.cpp Cards/nonBattleMonsters/Treasure.h SmartPtr.h)
