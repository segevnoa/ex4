#include "Well.h"

Well::Well() : Card("Well"){}

void Well:: applyEncounter(std::shared_ptr<Player> player) {
    bool isNinja = true;
    std::shared_ptr<Player> tempPlayer = std::dynamic_pointer_cast<Ninja>(player);
    if (tempPlayer == NULL) {
        player->damage(HP_OF_WELL);
        isNinja = false;
    }
    printWellMessage(isNinja);
}