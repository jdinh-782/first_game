//
// Created by jdinh on 12/13/2020.
//

#ifndef FIRST_GAME_VILLAGE_H
#define FIRST_GAME_VILLAGE_H

#include "Validity.h"


template <class T>
class Village
{
private:
    int newBalance, potionIndex, potionAmount, spellIndex;
    bool learnedSpells[3];
    string spellNames[3];

public:
    Village();

    bool confirmPotionPurchase(int& playerCoins);
    bool confirmSpellPurchase(int& playerCoins, int spellCost);

    int getOption(int& playerCoins);
    int buyPotions(int& playerCoins);
    int returnPotionIndex();
    int returnPotionAmount();

    int learnSpell(int& playerCoins);
    string returnSpellName();

    int mainMenu();
};


#include "Village.cpp"

#endif //FIRST_GAME_VILLAGE_H
