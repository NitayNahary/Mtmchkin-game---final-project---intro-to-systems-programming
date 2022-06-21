
#include "Merchant.h"

Merchant::Merchant() : m_buy(-1){}

void Merchant::applyEncounter(Player &player) {
    m_buyerName = player.name();
    printMerchantInitialMessageForInteractiveEncounter(std::cout, m_buyerName, player.purse());
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
    }
    if(!hadMoney) {
        printMerchantInsufficientCoins(std::cout);
    }
    switch(m_buy){
        case M_BUY_FORCE:
            printMerchantSummary(std::cout, m_buyerName, m_buy, hadMoney ? M_FORCE_COST : 0);
            break;
        case M_BUY_HP:
            printMerchantSummary(std::cout, m_buyerName, m_buy, hadMoney ? M_HP_COST : 0);
            break;
        default:
            printMerchantSummary(std::cout, m_buyerName, m_buy, M_BUY_NOTHING);
    }
}

void Merchant::printInfo() const {
    printCardDetails(std::cout, "Merchant");
    printEndOfCardDetails(std::cout);

}

bool Merchant::isMonster() {
    return false;
}
