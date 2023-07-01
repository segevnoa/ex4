#include "Warrior.h"

Warrior::Warrior(std::string playerName)
        : Player(playerName, "Warrior") {}

int Warrior::getAttackForce () {
    int warriorForce = WARRIOR_MULTIPLY * m_force;
    int attackForce = m_level + warriorForce;
    return (attackForce);
}