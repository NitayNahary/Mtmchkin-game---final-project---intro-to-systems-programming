#include "Fighter.h"
#include <ostream>

Fighter::Fighter(const char *name)  : Player(name){}

int Fighter::getAttackStrength() const{
    return m_level + (2 * m_force) ;
}
string Fighter::getClass() const {
    return "Fighter";
}