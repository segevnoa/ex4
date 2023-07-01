#ifndef PLAYERFACTORY_H
#define PLAYERFACTORY_H

#include "Players/Player.h"
#include "Players/Ninja.h"
#include "Players/Warrior.h"
#include "Players/Healer.h"
#include <queue>
#include <memory>

int checkTeamSize();
std::vector<std::string> createVectorInput();
bool checkName (std::string name);
std::shared_ptr<Player> createPlayer();
std::vector<std::shared_ptr<Player>> createPlayers();

static const int MIN_TEAM_SIZE = 2;
static const int MAX_TEAM_SIZE = 6;
static const int MAX_LEN = 15;
static const char SPACE = ' ';
static const int INPUT_SIZE = 2;

#endif //PLAYERFACTORY_H
