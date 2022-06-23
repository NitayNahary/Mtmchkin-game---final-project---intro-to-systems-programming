
#ifndef HW4_GANG_H
#define HW4_GANG_H

#include "MonsterCard.h"
#include "Card.h"
#include <memory>
#include <deque>

class Gang : public Card{
    public:
    /*
     * Empty C'tor of Gang card
     *      @return
     *          An instance of Gang card
    */
    Gang();

    // Copy C'tor, Assignment operator and Default D'tor of Gang card
    Gang(const Gang& src);
    Gang& operator=(const Gang& src);
    ~Gang() override = default;

    /*
     * Handling the player's applyEncounter with the card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    void applyEncounter(Player& player) const override;

    /*
     * Adds a monster to the gang
     *
     * @return
     *      void
    */
    void pushBack(std::unique_ptr<MonsterCard> addToGang);

    //initialize m_open to true
    bool open() const;

    //initialize m_open to close
    void close();

private:
    bool m_open;
    std::deque<std::unique_ptr<MonsterCard>> m_gang;

    /*
     * Prints the card info:
     *
     * @return
     *      void
    */
    void printInfo() const override;
};

#endif //HW4_GANG_H
