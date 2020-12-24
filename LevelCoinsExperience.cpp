//
// Created by jdinh on 12/13/2020.
//

#include "LevelCoinsExperience.h"


LevelCoinsExperience::LevelCoinsExperience()
= default;


int LevelCoinsExperience::increaseExp()
{
    srand(time(nullptr));
    int addExp = 100 + (rand() % (100 - 50 + 1));

    return addExp;
}


int LevelCoinsExperience::increaseCoins()
{
    srand(time(nullptr));
    int randCoins = 100 + (rand() % 20);

    return randCoins;
}


