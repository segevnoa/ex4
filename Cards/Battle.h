#ifndef BATTLE_H
#define BATTLE_H

#include "Card.h"

class Battle : public Card {
public:
    //-- Battle methods --//
    Battle(int givenForce, int givenLoot, int givenDamage, bool dragonResult, bool witchResult, std::string name);
    ~Battle() = default;
    std::ostream& printCardInfo(std::ostream& os) const override;
    void applyEncounter(std::shared_ptr<Player> player) override;

    static const int WITCH_FORCE_DAMAGE = 1;

protected:
    int m_force;
    int m_loot;
    int m_damage;
    bool m_isDragon;
    bool m_isWitch;
    std::string m_BattleName;
private:
    friend std::ostream& operator<<(std::ostream& os, const Battle& card);
};

#endif //BATTLE_H
