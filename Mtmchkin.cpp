
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

static bool isActive(std::shared_ptr<Player> player){
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
    if(source == nullptr){
        throw DeckFileNotFound();
    }
    int line = 1, deckSize = 0;
    char buffer[BUFFER_SIZE] = {'\0'};
    while(fgets(buffer,BUFFER_SIZE,source) != nullptr) {
        int lastChar = strlen(buffer)-1;
        if(buffer[lastChar] == '\n'){
            buffer[lastChar] = '\0';
        }
        if(!isValidName(buffer)){
            throw DeckFileFormatError(line);
        }
        if(buildMyCard(buffer) == NOT_FOUND){
            throw DeckFileFormatError(line);
        }
        else{
            deckSize++;
        }
        for(int i =0; i < BUFFER_SIZE; i++){
            buffer[i] = '\0';
        }
        line++;
    }
    if(deckSize < MIN_DECK_SIZE){
        throw DeckFileInvalidSize();
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
    getIntInputNumber(numberOfPlayers, MIN_PLAYERS, MAX_PLAYERS, printInvalidTeamSize);
    bool badInput = false;
    for(int i = 0; i < numberOfPlayers; i++){
        std::string input;
        if(!badInput) {
            printInsertPlayerMessage();
        }
        badInput = false;
        getStringInput(input);
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
            try{
                if(buildMyPlayer(playerType, name) == NOT_FOUND){
                    printInvalidClass();
                    badInput = true;
                }
            }catch(...){
                printInvalidName();
                badInput = true;
            }
        }
        if(badInput){
            i--;
        }
    }
}

int Mtmchkin::buildMyPlayer(const std::string& playerType , const std::string& name){
    try{
        switch (CLASS_LEXICON.at(playerType)){
            case PlayerClass::Wizard:
                m_activePlayers.pushBack(std::shared_ptr<Player>(new Wizard(name)));
                break;
                case PlayerClass::Rogue:
                    m_activePlayers.pushBack(std::shared_ptr<Player>(new Rogue(name)));
                    break;
                    case PlayerClass::Fighter:
                        m_activePlayers.pushBack(std::shared_ptr<Player>(new Fighter(name)));
                        break;
                        default:
                            return NOT_FOUND;
        }
    }catch(std::out_of_range& a){
        return NOT_FOUND;
    }
    return FOUND;
}

int Mtmchkin::buildMyCard(const std::string& cardTypeIndex){
    try{
        switch (CARD_LEXICON.at(cardTypeIndex)){
            case CardTypes::Barfight:
                m_deck.pushBack(std::shared_ptr<Card>(new Barfight()));
                break;
                case CardTypes::Dragon:
                    m_deck.pushBack(std::shared_ptr<Card>(new Dragon()));
                    break;
                    case CardTypes::Fairy:
                        m_deck.pushBack(std::shared_ptr<Card>(new Fairy()));
                        break;
                        case CardTypes::Goblin:
                            m_deck.pushBack(std::shared_ptr<Card>(new Goblin()));
                            break;
                            case CardTypes::Merchant:
                                m_deck.pushBack(std::shared_ptr<Card>(new Merchant()));
                                break;
                                case CardTypes::Pitfall:
                                    m_deck.pushBack(std::shared_ptr<Card>(new Pitfall()));
                                    break;
                                    case CardTypes::Treasure:
                                        m_deck.pushBack(std::shared_ptr<Card>(new Treasure()));
                                        break;
                                        case CardTypes::Vampire:
                                            m_deck.pushBack(std::shared_ptr<Card>(new Vampire()));
                                            break;
                                            default:
                                                return NOT_FOUND;
        }
    }catch(std::out_of_range& a){
        return NOT_FOUND;
    }

    return FOUND;
}

void Mtmchkin::updatePlayerStatus(std::shared_ptr<Player> player){
    if(player->isKnockedOut()){
        m_deadPlayers.push(player);
    }else if(player->getLevel() == WIN_CONDITION){
        m_winPlayers.pushBack(player);
    }
}

///---------------------------------------------PUBLIC FUNCTIONS-----------------------------------------------------------

void Mtmchkin::playRound(){
    printRoundStartMessage(m_roundsPlayed);
    for(std::shared_ptr<Player> player : m_activePlayers){
        printTurnStartMessage(player->getName());
        std::shared_ptr<Card> playingCard = m_deck.front();
        playingCard->applyEncounter(*player);
        std::cout << *playingCard << std::endl;
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
    for(std::shared_ptr<Player> player : m_winPlayers){
        printPlayerLeaderBoard(i, *player);
        i++;
    }
    for(std::shared_ptr<Player> player : m_activePlayers){
        printPlayerLeaderBoard(i, *player);
        i++;
    }
    for(std::shared_ptr<Player> player : m_deadPlayers){
        printPlayerLeaderBoard(i, *player);
        i++;
    }
}
