//
// Created by jdinh on 12/13/2020.
//

#include "Validity.h"


Validity::Validity()
= default;


void Validity::excess()
{
    char c;

    do
    {
        cin.get(c);
    } while (c != '\n');
}


void Validity::pressEnterKey()
{
    while (true)
    {
        string input;
        getline(cin, input);

        if (input == "\n")
        {
            cout << "";
        }
        else
        {
            break;
        }
    }
}


int Validity::invalidInput(int num1, int num2, int correctInput)
{
    while (cin.fail() || correctInput < num1 || correctInput > num2)
    {
        cout << "Invalid input! Enter again: ";
        cin.clear();
        excess();
        cin >> correctInput;
    }
    return correctInput;
}



