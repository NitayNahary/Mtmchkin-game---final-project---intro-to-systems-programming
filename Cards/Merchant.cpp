
#include "Merchant.h"

void Merchant::applyEncounter(Player &player) const{
    std::string name = player.name();
    int itemType = -1;
    printMerchantInitialMessageForInteractiveEncounter(std::cout, name, player.purse());
    getIntInputNumber(itemType, SELL_START_INPUT_RANGE, SELL_END_INPUT_RANGE);

    bool hadMoney = false;
    switch(itemType){
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
    switch(itemType){
        case M_BUY_FORCE:
            printMerchantSummary(std::cout, name, itemType, hadMoney ? M_FORCE_COST : M_BUY_NOTHING);
            break;
        case M_BUY_HP:
            printMerchantSummary(std::cout, name, itemType, hadMoney ? M_HP_COST : M_BUY_NOTHING);
            break;
        default:
            printMerchantSummary(std::cout, name, itemType, M_BUY_NOTHING);
    }
}

bool Merchant::isMonster() const{
    return false;
}

void Merchant::printInfo() const {
    printCardDetails(std::cout, "Merchant");
    printEndOfCardDetails(std::cout);

}