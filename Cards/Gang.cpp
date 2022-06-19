//
// Created by shach on 6/19/2022.
//

#include "Gang.h"

void Gang::printInfo() const{

}

void Gang::applyEncounter(Player &player) {

}

void Gang::pushBack(std::unique_ptr<Card> addToGang) {

}

bool Gang::open() const {
    return m_open;
}

Gang::Gang() {
    m_nextGangIndex = -1;
    m_open = true;

}

void Gang::close(){
    m_open = false;
}

bool Gang::isMonster() {
    return false;
}
