
#ifndef HW4_MTMCHKIN_H
#define HW4_MTMCHKIN_H
#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <deque>
#include "Cards/Card.h"
#include "Cards/Barfight.h"
#include "Cards/Dragon.h"
#include "Cards/Fairy.h"
#include "Cards/Goblin.h"
#include "Cards/Merchant.h"
#include "Cards/Vampire.h"
#include "Cards/Pitfall.h"
#include "Cards/Treasure.h"
#include "Cards/Gang.h"

#include "Players/Player.h"
#include "Players/Fighter.h"
#include "Players/Wizard.h"
#include "Players/Rogue.h"

#include "MyUtilities.h"
#include <memory>



#define MIN_DECK_SIZE 5
#define MIN_PLAYERS 2
#define MAX_PLAYERS 6

enum class GeneralCardType{NotFound, Monster, NonMonster, EndGang};
enum class CardTypes{notCard,Barfight , Dragon , Fairy , Goblin , Merchant , Treasure , Pitfall , Vampire, Gang, EndGang};
enum class PlayerClass{notClass,Rogue , Wizard , Fighter};

static const int WIN_CONDITION = 10;

class Mtmchkin {
public:
    /*
    * C'tor of Mtmchkin class
    *
    * @param filename - a file which contains the cards of the deck.
    * @return
    *      A new instance of Mtmchkin.
    */
    explicit Mtmchkin(const std::string& fileName);

    /*
    * Play the next Round of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void playRound();

    /*
    * Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void printLeaderBoard() const;

    /*
    *  Checks if the game ended:
    *
    *  @return
    *          True if the game ended
    *          False otherwise
    */
    bool isGameOver() const;

    /*
    *  Returns the number of rounds played.
    *
    *  @return
    *          int - number of rounds played
    */
    int getNumberOfRounds() const;

private:
    std::deque<std::unique_ptr<Card>> m_deck;
    std::deque<std::unique_ptr<Player>> m_activePlayers;
    std::deque<std::unique_ptr<Player>> m_winPlayers;
    std::deque<std::unique_ptr<Player>> m_deadPlayers;
    int m_roundsPlayed;

    /*
     * Read cards one by one from deck file
     *          @param:
     *              const std::string& fileName - deck file name
     *          @return:
     *              void
     */
    void readCards(const std::string& fileName);

    /*
     * Initialize the players names and class
     *          @return:
     *              void
     */
    void initPlayers();

    /*
     * Make the players active in the game
     *          @param:
     *              const std::string& playerType - the class of the player
     *              const std::string& name - the name of the player
     *          @return:
     *              INVALID_NAME - the name is not valid
     *              INVALID_CLASS - the class is not valid
     *              INVALID_INPUT - the format of name and class is invalid
     *
     */
    int buildMyPlayer(const std::string& playerType, const std::string& name);

    /*
     * creates a new card
     *          @param:
     *              const std::string& cardTypeIndex - index of card type in mpa cardTypes
     *          @return:
     *              INVALID_CARD - illegal card
     *              VALID_INPUT - succes build the card
     *
     */
    int buildCard(const std::string& cardTypeIndex);

    /*
     * updates player status:
     * move to winners if player level hit win condition
     * move to dead players if player hp hit 0
     *          @param:
     *              &Player - a player
     *          @return:
     *              false if player status has not changed
     *              true if player status has changed
     *
     */
    bool changePlayerStatus(std::unique_ptr<Player>& player);

    /*
     *  create unique ptr of non monster based on card type index entered
     *          @param
     *              unique_ptr<Card>& cardType - destination pointer
     *              string& cardTypeIndex - index in map
     *          @return
     *              GeneralCardType::NonMonster - if the card successfully found
     *              GeneralCardType::NotFound - if no card matched
     */
    GeneralCardType getNonMonsterCardType(std::unique_ptr<Card>& cardType, const std::string& cardTypeIndex);

    /*
     *  create unique ptr of monster based on card type index entered
     *          @param
     *              unique_ptr<Card>& cardType - destination pointer
     *              string& cardTypeIndex - index in map
     *          @return
     *              GeneralCardType::Monster - if the card successfully found
     *              GeneralCardType::NotFound - if no card matched
     *              GeneralCardType::EndGang - when end gang string found
     */
    GeneralCardType getMonsterCardType(std::unique_ptr<MonsterCard> &cardType, const std::string &cardTypeIndex);
};


#endif //HW4_MTMCHKIN_H
