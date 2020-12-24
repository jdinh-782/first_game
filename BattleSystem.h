//
// Created by jdinh on 12/12/2020.
//

#ifndef FIRST_GAME_BATTLESYSTEM_H
#define FIRST_GAME_BATTLESYSTEM_H

#include "Validity.h"
#include "Spells.h"
#include "Items.h"
#include <ctime>


template <class T>
class BattleSystem
{
private:
    int level, totalDamage, enemyDamage, totalEnemyDamage, healthRemain, healthMax, enemyHealthRemain, enemyHealthMax,
        manaRemain, manaMax;
    bool menu = false;
    bool death = false;

public:
	BattleSystem();
	BattleSystem(int playerLevelInput, int weaponDamage, int healthInput, int manaInput, int enemyHealthInput);

    int getOption() const;

    void fight(int choice, Spells<T>& s);
    bool battle(Items<int>& i, Spells<T>& s);
};


#include "BattleSystem.cpp"

#endif //FIRST_GAME_BATTLESYSTEM_H
