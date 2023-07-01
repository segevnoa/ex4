#include "Battle.h"

Battle::Battle(int givenForce, int givenLoot, int givenDamage, bool dragonResult, bool witchResult, std::string name){
    m_force = givenForce;
    m_loot = givenLoot;
    m_damage = givenDamage;
    m_isDragon = dragonResult;
    m_isWitch = witchResult;
    m_BattleName = name;
}

std::ostream& Battle::printCardInfo(std::ostream& os) const{
    printCardDetails(os,m_BattleName);
    printMonsterDetails(os,m_force,m_damage,m_loot,m_isDragon);
    printEndOfCardDetails(os);
    return os;
}

void Battle::applyEncounter(std::shared_ptr<Player> player) {
    int playerAttackForce = player->getAttackForce();
    if (playerAttackForce >= m_force) {
        player->levelUp();
        player->addCoins(m_loot);
        printWinBattle(player->getName(),m_BattleName);
    }
    else {
        int damage = m_damage;
        if (m_isDragon) {
            damage = player->getHP();
        }
        if (m_isWitch) {
            player->setForceDamage(WITCH_FORCE_DAMAGE);
        }
        player->damage(damage);
        printLossBattle(player->getName(),m_BattleName);
    }
}

std::ostream& operator<<(std::ostream& os, const Battle& card){
    return card.printCardInfo(os);
}