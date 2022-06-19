//
// Created by shach on 6/19/2022.
//
#include "Card.h"
#include <memory>
#ifndef HW4_GANG_H
#define HW4_GANG_H


class Gang : public Card{
    bool m_open;
    void printInfo() const override;
    public:
    Gang();
    void applyEncounter(Player& player) override;
    bool open() const;
    void pushBack(std::unique_ptr<Card> addToGang);
    bool isMonster() override;
    void close();
};

#endif //HW4_GANG_H