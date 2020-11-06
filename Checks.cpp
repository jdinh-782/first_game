//
// Created by jdinh on 10/2/2020.
//

#include "Checks.h"


//makes sure the enter key is the only input, discards everything else
void Checks::pressEnterKey()
{
    while(true)
    {
        string input;
        getline(cin, input);

        if (input == "\n")
        {
            cout << endl;
        }
        else
        {
            break;
        }
    }
}


//discards any excess input
void Checks::excess()
{
    char a;

    do
    {
        cin.get(a);
    } while (a != '\n');
}


//checks specifically for char inputs and sets the pre-conditions for incorrect int inputs
int Checks::invalidInput (int num1, int num2, int correctInput)
{
    while (cin.fail() || correctInput < num1 || correctInput > num2)
    {
        cout << "Invalid Input! Enter Again: ";
        cin.clear();
        excess();
        cin >> correctInput;
    }
    return correctInput;
}