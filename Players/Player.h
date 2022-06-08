#ifndef HW4_PLAYER_H
#define HW4_PLAYER_H

#include <string>
class Player{
public:
    static const int DEFAULT_FORCE = 5;
    static const int DEFAULT_MAXHP = 100; //HP set to MaxHP in start of game
    static const int STARTING_LEVEL = 1;
    static const int STARTING_COINS = 10;
    const int WIN_LEVEL = 10;


//---------------------------INITIATOR & DESTRUCTOR----------------------------
/***
 Player C'tor - Constructs a new Player.
                     @param maxHP (default = 100) - sets player's maxHP and HP
                     @param force (default = 5) -  sets player's force
                     @param name - sets players name
                     @field coins set to STARTING_COINS (0)
                     @field level set to STARTING_LEVEL (1)
                     @return
                            An instance of Player
*/
    explicit Player(const std::string name);

//  Copy-Assigment C'tor, Copy C'tor, D'tor - defaulted as string already handles memory, copy and copy-assignment.
    Player& operator=(const Player& src) = default;
    Player(const Player& src) = default;
    virtual ~Player() = default;

//--------------------------------------------------FUNCTIONS---------------------------------------------------------//

    friend std::ostream& operator<<(std::ostream& os,const Player& player);

    //get the name of the player
    std::string getName();

    //get the amount of coins the player have
    int getCoins();

    //increment player level by 1
    void levelUp();

    //@returns player level
    int getLevel() const;

    //increments player force by @param strUp
    void buff(const int strUp);

    //increments players HP by @param hpUp. Up to players maxHp
    virtual void heal(const int hpUp);

    //increments players HP negatively by @param hpDown. Down to 0
    void damage(const int hpDown);

    //@Returns
    //          true if hp = 0
    //          false otherwise
    bool isKnockedOut() const;

    //increments players coin up by @param coinUp
    virtual void addCoins(const int coinUp);

    //if player has at least coinDown number of m_coins:
    //increments players coin down by @param coinDown.
    //@returns
    //         true if action was executed
    //         false otherwise
    bool pay(const int coinDown);

    //@returns
    //         players attack strength - calculated as level+force
    virtual int getAttackStrength() const;

    //decrease 1 from the player force
    void weaken();

    void strengthen();

    virtual std::string getClass() const = 0;


//----------------------------PLAYER STATS---------------------------------
private:
    std::string m_name; // player name

protected:
    int m_level; // player level
    int m_force; // player force
    int m_HP; // player HP
    int m_maxHP; // player max HP
    int m_coins; // player coins

};


#endif //HW4_PLAYER_H
