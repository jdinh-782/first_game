//
// Created by jdinh on 12/12/2020.
//

#ifndef FIRST_GAME_SPELLS_H
#define FIRST_GAME_SPELLS_H

#include "LinkedList.h"

template <class T>
class Spells : public LinkedList<T>
{
public:
    Spells();

    string spell1, spell2, spell3;

    bool checkManaRemaining(double manaRemain, double manaCost);

    void addSpell(string spellName);

    T top();
};


#include "Spells.cpp"

#endif //FIRST_GAME_SPELLS_H
