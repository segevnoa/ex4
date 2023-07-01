#include "utilities.h"
#include "Player.h"

Player::Player(std::string playerName, std::string playerJob):
            m_name(playerName),m_job(playerJob),m_level(MIN_LEVEL),m_force(MAX_FORCE),
            m_maxHP(DEFAULT_HP),m_HP(DEFAULT_HP),m_coins(DEFAULT_COINS),m_isWin(DEFAULT_MODE),
            m_isLose(DEFAULT_MODE){}

Player::Player (Player& other) {
    m_name = other.m_name;
    m_job = other.m_job;
    m_level = other.m_level;
    m_force = other.m_force;
    m_maxHP = other.m_maxHP;
    m_HP = other.m_HP;
    m_coins = other.m_coins;
    m_isWin = other.m_isWin;
    m_isLose = other.m_isLose;
}

Player& Player::operator= (const Player& other) {
    m_name = other.m_name;
    m_job = other.m_job;
    m_level = other.m_level;
    m_force = other.m_force;
    m_maxHP = other.m_maxHP;
    m_HP = other.m_HP;
    m_coins = other.m_coins;
    m_isWin = other.m_isWin;
    m_isLose = other.m_isLose;
    return *this;
}

std::string Player::getName() {
    return (m_name);
}

std::string Player::getJob() {
    return (m_job);
}

void Player::levelUp () {
    if (this->m_isWin) {
        return;
    }
    m_level++;
    if (m_level == MAX_LEVEL) {
     m_isWin = true;
    }
}

int Player::forceUp(){
    return m_force++;
};

int Player::getLevel () {
    int currentLevel = m_level;
    return currentLevel;
}

void Player::heal (int moreHP) {
    int sumHP = m_HP + moreHP;
    if (sumHP > m_maxHP) {
        this-> m_HP = m_maxHP;
    }
    m_HP = sumHP;
}

void Player::damage (int lessHP) {
    int diff = m_HP - lessHP;
    if (diff < MIN_HP) {
        diff = MIN_HP;
    }
    if (diff > m_HP) {
        m_HP = MIN_HP;
        m_isLose = false;
    }
    else {
        m_HP = diff;
    }
}

bool Player::isPlaying() {
    bool result = true;
    if (m_level == MAX_LEVEL || m_HP == MIN_HP){
        result = false;
    }
    return result;
}

bool Player::isKnockedOut () {
    bool result = false;
    if (m_HP == MIN_HP) {
        result = true;
    }
    return result;
}

void Player::addCoins (int moreCoins) {
    m_coins += moreCoins;
}

int Player::getCoins () {
    int coins = m_coins;
    return coins;
}

bool Player::pay (int lessCoins) {
    bool result = false;
    int diff = m_coins - lessCoins;
    if (diff >= MIN_COINS) {
        m_coins = diff;
        result = true;
    }
    return result;
}

int Player::getAttackForce () {
    int attackForce = m_level + m_force;
    return (attackForce);
}

int Player::getHP() {
    int hp = m_HP;
    return hp;
}

void Player::setForceDamage(int forceToSet) {
    int diff = m_force - forceToSet;
    if (diff <= MIN_FORCE){
        diff = MIN_FORCE;
    }
    m_force = diff;
}

std::ostream& Player::printPlayerInfo(std::ostream& os) const{
    printPlayerDetails(os, m_name, m_job, m_level, m_force, m_HP, m_coins);
    return os;
}

std::ostream& operator<<(std::ostream& os, const Player& player){
    return player.printPlayerInfo(os);
}