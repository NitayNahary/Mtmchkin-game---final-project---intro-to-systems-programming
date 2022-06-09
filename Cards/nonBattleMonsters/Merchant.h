
#ifndef HW4_MERCHANT_H
#define HW4_MERCHANT_H
#include "Card.h"
#define SELL_START_INPUT_RANGE 0
#define SELL_END_INPUT_RANGE 2
class Merchant : public Card {
public:
    /*
     * Handling the player's applyEncounter with the card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    void applyEncounter(Player &player) override;


    /*
     * Prints the card info:
     *
     * @return
     *      void
    */


    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
private:
    void printInfo(std::ostream& os) const override;
    static const int M_ITEM_VALUE = 1;
    static const int M_HP_COST = 5;
    static const int M_FORCE_COST = 10;
    static const int M_BUY_NOTHING = 0;
    static const int M_BUY_HP = 1;
    static const int M_BUY_FORCE = 2;
    int m_buy;
    std::string m_buyerName;
};



#endif //HW4_MERCHANT_H
