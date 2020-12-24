//
// Created by jdinh on 12/13/2020.
//

#ifndef FIRST_GAME_VALIDITY_H
#define FIRST_GAME_VALIDITY_H

#include <iostream>

using namespace std;


class Validity
{
public:
    Validity();

    static void excess();
    static void pressEnterKey();

    static int invalidInput (int num1, int num2, int correctInput);

};


#endif //FIRST_GAME_VALIDITY_H
