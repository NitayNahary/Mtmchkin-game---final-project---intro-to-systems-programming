
#include "Pitfall.h"
static const std::string M_NAME = "Pitfall";

Pitfall::Pitfall() : m_isRogue(false){}

void Pitfall::applyEncounter(Player &player){
    m_isRogue = player.getClass() == "Rogue";
    if(!m_isRogue)
        player.damage(M_EFFECT_VALUE);
    printInfo(std::cout);
}

void Pitfall::printInfo(std::ostream& os) const {
    printPitfallMessage(m_isRogue);
}
