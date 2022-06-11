
#include "Mtmchkin.h"
using std::shared_ptr;
using std::map;
using std::string;
static const map<string, CardTypes> CARD_LEXICON = {{"Barfight", CardTypes::Barfight},
                                                    {"Dragon",   CardTypes::Dragon},
                                                    {"Fairy",    CardTypes::Fairy},
                                                    {"Goblin",   CardTypes::Goblin},
                                                    {"Merchant", CardTypes::Merchant},
                                                    {"Treasure", CardTypes::Treasure},
                                                    {"Pitfall",  CardTypes::Pitfall},
                                                    {"Vampire",  CardTypes::Vampire}};

static const map<string, PlayerClass> CLASS_LEXICON = {{"Rogue",   PlayerClass::Rogue},
                                                       {"Wizard",  PlayerClass::Wizard},
                                                       {"Fighter", PlayerClass::Fighter}};

static bool isActive(shared_ptr<Player> player){
    if(player->isKnockedOut() || player->getLevel() == WIN_CONDITION){
        return false;
    }
    return true;
}

Mtmchkin::Mtmchkin(const string& fileName){
    readCards(fileName);
    printStartGameMessage();
    try {
        initPlayers();
    }catch (EndOfFile& eof){
        std::cout << "Team not full" << std::endl;
        throw InvalidTeamInput();
    }
    m_roundsPlayed = 0;
}

void Mtmchkin::readCards(const string& fileName){
    FILE* source = fopen(fileName.c_str(), "r");
    if(source == nullptr){
        throw DeckFileNotFound();
    }
    char buffer[BUFFER_SIZE] = {'\0'};
    for(int line = 1; fgets(buffer,BUFFER_SIZE,source) != nullptr; line++){
        int lastChar = strlen(buffer)-1;
        if(lastChar >=0 && buffer[lastChar] == '\n'){
            buffer[lastChar] = '\0';
        }
        if(buildMyCard(buffer) == NOT_FOUND){
            throw DeckFileFormatError(line);
        }
        for(int i =0; i < BUFFER_SIZE; i++){
            buffer[i] = '\0';
        }
    }
    if(m_deck.size() < MIN_DECK_SIZE){
        throw DeckFileInvalidSize();
    }
    fclose(source);
}

void Mtmchkin::initPlayers(){
    int numberOfPlayers;
    printEnterTeamSizeMessage();
    getIntInputNumber(numberOfPlayers, MIN_PLAYERS, MAX_PLAYERS, printInvalidTeamSize);
    bool badInputFlag = false;
    for(int i = 0; i < numberOfPlayers; i++){
        if(!badInputFlag) { //checking if last round had a bad input
            printInsertPlayerMessage();
        }
        badInputFlag = false;
        string input;
        getStringInput(input);
//        std::cerr << input << std::endl;
        string::size_type spaceIndex = input.find_first_of(' ');
        string name, playerType;
        name = input.substr(0,spaceIndex);
        playerType = input.substr(spaceIndex+1);
        if(spaceIndex == string::npos || playerType.find_first_of(' ') != string::npos){
//            std::cout << playerType << name << std::endl;
            printInvalidInput();
            badInputFlag = true;
        }
        else{
            try{
                if(buildMyPlayer(playerType, name) == NOT_FOUND){
                    printInvalidClass();
                    badInputFlag = true;
                }
            }catch(InvalidName& a){
                printInvalidName();
                badInputFlag = true;
            }
        }
        if(badInputFlag){
            i--;
        }
    }
}

int Mtmchkin::buildMyPlayer(const string& playerType , const string& name){
    try{
        switch (CLASS_LEXICON.at(playerType)){
            case PlayerClass::Wizard:
                m_activePlayers.pushBack(shared_ptr<Player>(new Wizard(name)));
                break;
            case PlayerClass::Rogue:
                m_activePlayers.pushBack(shared_ptr<Player>(new Rogue(name)));
                break;
            case PlayerClass::Fighter:
                m_activePlayers.pushBack(shared_ptr<Player>(new Fighter(name)));
                break;
            default:
                return NOT_FOUND;
        }
    }catch(std::out_of_range& a){
        Wizard nameCheck(name); //dummy player for name check
        return NOT_FOUND;
    }
    return FOUND;
}

int Mtmchkin::buildMyCard(const string& cardTypeIndex){
    try{
        switch (CARD_LEXICON.at(cardTypeIndex)){
            case CardTypes::Barfight:
                m_deck.pushBack(shared_ptr<Card>(new Barfight()));
                break;
            case CardTypes::Dragon:
                m_deck.pushBack(shared_ptr<Card>(new Dragon()));
                break;
            case CardTypes::Fairy:
                m_deck.pushBack(shared_ptr<Card>(new Fairy()));
                break;
            case CardTypes::Goblin:
                m_deck.pushBack(shared_ptr<Card>(new Goblin()));
                break;
            case CardTypes::Merchant:
                m_deck.pushBack(shared_ptr<Card>(new Merchant()));
                break;
            case CardTypes::Pitfall:
                m_deck.pushBack(shared_ptr<Card>(new Pitfall()));
                break;
            case CardTypes::Treasure:
                m_deck.pushBack(shared_ptr<Card>(new Treasure()));
                break;
            case CardTypes::Vampire:
                m_deck.pushBack(shared_ptr<Card>(new Vampire()));
                break;
            default:
                return NOT_FOUND;
        }
    }catch(std::out_of_range& a){
        return NOT_FOUND;
    }

    return FOUND;
}

void Mtmchkin::updatePlayerStatus(const shared_ptr<Player>& player){
    if(player->isKnockedOut()){
        m_deadPlayers.push(player);
    }else if(player->getLevel() == WIN_CONDITION){
        m_winPlayers.pushBack(player);
    }
}

///---------------------------------------------PUBLIC FUNCTIONS-----------------------------------------------------------

void Mtmchkin::playRound(){
    printRoundStartMessage(++m_roundsPlayed);
    for(shared_ptr<Player> player : m_activePlayers){
        printTurnStartMessage(player->getName());
        shared_ptr<Card> playingCard = m_deck.front();
        playingCard->applyEncounter(*player);
        updatePlayerStatus(player);
        m_deck.popFront();
        m_deck.pushBack(playingCard);
    }
    m_activePlayers = filter(m_activePlayers, isActive);
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
    for(shared_ptr<Player> player : m_winPlayers){
        printPlayerLeaderBoard(i, *player);
        i++;
    }
    for(shared_ptr<Player> player : m_activePlayers){
        printPlayerLeaderBoard(i, *player);
        i++;
    }
    for(shared_ptr<Player> player : m_deadPlayers){
        printPlayerLeaderBoard(i, *player);
        i++;
    }
}
