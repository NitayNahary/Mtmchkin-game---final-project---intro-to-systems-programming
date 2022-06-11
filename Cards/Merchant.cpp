
#include "Merchant.h"

Merchant::Merchant() : m_buy(-1){}

void Merchant::applyEncounter(Player &player) {
    m_buyerName = player.getName();
    printMerchantInitialMessageForInteractiveEncounter(std::cout, m_buyerName, player.getCoins());
    getIntInputNumber(m_buy, SELL_START_INPUT_RANGE, SELL_END_INPUT_RANGE);

    bool hadMoney = false;
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
            throw GeneralError(); // general error unknown
            ;
    }
    if(!hadMoney) {
        printMerchantInsufficientCoins(std::cout);
    }
    printInfo(std::cout);
}

void Merchant::printInfo(std::ostream& os) const {
    switch(m_buy){
        case M_BUY_FORCE:
            printMerchantSummary(os, m_buyerName, m_buy, M_FORCE_COST);
            break;
        case M_BUY_HP:
            printMerchantSummary(os, m_buyerName, m_buy, M_HP_COST);
            break;
        default:
            printMerchantSummary(os, m_buyerName, m_buy, M_BUY_NOTHING);
    }

}
