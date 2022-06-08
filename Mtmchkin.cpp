
#include "Mtmchkin.h"

const std::map<std::string, CardTypes> CARD_LEXICON = {{"Barfight", CardTypes::Barfight},
                                                       {"Dragon",   CardTypes::Dragon},
                                                       {"Fairy",    CardTypes::Fairy},
                                                       {"Goblin",   CardTypes::Goblin},
                                                       {"Merchant", CardTypes::Merchant},
                                                       {"Treasure", CardTypes::Treasure},
                                                       {"Pitfall",  CardTypes::Pitfall},
                                                       {"Vampire",  CardTypes::Vampire}};

const std::map<std::string, PlayerClass> CLASS_LEXICON = {{"Rogue",   PlayerClass::Rogue},
                                                          {"Wizard",  PlayerClass::Wizard},
                                                          {"Fighter", PlayerClass::Fighter}};

static bool isActive(const Player* player){
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
//
//static bool isValidName(const std::string& name){
//    if(name.size() > 15){
//        return false;
//    }
//    for(char letter : name){
//        if(letter < 'A' || (letter > 'Z' && letter < 'a') || letter > 'z'){
//            return false;
//        }
//    }
//    return true;
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
    switch (CLASS_LEXICON.at(playerType)){
        case PlayerClass::Wizard:
            m_activePlayers.pushBack(&Wizard(name));
            break;
        case PlayerClass::Rogue:
            m_activePlayers.pushBack(&Rouge(name));
            break;
        case PlayerClass::Fighter:
            m_activePlayers.pushBack(&Fighter(name));
            break;
        default:
            return -1;
    }
    return 1;
}

int Mtmchkin::buildMyCard(const std::string& cardTypeIndex){
    switch (CARD_LEXICON.at(cardTypeIndex)){
        case CardTypes::Barfight:
            m_deck.pushBack(&Barfight());
            break;
        case CardTypes::Dragon:
            m_deck.pushBack(&Dragon());
            break;
        case CardTypes::Fairy:
            m_deck.pushBack(&Fairy());
            break;
        case CardTypes::Goblin:
            m_deck.pushBack(&Goblin());
            break;
        case CardTypes::Merchant:
            m_deck.pushBack(&Merchant());
            break;
        case CardTypes::Pitfall:
            m_deck.pushBack(&Pitfall());
            break;
        case CardTypes::Treasure:
            m_deck.pushBack(&Treasure());
            break;
        case CardTypes::Vampire:
            m_deck.pushBack(&Vampire());
            break;
        default:
            return -1;
    }
    return 1;
}

void Mtmchkin::updatePlayerStatus(Player *const  player){
    if(player->isKnockedOut()){
        m_deadPlayers.push(player);
    }else if(player->getLevel() == WIN_CONDITION){
        m_winPlayers.pushBack(player);
    }
}

///---------------------------------------------PUBLIC FUNCTIONS-----------------------------------------------------------

void Mtmchkin::playRound(){
    printRoundStartMessage(m_roundsPlayed);
    for(Player* player : m_activePlayers){
        printTurnStartMessage(player->getName());
        Card* playingCard = m_deck.front();
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
    for(const Player* player : m_winPlayers){
        printPlayerLeaderBoard(i, *player);
        i++;
    }
    for(const Player* player : m_activePlayers){
        printPlayerLeaderBoard(i, *player);
        i++;
    }
    for(const Player* player : m_deadPlayers){
        printPlayerLeaderBoard(i, *player);
        i++;
    }
}
