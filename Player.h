//
// Created by jdinh on 12/13/2020.
//

#ifndef FIRST_GAME_PLAYER_H
#define FIRST_GAME_PLAYER_H

#include "LevelCoinsExperience.h"
#include "Dialogue.h"
#include "BattleSystem.h"
#include "Village.h"
#include <fstream>


template <class T>
class Player : public Dialogue
{
protected:
    LevelCoinsExperience l;
    Village<T> v;
    Spells<T> s;
    Items<int> i;
    string playerName;
    int playerLevel, playerExp, playerExpMax, playerTotalCoins, playerWeaponDamage, playerHealthMax, playerManaMax;
    int enemyHealth;
    string message;

    bool goBattle = false;

public:
    Player();
    Player(string playerNameInput, int playerLevelInput, int playerExpInput, int playerExpMaxInput, int playerTotalCoinsInput, int playerWeaponDamageInput,
           int playerHealthMaxInput, int playerManaMaxInput, int enemyHealthInput);

    int returnExp;
    int returnCoins;

    void addToTotalExp();
    void addToTotalCoins();
    void addToTotalMana();
    void addToTotalHealth();
    void increaseWeaponDamage();
    void increaseEnemyHealth();
    void showStats();
    void saveOrLoadGame();
    void goToVillage();

    virtual void display();
};


#include "Player.cpp"

#endif //FIRST_GAME_PLAYER_H
