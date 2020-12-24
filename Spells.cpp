//
// Created by jdinh on 12/12/2020.
//
#ifndef FIRST_GAME_SPELLS_CPP
#define FIRST_GAME_SPELLS_CPP
#include "Spells.h"


template <class T>
Spells<T>::Spells()
{
    for (int i = 0; i < 3; i++)
    {
        addSpell("NULL");
    }
}


template <class T>
bool Spells<T>::checkManaRemaining(double manaRemain, double manaCost)
{
    if (manaCost > manaRemain)
    {
        cout << "\nYou do not have enough mana to use that spell! ";
        return true;
    }
    return false;
}


template<class T>
void Spells<T>::addSpell(string spellName)
{
    if (spellName == "Aureobolis")
    {
        spell1 = spellName;
    }
    else if (spellName == "Menicha")
    {
        spell2 = spellName;
    }
    else if (spellName == "Shadlino")
    {
        spell3 = spellName;
    }
    LinkedList<T>::operator+=(spellName);
}


template<class T>
T Spells<T>::top()
{
    string data = LinkedList<T>::headValue();
    return data;
}


#endif //FIRST_GAME_SPELLS_CPP