
#include "Mtmchkin.h"

#include <memory>
using std::shared_ptr;
using std::unique_ptr;
using std::map;
using std::cerr;
using std::endl;
using std::string;


#define VALID_INPUT 1
#define INVALID_CLASS -2
#define INVALID_NAME -1
#define INVALID_CARD -1
#define GANG_CARD 2
#define ENDGANG_CARD 3
static map<string, CardTypes> CARD_LEXICON = {{"Barfight", CardTypes::Barfight},
                                              {"Dragon",   CardTypes::Dragon},
                                              {"Fairy",    CardTypes::Fairy},
                                              {"Goblin",   CardTypes::Goblin},
                                              {"Merchant", CardTypes::Merchant},
                                              {"Treasure", CardTypes::Treasure},
                                              {"Pitfall",  CardTypes::Pitfall},
                                              {"Vampire",  CardTypes::Vampire},
                                              {"Gang",     CardTypes::Gang},
                                              {"EndGang",  CardTypes::EndGang}};

static map<string, PlayerClass> CLASS_LEXICON = { {"Rogue",   PlayerClass::Rogue},
                                                  {"Wizard",  PlayerClass::Wizard},
                                                  {"Fighter", PlayerClass::Fighter}};

Mtmchkin::Mtmchkin(const string& fileName){
    printStartGameMessage();
    readCards(fileName);
    try {
        initPlayers();
    }catch (EndOfFile& eof){
        std::cout << "Team not full" << std::endl;
        throw InvalidTeamInput();
    }
    m_roundsPlayed = 0;
}

void Mtmchkin::readCards(const string& fileName){
    std::fstream source(fileName, std::fstream::in);
    if(source.fail() || !source){
        throw DeckFileNotFound();
    }
    string lineText;
    for(int line = 1; !source.eof(); line++){
        std::getline(source , lineText);
        if(buildCard(lineText) == INVALID_CARD && !source.eof()){
            throw DeckFileFormatError(line);
        }
    }
    if(m_deck.size() < MIN_DECK_SIZE){
        throw DeckFileInvalidSize();
    }
}
int Mtmchkin::buildCard(const string& cardTypeIndex){
    unique_ptr<Card> cardType;
    Gang* gang = m_deck.empty() ?  nullptr : dynamic_cast<Gang*>(&*m_deck.front());
    int inputValidity = getCardType(cardType, cardTypeIndex);

    switch (inputValidity) {
        case INVALID_CARD:
            return INVALID_CARD;
        case ENDGANG_CARD:
            if(!gang || !gang->open()){
                return INVALID_CARD;
            }
            gang->close();
            break;
        case GANG_CARD:
            if(gang){
                return INVALID_CARD;
            }
        default:
            if(gang && gang->open()){
                if(!cardType->isMonster()){
                    return INVALID_CARD;
                }
                gang->pushBack(std::move(cardType));
            }else{
                m_deck.push_back(std::move(cardType));
            }
    }
    return VALID_INPUT;
}
int Mtmchkin::getCardType(unique_ptr<Card>& cardType, const string& cardTypeIndex){
    switch (CARD_LEXICON[cardTypeIndex]){
        case CardTypes::Barfight:
            cardType = std::make_unique<Barfight>();
            break;
        case CardTypes::Dragon:
            cardType = std::make_unique<Dragon>();
            break;
        case CardTypes::Fairy:
            cardType = std::make_unique<Fairy>();
            break;
        case CardTypes::Goblin:
            cardType = std::make_unique<Goblin>();
            break;
        case CardTypes::Merchant:
            cardType = std::make_unique<Merchant>();
            break;
        case CardTypes::Pitfall:
            cardType = std::make_unique<Pitfall>();
            break;
        case CardTypes::Treasure:
            cardType = std::make_unique<Treasure>();
            break;
        case CardTypes::Vampire:
            cardType = std::make_unique<Vampire>();
            break;
        case CardTypes::Gang:
            cardType = std::make_unique<Gang>();
            return GANG_CARD;
        case CardTypes::EndGang:
            return ENDGANG_CARD;
        default:
            return INVALID_CARD;
    }
    return VALID_INPUT;
}
void Mtmchkin::initPlayers(){
    int numberOfPlayers;
    printEnterTeamSizeMessage();
    getIntInputNumber(numberOfPlayers, MIN_PLAYERS, MAX_PLAYERS, printInvalidTeamSize);

    bool badInputFlag = false;
    for(int i = 0; i < numberOfPlayers; badInputFlag ? i : i++){
        if(!badInputFlag) { //checking if last round had a bad input
            printInsertPlayerMessage();
        }
        badInputFlag = true;

        string input, name, playerType;
        getStringInput(input);
        string::size_type spaceIndex = input.find_first_of(' ');
        name = input.substr(0,spaceIndex);
        playerType = input.substr(spaceIndex+1);
        switch(buildMyPlayer(playerType, name)){
            case INVALID_NAME:
                printInvalidName();
                break;
            case INVALID_CLASS:
                printInvalidClass();
                break;
            default:
                badInputFlag = false;
        }
    }
}

int Mtmchkin::buildMyPlayer(const string& playerType , const string& name){
    switch (CLASS_LEXICON[playerType]){
        case PlayerClass::Wizard:
            m_activePlayers.push_back(unique_ptr<Player>(new Wizard(name)));
            break;
        case PlayerClass::Rogue:
            m_activePlayers.push_back(unique_ptr<Player>(new Rogue(name)));
            break;
        case PlayerClass::Fighter:
            m_activePlayers.push_back(unique_ptr<Player>(new Fighter(name)));
            break;
        default:
            try {
                Wizard nameCheck(name); //dummy player for name check
            }catch(InvalidName& a){
                return INVALID_NAME;
            }
            return INVALID_CLASS;
    }
    return VALID_INPUT;
}


bool Mtmchkin::changePlayerStatus(unique_ptr<Player>& player){
    if(player->isKnockedOut()){
        m_deadPlayers.push_front(std::move(player));
    }else if(player->getLevel() == WIN_CONDITION){
        m_winPlayers.push_back(std::move(player));
    }else{
        return false;
    }
    return true;
}

///---------------------------------------------PUBLIC FUNCTIONS-----------------------------------------------------------

void Mtmchkin::playRound(){
    printRoundStartMessage(++m_roundsPlayed);
    for(int i = 0; i < m_activePlayers.size(); i++){
        printTurnStartMessage(m_activePlayers[i]->name());
        unique_ptr<Card> playingCard = std::move(m_deck.front());
        playingCard->applyEncounter(*m_activePlayers[i]);

        if(changePlayerStatus(m_activePlayers[i])){
            m_activePlayers.erase(m_activePlayers.begin()+i);
            i--;
        }
        m_deck.pop_front();
        m_deck.push_back(std::move(playingCard));
    }
    if(isGameOver()){
        printGameEndMessage();
    }
}

bool Mtmchkin::isGameOver() const{
    if(m_activePlayers.empty()){
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
    for(const unique_ptr<Player>& player : m_winPlayers){
        printPlayerLeaderBoard(i, *player);
        i++;
    }
    for(const unique_ptr<Player>& player : m_activePlayers){
        printPlayerLeaderBoard(i, *player);
        i++;
    }
    for(const unique_ptr<Player>& player : m_deadPlayers){
        printPlayerLeaderBoard(i, *player);
        i++;
    }
}
