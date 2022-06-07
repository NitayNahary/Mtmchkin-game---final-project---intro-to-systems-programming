
#include "Merchant.h"

void Merchant::applyEncounter(Player &player) {
    printMerchantInitialMessageForInteractiveEncounter(std::cout, player.getName(), player.getCoins());
    m_buyerName = player.getName();
    getIntInputNumber(m_buy, 0, 2);
    bool hadMoney;
    switch(m_buy){
        case M_BUY_FORCE:
            if(player.pay(M_FORCE_COST)){
                player.strengthen();
                hadMoney = true;
            }
            break;
        case M_BUY_HP:
            if(player.pay(M_HP_COST)){
                player.heal(M_ITEM_VALUE);
                hadMoney = true;
            }
            break;
        case M_BUY_NOTHING:
            hadMoney = true;
            break;
        default:
            //throw
            ;
    }
    if(!hadMoney) {
        printMerchantInsufficientCoins(std::cout);
    }
}

void Merchant::printInfo(std::ostream& os) const {
    int spent = 0;
    switch(m_buy){
        case M_BUY_FORCE:
            spent = M_FORCE_COST;
            break;
        case M_BUY_HP:
            spent = M_HP_COST;
            break;
        default:
            ;
    }
    // printMerchantSummary(os, m_buyerName, m_buy, spent);
}
