//
// Created by shach on 6/19/2022.
//
#include "MonsterCard.h"
#include "Card.h"
#include <memory>
#include <deque>
#ifndef HW4_GANG_H
#define HW4_GANG_H


class Gang : public Card{
    bool m_open;
    std::deque<std::unique_ptr<MonsterCard>> m_gang;
    /*
     * Prints the card info:
     *
     * @return
     *      void
    */
    void printInfo() const override;
    public:
    /*
     * Empty C'tor
     *      @return
     *          An instance of Gang card
    */
    Gang();
    /*
     * Handling the player's applyEncounter with the card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    void applyEncounter(Player& player) override;
    /*
     * Adds a monster to the gang
     *
     * @return
     *      void
    */
    void pushBack(std::unique_ptr<Card> addToGang);
    /*
     * Check if the card is a monster card
     *
     * @return
     *      false
    */
    bool isMonster() override;
    //initialize m_open to true
    bool open() const;
    //initialize m_open to close
    void close();
};

#endif //HW4_GANG_H
