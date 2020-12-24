//
// Created by jdinh on 12/12/2020.
//
#ifndef FIRST_GAME_BATTLESYSTEM_CPP
#define FIRST_GAME_BATTLESYSTEM_CPP
#include "BattleSystem.h"


template <class T>
BattleSystem<T>::BattleSystem()
{
    srand(time(nullptr));

    level = 0;
    healthRemain = 0;
    healthMax = 0;
    enemyHealthRemain = 0;
    enemyHealthMax = 0;
    manaRemain = 0;
    manaMax = 0;
    totalEnemyDamage = 0;
    enemyDamage = 0;
    totalDamage = 0;
}


template <class T>
BattleSystem<T>::BattleSystem(int playerLevelInput, int weaponDamageInput, int healthInput, int manaInput, int enemyHealthInput) : enemyDamage(0)
{
    level = playerLevelInput;

    totalDamage = weaponDamageInput + (10 + (rand() % 20));

    healthRemain = healthInput;
    healthMax = healthInput;

    manaRemain = manaInput;
    manaMax = manaInput;

    enemyHealthRemain = enemyHealthInput;
    enemyHealthMax = enemyHealthInput;

    totalEnemyDamage = level + (5 + (rand() % 10));
}


template <class T>
int BattleSystem<T>::getOption() const
{
    int option;

    cout << "\n\nPlayer Level: " << level <<
            "\nHP (Health Points): " << healthRemain << "/" << healthMax << "          MP (Mana Points): "
         << manaRemain << "/" << manaMax << "          EH (Enemy Health): " << enemyHealthRemain << "/" << enemyHealthMax;
    cout << "\n[1] Fight"
            "\n[2] Items"
            "\n[3] Defend"
            "\n[4] Run"
            "\nEnter Choice: ";
    cin >> option;

    return option;
}


template <class T>
void BattleSystem<T>::fight(int choice, Spells<T>& s)
{
    if (choice == 1)
    {
        srand(time(nullptr));
        int damageDone = (25 + rand() % totalDamage);

        cout << "\n\n-> You attack the enemy for " << damageDone << " Damage! "; Validity::pressEnterKey();
             Validity::pressEnterKey();
        enemyHealthRemain -= damageDone;
        menu = false;
    }

    else if (choice == 2)
    {
        if (level < 5)
        {
            cout << "\n\n-> You cannot cast any spells because your level is too low! Choose a different option! ";
                 Validity::pressEnterKey(); Validity::pressEnterKey();
            menu = true;
            return;
        }

        else if (manaRemain < 25)
        {
            cout << "\n**You do not have enough mana to use any of your skills! Either refill up your mana or choose a "
                    "different option! "; Validity::pressEnterKey(); Validity::pressEnterKey();
            cout << endl;
            menu = true;
            return;
        }

        else
        {
            int spellChoice;

            cout << "\n\nSelect a spell..."
                    "\n[1] " << s.headValue() <<
                    "\n[2] " << s.returnData() <<
                    "\n[3] " << s.tailValue() <<
                    "\n[4] Go Back "
                    "\nEnter Choice: ";
            cin >> spellChoice;

            spellChoice = Validity::invalidInput(1, 4, spellChoice);

            int damageDone = 100;

            if (spellChoice == 1 && s.spell1 == "Aureobolis")
            {
                if (s.checkManaRemaining(manaRemain, 25))
                {
                    Validity::pressEnterKey;
                    return;
                }
                cout << "\n\n-> You cast the Aureobolis spell! "; Validity::pressEnterKey();
                cout << "-> You attack the enemy for " << damageDone << " Fire Damage!";
                enemyHealthRemain -= damageDone;
                manaRemain -= 25;
                menu = false;
            }

            else if (spellChoice == 2 && s.spell2 == "Menicha")
            {
                if (s.checkManaRemaining(manaRemain, 50))
                {
                    return;
                }
                damageDone = 250;
                cout << "\n\n-> You cast the Menicha spell! "; Validity::pressEnterKey();
                cout << "-> You attack the enemy for " << damageDone << " Light Damage!";
                enemyHealthRemain -= damageDone;
                manaRemain -= 50;
                menu = false;
            }

            else if (spellChoice == 3 && s.spell3 == "Shadlino")
            {
                if (s.checkManaRemaining(manaRemain, 50))
                {
                    return;
                }
                damageDone = 250;
                cout << "\n\n-> You cast the Shadlino spell! "; Validity::pressEnterKey();
                cout << "-> You attack the enemy for " << damageDone << " Dark Damage!";
                enemyHealthRemain -= damageDone;
                manaRemain -= 50;
                menu = false;
            }

            else if (spellChoice == 4)
            {
                cout << "\n-> Going back to options! "; Validity::pressEnterKey(); Validity::pressEnterKey();
                menu = true;
                return;
            }

            else
            {
                cout << "\n-> Not a valid spell! "; Validity::pressEnterKey(); Validity::pressEnterKey();
                cout << endl;
                menu = true;
            }
        }
    }

    else if (choice == 3)
    {
        cout << "\n-> Going back to options! "; Validity::pressEnterKey(); Validity::pressEnterKey();
        menu = true;
    }
}


//continue to update this function as game gets more complex
template <class T>
bool BattleSystem<T>::battle(Items<int>& i, Spells<T>& s)
{
    do
    {
        srand(time(nullptr));
        enemyDamage = (5 + rand() % totalEnemyDamage);

        do
        {
            int choice = getOption();

            cout << endl;
            choice = Validity::invalidInput(1, 4, choice);

            if (choice == 1)
            {
                int fightOption;

                cout << "\n[1] Weapon Attack"
                        "\n[2] Spells"
                        "\n[3] Go Back"
                        "\nEnter Choice: ";
                cin >> fightOption;

                fightOption = Validity::invalidInput(1, 3, fightOption);

                fight(fightOption, s);
            }

            else if (choice == 2)
            {
                if (level == 0)
                {
                    cout << "\n-> You do not have access to any items right now! "; Validity::pressEnterKey();
                         Validity::pressEnterKey();
                    menu = true;
                }

                else
                {
                    int itemChoice;
                    cout << "\n\nChoose an item to use..."
                            "\n[1] Health Potion - " << i.headValue() <<
                            "\n[2] Mana Potion - " << i.returnData() <<
                            "\n[3] Attack Potion - " << i.tailValue() <<
                            "\n[4] Go Back "
                            "\nEnter choice: ";
                    cin >> itemChoice;

                    itemChoice = Validity::invalidInput(1, 4, itemChoice);

                    int confirmItem = i.checkItemUsed(itemChoice);

                    if (confirmItem == 1)
                    {
                        healthRemain += 50;
                        if (healthRemain >= healthMax)
                        {
                            healthRemain = healthMax;
                        }
                        cout << "\nYou use 1 health potion! Your health increases by 50 points! "; Validity::pressEnterKey(); Validity::pressEnterKey();
                        menu = false;
                    }

                    else if (confirmItem == 2)
                    {
                        manaRemain += 50;
                        if (manaRemain >= manaMax)
                        {
                            manaRemain = manaMax;
                        }
                        cout << "\nYou use 1 mana potion! Your mana increases by 50 points! "; Validity::pressEnterKey(); Validity::pressEnterKey();
                        menu = false;
                    }

                    else if (confirmItem == 3)
                    {
                        totalDamage += 10;
                        cout << "\nYou use 1 attack potion! Your attack increases by 10 points! "; Validity::pressEnterKey(); Validity::pressEnterKey();
                        menu = false;
                    }

                    else if (confirmItem == 4)
                    {
                        cout << "\nGoing back to options! "; Validity::pressEnterKey(); Validity::pressEnterKey();
                        menu = true;
                    }

                    if (confirmItem == -1)
                    {
                        cout << "\nYou do not have any more potions! Try a different option! "; Validity::pressEnterKey(); Validity::pressEnterKey();
                        menu = true;
                    }
                }
            }

            else if (choice == 3)
            {
                cout << "\n-> You DEFEND yourself! "; Validity::pressEnterKey();

                int halfNumber = totalDamage / 2;
                int randomNumber = 0 + (rand() % halfNumber);
                enemyDamage = randomNumber;
                menu = false;
            }

            else if (choice == 4)
            {
                if (level == 0)
                {
                    cout << "\nYou cannot try to escape! You must fight now! "; Validity::pressEnterKey(); Validity::pressEnterKey();
                    menu = true;
                }

                else
                {
                    srand(time(nullptr));
                    int randNum = rand() % 50;

                    if (randNum < 35)
                    {
                        cout << "\n-> You escaped! "; Validity::pressEnterKey(); Validity::pressEnterKey();
                        return false;
                    }

                    else if (randNum > 35)
                    {
                        cout << "\n-> You could not escape! "; Validity::pressEnterKey(); Validity::pressEnterKey();
                        menu = true;
                    }
                }
            }

            if (!menu)
            {
                break;
            }
        } while (true);

        if (enemyHealthRemain < 0 || enemyHealthRemain == 0)
        {
            cout << "\n\n-> THE ENEMY'S HEALTH REACHES ZERO!"; Validity::pressEnterKey();
            cout << "-> THE ENEMY HAS BEEN SLAIN! "; Validity::pressEnterKey();
            return true;
        }

        cout << "-> The Enemy has " << enemyHealthRemain << " HP left! "; Validity::pressEnterKey();
        cout << "\n-> The Enemy attacks you for " << enemyDamage << " damage! "; Validity::pressEnterKey();

        healthRemain -= enemyDamage;

        if (healthRemain < 0 || healthRemain == 0)
        {
            cout << "\n\nYou have fallen...";
            exit(0);
        }
    } while (true);
}



#endif //FIRST_GAME_BATTLESYSTEM_CPP
