
#include "Fighter.h"

Fighter::Fighter(const std::string name)  : Player(name){}

int Fighter::getAttackStrength() const{
    return m_level + (2 * m_force) ;
}
std::string Fighter::getClass() const {
    return "Fighter";
}