
#include "Mtmchkin.h"

static const std::map<std::string, CardTypes> CARD_LEXICON = {{"Barfight", CardTypes::Barfight},
                                                       {"Dragon",   CardTypes::Dragon},
                                                       {"Fairy",    CardTypes::Fairy},
                                                       {"Goblin",   CardTypes::Goblin},
                                                       {"Merchant", CardTypes::Merchant},
                                                       {"Treasure", CardTypes::Treasure},
                                                       {"Pitfall",  CardTypes::Pitfall},
                                                       {"Vampire",  CardTypes::Vampire}};

static const std::map<std::string, PlayerClass> CLASS_LEXICON = {{"Rogue",   PlayerClass::Rogue},
                                                          {"Wizard",  PlayerClass::Wizard},
                                                          {"Fighter", PlayerClass::Fighter}};

static bool isActive(SmartPtr<Player> player){
    if(player->isKnockedOut() || player->getLevel() == WIN_CONDITION){
        return false;
    }
    return true;
}

Mtmchkin::Mtmchkin(const std::string fileName){
    readCards(fileName);
    printStartGameMessage();
    initPlayers();
    m_roundsPlayed = 0;
}

void Mtmchkin::readCards(const std::string& fileName){
    FILE* source = fopen(fileName.c_str(), "r");
    char buffer[BUFFER_SIZE] = {'\0'};
    while(fgets(buffer,BUFFER_SIZE,source) != NULL) {
        if(buffer[15] != 0){ //define 15 as max length of card name
            //throw
        }
        if(buildMyCard(buffer) == -1){
            //handle
        }
        for(int i =0; i < BUFFER_SIZE; i++){
            buffer[i] = '\0';
        }
    }
    fclose(source);
}

//static int getNumOfPlayers(){
//    int num = 0;
//    bool firstSizeIn = true;
//    printEnterTeamSizeMessage();
//    do{
//        if(!firstSizeIn){
//            printInvalidTeamSize();
//        }
//        std::cin >> num;
//        firstSizeIn = false;
//    }
//    while(std::cin.fail() || num < 2 || num > 6);{
//
//
//    }
//    return num;
//}


void Mtmchkin::initPlayers(){
    int numberOfPlayers;
    getIntInputNumber(numberOfPlayers, 2, 6, printInvalidTeamSize);
    bool badInput = false;
    for(int i = 0; i < numberOfPlayers; i++){
        std::string input;
        if(!badInput) {
            printInsertPlayerMessage();
        }
        badInput = false;
        std::cin >> input;
        int spaceIndex = input.find_first_of(' ');
        int rawInputLength = input.length();
        std::string name, playerType;
        name = input.substr(0, spaceIndex);
        playerType = input.substr(spaceIndex + 1, rawInputLength);
        if(playerType.length() == 0 || playerType.find_first_of(' ') != std::string::npos){
            printInvalidInput();
            badInput = true;
        }
        else{
            //try{
                if(buildMyPlayer(playerType, name) == -1){
                    printInvalidClass();
                    badInput = true;
              //  }
            }//catch(Player::Bad_Name a){
              //  printInvalidName();
            //    badInput = true;
           // }
        }
        if(badInput){
            i--;
        }
    }
}

int Mtmchkin::buildMyPlayer(const std::string& playerType , const std::string& name){
    SmartPtr<Player> player;
    switch (CLASS_LEXICON.at(playerType)){
        case PlayerClass::Wizard:
            player = new Wizard(name);
            break;
        case PlayerClass::Rogue:
            player = new Rouge(name);
            break;
        case PlayerClass::Fighter:
            player = new Fighter(name);
            break;
        default:
            return -1;
    }
    m_activePlayers.pushBack(player);
    return 1;
}

int Mtmchkin::buildMyCard(const std::string& cardTypeIndex){
    SmartPtr<Card> card;
    switch (CARD_LEXICON.at(cardTypeIndex)){
        case CardTypes::Barfight:
            card = new Barfight();
            break;
        case CardTypes::Dragon:
            card = new Dragon();
            break;
        case CardTypes::Fairy:
            card = new Fairy();
            break;
        case CardTypes::Goblin:
            card = new Goblin();
            break;
        case CardTypes::Merchant:
            card = new Merchant();
            break;
        case CardTypes::Pitfall:
            card = new Pitfall();
            break;
        case CardTypes::Treasure:
            card = new Treasure();
            break;
        case CardTypes::Vampire:
            card = new Vampire();
            break;
        default:
            return -1;
    }
    m_deck.pushBack(card);
    return 1;
}

void Mtmchkin::updatePlayerStatus(SmartPtr<Player> player){
    if(player->isKnockedOut()){
        m_deadPlayers.push(player);
    }else if(player->getLevel() == WIN_CONDITION){
        m_winPlayers.pushBack(player);
    }
}

///---------------------------------------------PUBLIC FUNCTIONS-----------------------------------------------------------

void Mtmchkin::playRound(){
    printRoundStartMessage(m_roundsPlayed);
    for(SmartPtr<Player> player : m_activePlayers){
        printTurnStartMessage(player->getName());
        SmartPtr<Card> playingCard = m_deck.front();
        playingCard->applyEncounter(*player);
        updatePlayerStatus(player);
        m_deck.popFront();
        m_deck.pushBack(playingCard);
    }
    m_activePlayers = filter(m_activePlayers, isActive);
    m_roundsPlayed++;
    if(isGameOver()){
        printGameEndMessage();
    }
}

bool Mtmchkin::isGameOver() const{
    if(m_activePlayers.size() == 0){
        return true;
    }
    return false;
}

int Mtmchkin::getNumberOfRounds() const {
    return m_roundsPlayed;
}

void Mtmchkin::printLeaderBoard() const {
    printLeaderBoardStartMessage();
    int i = 1;
    for(SmartPtr<Player> player : m_winPlayers){
        printPlayerLeaderBoard(i, *player);
        i++;
    }
    for(SmartPtr<Player> player : m_activePlayers){
        printPlayerLeaderBoard(i, *player);
        i++;
    }
    for(SmartPtr<Player> player : m_deadPlayers){
        printPlayerLeaderBoard(i, *player);
        i++;
    }
}
