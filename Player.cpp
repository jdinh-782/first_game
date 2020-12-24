//
// Created by jdinh on 12/13/2020.
//
#ifndef FIRST_GAME_PLAYER_CPP
#define FIRST_GAME_PLAYER_CPP
#include "Player.h"


template <class T>
Player<T>::Player()
{
    playerName = "Johnson";
    playerLevel = 0;
    playerExp = 0;
    playerExpMax = 100;
    playerTotalCoins = 0;
    returnExp = 0;
    returnCoins = 0;
    playerWeaponDamage = 10;
    playerHealthMax = 100;
    playerManaMax = 100;
    enemyHealth = 100;

    for (int counter = 0; counter < 3; counter++)
    {
        i.addItem(0);
    }
}


template <class T>
Player<T>::Player(string playerNameInput, int playerLevelInput, int playerExpInput, int playerExpMaxInput, int playerTotalCoinsInput, int playerWeaponDamageInput,
                  int playerHealthMaxInput, int playerManaMaxInput, int enemyHealthInput)
{
    playerName = playerNameInput;
    playerLevel = playerLevelInput;
    playerExp = playerExpInput;
    playerExpMax = playerExpMaxInput;
    playerTotalCoins = playerTotalCoinsInput;
    returnExp = 0;
    returnCoins = 0;
    playerWeaponDamage = playerWeaponDamageInput;
    playerHealthMax = playerHealthMaxInput;
    playerManaMax = playerManaMaxInput;
    enemyHealth = enemyHealthInput;

    for (int counter = 0; counter < 3; counter++)
    {
        i.addItem(0);
    }
}


template <class T>
void Player<T>::addToTotalExp()
{
    if (playerLevel == 0)
    {
        playerLevel = 1;
    }
    else
    {
        returnExp = l.increaseExp();
        playerExp += returnExp;

        while (true)
        {
            if (playerExp >= playerExpMax)
            {
                //playerExp = 0;
                playerExp -= playerLevel * 100;
                playerExpMax += 100;
                playerLevel += 1;
                addToTotalHealth();
                addToTotalMana();
                increaseEnemyHealth();
                increaseWeaponDamage();
            }
            if (playerExp < playerExpMax)
            {
                break;
            }
        }
    }
}


template <class T>
void Player<T>::addToTotalCoins()
{
    returnCoins = l.increaseCoins();
    playerTotalCoins += returnCoins;
}


template <class T>
void Player<T>::addToTotalMana()
{
    playerManaMax += 75;
}


template <class T>
void Player<T>::addToTotalHealth()
{
    playerHealthMax += 100;
}


template <class T>
void Player<T>::increaseWeaponDamage()
{
    playerWeaponDamage += 50;
}


template <class T>
void Player<T>::increaseEnemyHealth()
{
    enemyHealth += 50;
}


template <class T>
void Player<T>::showStats()
{
    cout << "\n\n" << playerName << "'s stats: \n";
    cout << message; Validity::pressEnterKey(); Validity::pressEnterKey();
}


template <class T>
void Player<T>::saveOrLoadGame()
{
    int choice;

    cout << "\nSAVE new progress or LOAD from a previous save file? "
            "\n[1] Save"
            "\n[2] Load"
            "\n[3] Go Back"
            "\nEnter choice: ";
    cin >> choice;

    choice = Validity::invalidInput(1, 3, choice);

    if (choice == 1)
    {
        ofstream saveFile;
        saveFile.open("save.txt");

        saveFile << message;

        cout << "\nSaved! "; Validity::pressEnterKey(); Validity::pressEnterKey();
        saveFile.close();
    }

    else if (choice == 2)
    {
        //loadSavedFile(level, exp, expMax, coins, healthMax, manaMax, weaponDamage, enemyHealthMax, enemyDamage, healthPotions, manaPotions, attackPotions, spell1, spell2, spell3, item1, item2, item3);
        cout << "\nGoing Back To Options! "; Validity::pressEnterKey();
    }

    else if (choice == 3)
    {
        cout << "\nGoing Back To Options! "; Validity::pressEnterKey(); Validity::pressEnterKey();
    }
}


template <class T>
void Player<T>::goToVillage()
{
    playerLevel = 5;
    playerTotalCoins = 2000;
    do
    {
        int choice = v.getOption(playerTotalCoins);
        message = "Player Name: " + playerName + "\nLevel: " + to_string(playerLevel) + "\nExperience Points: " + to_string(playerExp) + "\nMaximum Experience Points: " + to_string(playerExpMax) +
                  "\nCoins: " + to_string(playerTotalCoins) + "\nMaximum Health: " + to_string(playerHealthMax) + "\nMaximum Mana: " + to_string(playerManaMax) +
                  "\nWeapon Damage: " + to_string(playerWeaponDamage) + "\nSpell 1: " + "NULL" + "\nSpell 2: " + "NULL" + "\nSpell 3: " + "NULL" + "\nItem 1: " + "NULL" +
                  " " + "NULL" + " Potion(s)" + "\nItem 2: " + "NULL" + " " + "NULL" + " Potion(s)" + "\nItem 3: " + "NULL" + " " + "NULL" + " Potion(s)\n";

        //buy potions
        if (choice == 1)
        {
            playerTotalCoins = v.buyPotions(playerTotalCoins);

            int potionTypeIndex = v.returnPotionIndex();
            int newPotionAmount = v.returnPotionAmount();
            i.changeItemAmount(potionTypeIndex, newPotionAmount);
        }

        //learn spells
        else if (choice == 2)
        {
            if (playerLevel < 5)
            {
                cout << "\nYou must be at least level 5 to unlock spells! "; Validity::pressEnterKey(); Validity::pressEnterKey();
            }
            else
            {
                playerTotalCoins = v.learnSpell(playerTotalCoins);

                string spellName = v.returnSpellName();
                s.addSpell(spellName);
            }
        }

        //minigame
        else if (choice == 3)
        {
            break;
        }

        //battle monsters
        else if (choice == 4)
        {
            int response;
            cout << "\nAre you ready to go out and fight? "
                    "\nEnter 1 For \"Yes\", Enter 2 For \"No\""
                    "\nEnter choice: ";
            cin >> response;

            response = Validity::invalidInput(1, 2, response);

            if (response == 1)
            {
                cout << "\n\n\nHeading out... "; Validity::pressEnterKey(); Validity::pressEnterKey();
                cout << "You roam freely into the open grass...searching for the next enemy. "; Validity::pressEnterKey();
                cout << "A creature approaches from your blind side! You draw out your sword and commence battle! "; Validity::pressEnterKey();
                cout << endl << endl << endl << endl << endl;
                goBattle = true;
            }

            else if (response == 2)
            {
                cout << "\nIt is better to be be prepared first! "; Validity::pressEnterKey(); Validity::pressEnterKey();
                cout << endl;
            }
        }

        //?????
        else if (choice == 5)
        {
            exit(0);
        }

        //main menu
        if (choice == 6)
        {
            //cout << i;
            //cout << s;
            int option = v.mainMenu();

            if (option == 1)
            {
                showStats();
            }
            else if (option == 2)
            {
                saveOrLoadGame();
            }

            else if (option == 3)
            {
                exit(0);
            }

            else if (option == 4)
            {
                //cout << i << endl;
                //cout << s;
                cout << "\nGoing back to options! "; Validity::pressEnterKey(); Validity::pressEnterKey();
            }
        }

        //work on displaying items and skills in the battle system
        if (goBattle)
        {
            BattleSystem<T> battleSystem(playerLevel, playerWeaponDamage, playerHealthMax, playerManaMax, enemyHealth);
            if (battleSystem.battle(i, s))
            {
                addToTotalCoins();
                addToTotalExp();
            }
            display();
            goBattle = false;
        }
    } while (true);
}


template <class T>
void Player<T>::display()
{
    cout << "\n\nYou got " << returnCoins << " coins! "; Validity::pressEnterKey();
    cout << "You gained " << returnExp << " experience points! "; Validity::pressEnterKey();

    cout << "\n\nLevel: " << playerLevel << " (EXP: " << playerExp << "/" << playerExpMax << ") "; Validity::pressEnterKey();

    returnCoins = 0;
    returnExp = 0;
}


#endif //FIRST_GAME_PLAYER_CPP