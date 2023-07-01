#ifndef CARDFACTORY_H
#define CARDFACTORY_H

#include <fstream>
#include <queue>
#include <memory>
#include "utilities.h"
#include "Exception.h"
#include "Cards/Card.h"
#include "Cards/Witch.h"
#include "Cards/Dragon.h"
#include "Cards/Gremlin.h"
#include "Cards/Barfight.h"
#include "Cards/Mana.h"
#include "Cards/Well.h"
#include "Cards/Treasure.h"
#include "Cards/Merchant.h"

std::shared_ptr<Card> createCard(std::string cardName, int lineNumber);
void createCardQueue (const std::string &fileName, std::queue<std::shared_ptr<Card>>& cardQueue);

static const int MIN_SIZE = 5;

#endif //CARDFACTORY_H
