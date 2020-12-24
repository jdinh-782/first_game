//
// Created by jdinh on 12/13/2020.
//
#ifndef FIRST_GAME_VILLAGE_CPP
#define FIRST_GAME_VILLAGE_CPP
#include "Village.h"


template <class T>
Village<T>::Village()
{
    newBalance = 0;
    potionIndex = 0;
    potionAmount = 0;

    for (int i = 0; i < 2; i++)
    {
        learnedSpells[i] = false;
    }

    for (int i = 0; i < 2; i++)
    {
        spellNames[i] = "NULL";
    }
}


template <class T>
int Village<T>::getOption(int& playerCoins)
{
    int choice;
    newBalance = playerCoins;

    cout << "\n\n\n\n[1] Potions Shop"
            "\n[2] Spells Shop"
            "\n[3] Arcade"
            "\n[4] Battle Monsters"
            "\n[5] ?????"
            "\n[6] Main Menu "
            "\nEnter choice: ";
    cin >> choice;

    choice = Validity::invalidInput(1, 6, choice);

    return choice;
}


template <class T>
int Village<T>::buyPotions(int& playerCoins)
{
    int potionChoice;

    cout << "\n\n\nWelcome to the potions shop! We only have a small variety of potions, but they're sure to make you last in battle! "; Validity::pressEnterKey();
    cout << "\nHere are all our potions! Each potion costs 25 coins each! What would you like to buy? (Enter A Number For Your Choice) ";
    cout << "\nCoins: " << playerCoins;
    cout << "\n\n[1] Health Potion - Increases Remaining Health By 50 Points"
            "\n[2] Mana Potion - Increase Remaining Mana By 50 Points"
            "\n[3] Attack Potion - Increases Attack By 10 Points"
            "\n[4] Go Back"
            "\nEnter choice: ";
    cin >> potionChoice;

    potionChoice = Validity::invalidInput(1, 4, potionChoice);

    if (potionChoice == 1 || potionChoice == 2 || potionChoice == 3)
    {
        if (confirmPotionPurchase(playerCoins))
        {
            if (potionChoice == 1)
            {
                potionIndex = 1;
            }
            else if (potionChoice == 2)
            {
                potionIndex = 2;
            }
            else if (potionChoice == 3)
            {
                potionIndex = 3;
            }
        }
        else
        {
            cout << "\nSorry, but you do not have enough coins! Come back next time! "; Validity::pressEnterKey(); Validity::pressEnterKey();
            cout << endl << endl;
        }
    }
    else if (potionChoice == 4)
    {
        cout << "\nHope you come back next time! Going back to options! "; Validity::pressEnterKey(); Validity::pressEnterKey();
        cout << endl << endl;
    }
    return newBalance;
}


template <class T>
bool Village<T>::confirmPotionPurchase(int& playerCoins)
{
    cout << "\nHow many would you like to buy?\n";
    cin >> potionAmount;

    potionAmount = Validity::invalidInput(0, 1000, potionAmount);

    int potionTotal = potionAmount * 25;

    if (playerCoins >= potionTotal)
    {
        playerCoins -= potionTotal;
        newBalance = playerCoins;

        cout << "\nYou bought " << potionAmount << " potion(s)! "; Validity::pressEnterKey();
        cout << "\nYou now have " << playerCoins << " coins! "; Validity::pressEnterKey();
        return true;
    }
    return false;
}


template <class T>
int Village<T>::returnPotionIndex()
{
    return potionIndex;
}


template <class T>
int Village<T>::returnPotionAmount()
{
    return potionAmount;
}


template<class T>
int Village<T>::learnSpell(int& playerCoins)
{
    int choice, response;

    cout << "\n\n\nWelcome to the spells shop! We have trained and perfected our magic for years so we can teach young masters like you! "; Validity::pressEnterKey();
    cout << "\nWhich spell would you like to learn today? (Enter A Number For Your Choice) ";
    cout << "\n\nCoins: " << playerCoins;
    cout << "\n\n[1] Aureobolis"
            "\n[2] Menicha"
            "\n[3] Shadlino"
            "\n[4] Go Back"
            "\nEnter choice: ";
    cin >> choice;

    choice = Validity::invalidInput(1, 4, choice);

    if (choice == 1 || choice == 2 || choice == 3)
    {
        int cost;
        if (choice == 1)
        {
            spellNames[choice - 1] = "Aureobolis";
            spellIndex = 0;
            cost = 500;
        }
        else if (choice == 2)
        {
            spellNames[choice - 1] = "Menicha";
            spellIndex = 1;
            cost = 1000;
        }
        else if (choice == 3)
        {
            spellNames[choice - 1] = "Shadlino";
            spellIndex = 2;
            cost = 1500;
        }
        cout << "\nThe " << spellNames[choice - 1] << " spell costs " << cost << " coins to learn it! "; Validity::pressEnterKey();
        cout << "\nEnter 1 For \"Yes\", Enter 2 For \"No\""
                "\nEnter choice: ";
        cin >> response;

        response = Validity::invalidInput(1, 2, response);

        if (response == 1)
        {
            if (confirmSpellPurchase(playerCoins, cost))
            {
                learnedSpells[choice - 1] = true;
                return newBalance;
            }
            else
            {
                cout << "\nYou do not have enough coins to afford the Aureobolis spell! Going back to options! "; Validity::pressEnterKey(); Validity::pressEnterKey();
                cout << endl << endl << endl;
            }
        }

        else if (response == 2)
        {
            cout << "\nThat is a shame... "; Validity::pressEnterKey(); Validity::pressEnterKey();
            cout << endl << endl << endl;
        }
    }
    return newBalance;
}


template <class T>
bool Village<T>::confirmSpellPurchase(int& playerCoins, int spellCost)
{
    if (playerCoins >= spellCost)
    {
        cout << "\nYou have learned the spell! It is now equipped to your skillset! Enhance your mastery! "; Validity::pressEnterKey(); Validity::pressEnterKey();
        cout << endl;
        playerCoins -= spellCost;
        newBalance = playerCoins;
        return true;
    }
    return false;
}


template<class T>
string Village<T>::returnSpellName()
{
    return spellNames[spellIndex];
}


template<class T>
int Village<T>::mainMenu()
{
    int choice;

    cout << "\n\n\n\nMain Menu ";
    cout << "\n[1] Check Stats"
            "\n[2] Save/Load Game Data"
            "\n[3] Quit"
            "\n[4] Go Back"
            "\nEnter choice: ";
    cin >> choice;

    choice = Validity::invalidInput(1, 4, choice);

    return choice;
}


#endif //FIRST_GAME_VILLAGE_CPP