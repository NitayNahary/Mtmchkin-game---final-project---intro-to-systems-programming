#include "Player.h"
#include "../MyUtilities.h"
#include "../Exception.h"


static int zeroNegativeNumbers(const int value){
    return (value > 0 ? value : 0);
}

Player::Player(const std::string name) :  m_level(STARTING_LEVEL), m_force(DEFAULT_FORCE),
                                    m_HP(DEFAULT_MAXHP), m_maxHP(DEFAULT_MAXHP), m_coins(STARTING_COINS)
{
    if(isValidName(name)){
        m_name = name;
    }else
        throw InvalidName();
}
//--------------------------------------------------------------------------------------------------------------------//

std::ostream& operator<<(std::ostream& os,const Player& player){
    std::string job = player.getClass();
    printPlayerDetails(os,player.m_name,job,player.m_level,player.m_force,player.m_HP,player.m_coins);
    return os;
}
std::string Player::getName(){
    return m_name;
}

int Player::getCoins() {
    return m_coins;
}

void Player::levelUp(){
    if(m_level < WIN_LEVEL){
        m_level++;
    }
}

int Player::getLevel() const{
    return m_level;
}

void Player::buff(const int strUp){
    m_force += zeroNegativeNumbers(strUp);
}

void Player::heal(const int hpUp){
    int tempHp = zeroNegativeNumbers(hpUp) + m_HP;
    m_HP = tempHp > m_maxHP ? m_maxHP : tempHp;
}

void Player::damage(const int hpDown){
    int tempHp = m_HP - zeroNegativeNumbers(hpDown);
    m_HP = tempHp < 0 ? 0 : tempHp;
}

bool Player::isKnockedOut() const{
    return (m_HP == 0);
}

void Player::addCoins(const int coinUp){
    m_coins += zeroNegativeNumbers(coinUp);
}

bool Player::pay(const int coinDown){
    if(m_coins >= coinDown) {
        m_coins -= zeroNegativeNumbers(coinDown);
        return true;
    }
    return false;
}
int Player::getAttackStrength() const{
    return m_level + m_force ;
}
void Player::weaken() {
    if(m_force > 0)
        m_force -= 1;
}
void Player::strengthen() {
    m_force += 1;
}




