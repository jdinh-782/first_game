//
// Created by jdinh on 12/12/2020.
//

#ifndef FIRST_GAME_ITEMS_H
#define FIRST_GAME_ITEMS_H

#include "LinkedList.h"


template <class T>
class Items : public LinkedList<T>
{
private:
    T data;
    int itemAmounts[3];

public:
    Items();

    bool checkEmpty();

    void addItem(int itemIndex);
    void changeItemAmount(int index, int amount);
    int checkItemUsed(int itemChoice);

    T top();
};


#include "Items.cpp"

#endif //FIRST_GAME_ITEMS_H
