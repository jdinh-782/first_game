//
// Created by jdinh on 12/12/2020.
//
#ifndef FIRST_GAME_ITEMS_CPP
#define FIRST_GAME_ITEMS_CPP
#include "Items.h"


template <class T>
Items<T>::Items()
{
    data = 0;

    for (int& itemAmount : itemAmounts)
    {
        itemAmount = 0;
    }
}


template <class T>
bool Items<T>::checkEmpty()
{
    bool temp = LinkedList<T>::empty();
    return temp;
}


template <class T>
void Items<T>::addItem(int itemIndex)
{
    LinkedList<T>::operator+=(itemIndex);
}


template<class T>
void Items<T>::changeItemAmount(int index, int amount)
{
    if (index == 1)
    {
        itemAmounts[0] += amount;
        LinkedList<T>::changeHeadValue(itemAmounts[0]);
    }

    else if (index == 2)
    {
        itemAmounts[1] += amount;
        LinkedList<T>::changeMiddleValue(itemAmounts[1]);
    }

    else if (index == 3)
    {
        itemAmounts[2] += amount;
        LinkedList<T>::changeTailValue(itemAmounts[2]);
    }
}


template <class T>
int Items<T>::checkItemUsed(int itemChoice)
{
    if (itemChoice == 1)
    {
        if (LinkedList<T>::headValue() == 0)
        {
            return -1;
        }
        itemAmounts[0] -= 1;
        LinkedList<T>::changeHeadValue(itemAmounts[0]);
        return 1;
    }

    else if (itemChoice == 2)
    {
        if (LinkedList<T>::returnData() == 0)
        {
            return -1;
        }
        itemAmounts[1] -= 1;
        LinkedList<T>::changeHeadValue(itemAmounts[1]);
        return 2;
    }

    else if (itemChoice == 3)
    {
        if (LinkedList<T>::tailValue() == 0)
        {
            return -1;
        }
        itemAmounts[2] -= 1;
        LinkedList<T>::changeTailValue(itemAmounts[2]);
        return 3;
    }

    else if (itemChoice == 4)
    {
        return 4;
    }
    return -1;
}


template <class T>
T Items<T>::top()
{
    data = LinkedList<T>::headValue();
    return data;
}



#endif //FIRST_GAME_ITEMS_CPP