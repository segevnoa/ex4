#include "Healer.h"

Healer::Healer(std::string playerName)
                : Player(playerName, "Healer") {}

void Healer::heal (int moreHP) {
    int healerHP = HEALER_MULTIPLY * moreHP;
    int sum = healerHP + m_HP;
    if (sum > m_maxHP){
        sum = m_maxHP;
    }
    m_HP = sum;
}