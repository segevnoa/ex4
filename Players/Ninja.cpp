#include "Ninja.h"

Ninja::Ninja(std::string playerName)
            : Player(playerName, "Ninja"){}

void Ninja::addCoins (int moreCoins) {
    int newCoins = NINJA_MULTIPLY * moreCoins;
    m_coins += newCoins;
}