#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>

class Player {
public:
    //-- constructor + big 3 --//
    Player(std::string playerName, std::string playerJob);
    Player (Player& other);
    Player& operator = (const Player& other);
    ~Player () = default;

    //-- player methods --//
    std::string getName();
    std::string  getJob();
    void levelUp ();
    int getLevel ();
    int forceUp();
    virtual void heal (int moreHP);
    void damage (int lessHP);
    bool isPlaying(); // checks at the end of ech round if it's still playing
    bool isKnockedOut();
    virtual void addCoins (int moreCoins);
    int getCoins ();
    bool pay (int lessCoins);
    virtual int getAttackForce ();
    std::ostream& printPlayerInfo(std::ostream& os) const;
    int getHP ();
    void setForceDamage (int forceToSet);

    //--static const --//
    static const int MAX_LEVEL = 10;
    static const int MIN_LEVEL = 1;
    static const int MAX_FORCE = 5;
    static const int MIN_FORCE = 0;
    static const int DEFAULT_HP = 100;
    static const int MIN_HP = 0;
    static const int DEFAULT_COINS = 10;
    static const int MIN_COINS = 0;
    static const bool DEFAULT_MODE = false;
    static const int NINJA_MULTIPLY = 2;
    static const int HEALER_MULTIPLY = 2;
    static const int WARRIOR_MULTIPLY = 2;

protected:
    std::string m_name;
    std::string m_job;
    int m_level;
    int m_force;
    int m_HP;
    int m_maxHP;
    int m_coins;
    bool m_isWin; // winning check
    bool m_isLose; // losing check
private:
    friend std::ostream& operator<<(std::ostream& os, const Player& player);
};

#endif //PLAYER_H
