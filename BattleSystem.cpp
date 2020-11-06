//
// Created by jdinh on 10/2/2020.
//

#include "BattleSystem.h"


bool BattleSystem::battleSystem()
{
    /*(string& spell1, string& spell2, string& spell3, string& item1, string& item2, string& item3, int& healthMax, int& manaMax, int& expMax, int& weaponDamage, int& exp, int& enemyHealthMax, int& level, int& coins, int& healthPotions, int& manaPotions, int& attackPotions, int& enemyDamage)
    {
        srand(time(0));
        int totalDamage = weaponDamage + (10 + (rand() % 20));
        int healthRemain = healthMax;
        int enemyHealth = enemyHealthMax;
        int manaRemain = manaMax;
        int totalEnemyDamage = enemyDamage + (5 + (rand() % 10));

        cout << "\n\nEngaging Into Battle! "; pressEnterKey();

        bool menu = false;
        bool escape = false;
        bool death = false;

        do
        {
            int enemyDamageDone = (5 + rand() % totalEnemyDamage);
            if (manaRemain < 0)
            {
                manaRemain = 0;
            }

            do
            {
                cout << "\n\nHP (Health Points): " << healthRemain << "/" << healthMax << "          MP (Mana Points): " << manaRemain << "/" << manaMax << "          EH (Enemy Health): " << enemyHealth << "/" << enemyHealthMax;
                cout << "\n\nChoose An Option! "; cout << "\nFight (1)     Defend (3)\nItems (2)     Run    (4)\n";

                int option;
                cin >> option;

                option = invalidInput (1, 4, option);

                if (option == 1)
                {
                    int fightChoice;

                    cout << "\nAttack (1) or Spells (2) or Go Back (3): ";
                    cin >> fightChoice;

                    fightChoice = invalidInput (1, 3, fightChoice);

                    if (fightChoice == 1)
                    {
                        srand(time(0));
                        int damageDone = (25 + rand() % totalDamage);

                        cout << "\n\n**You Attack The Enemy For " << damageDone << " Damage! "; pressEnterKey();
                        enemyHealth -= damageDone;
                        menu = true;
                    }

                    else if (fightChoice == 2)
                    {
                        if (level < 5)
                        {
                            cout << "\n**You cannot cast any spells because your level is too low! Choose a different option! "; pressEnterKey(); pressEnterKey();
                            cout << endl << endl << endl << endl;
                            menu = false;
                        }

                        else if (manaRemain < 25)
                        {
                            cout << "\n**You do not have enough mana to use any of your skills! Either refill up your mana or choose a different option! "; pressEnterKey(); pressEnterKey();
                            cout << endl << endl << endl << endl;
                            menu = false;
                        }

                        else
                        {
                            cout << "\n\nSelect A Spell...\n" << spell1 << " (1)\n" << spell2 << "    (2)\n" << spell3 << "   (3)" << "\nNothing    (4)\n";

                            int spellChoice;
                            cin >> spellChoice;

                            spellChoice = invalidInput (1, 4, spellChoice);

                            int damageDone = 100;

                            if (spellChoice == 1)
                            {
                                if (spell1 != "Aureobolis")
                                {
                                    cout << "\n***You have not learned this specific spell yet! "; pressEnterKey(); pressEnterKey();
                                    cout << endl << endl << endl << endl;
                                    menu = false;
                                }

                                else
                                {
                                    cout << "\n\n**You cast the Aureobolis Spell! "; pressEnterKey();
                                    cout << "**You Attack The Enemy For " << damageDone << " Fire Damage!";
                                    enemyHealth -= damageDone;
                                    manaRemain -= 25;
                                    menu = true;
                                }
                            }

                            else if (spellChoice == 2)
                            {
                                if (spell2 != "Menicha")
                                {
                                    cout << "\n***You have not this specific spell yet! "; pressEnterKey(); pressEnterKey();
                                    cout << endl << endl << endl << endl;
                                    menu = false;
                                }

                                else if (manaRemain < 50)
                                {
                                    cout << "\n**You do not have enough mana to cast the Menicha spell! Either refill up your mana or choose a different option! "; pressEnterKey(); pressEnterKey();
                                    cout << endl << endl << endl << endl;
                                    menu = false;
                                }

                                else
                                {
                                    damageDone = 250;
                                    cout << "\n\n**You cast the Menicha Spell! "; pressEnterKey();
                                    cout << "**You Attack The Enemy For " << damageDone << " Light Damage!";
                                    enemyHealth -= damageDone;
                                    manaRemain -= 50;
                                    menu = true;
                                }
                            }

                            else if (spellChoice == 3)
                            {
                                if (spell3 != "Shadlino")
                                {
                                    cout << "\n***You have not learned this specific spell yet! "; pressEnterKey(); pressEnterKey();
                                    cout << endl << endl << endl << endl;
                                    menu = false;
                                }

                                else if (manaRemain < 50)
                                {
                                    cout << "\n**You do not have enough mana to cast the Shadlino spell! Either refill up your mana or choose a different option! "; pressEnterKey(); pressEnterKey();
                                    cout << endl << endl << endl << endl;
                                    menu = false;
                                }

                                else
                                {
                                    damageDone = 250;
                                    cout << "\n\n**You cast the Shadlino Spell! "; pressEnterKey();
                                    cout << "**You Attack The Enemy For " << damageDone << " Dark Damage!";
                                    enemyHealth -= damageDone;
                                    manaRemain -= 50;
                                    menu = true;
                                }
                            }

                            else if (spellChoice == 4)
                            {
                                cout << "\n**Going Back To Options! "; pressEnterKey(); pressEnterKey();
                                cout << endl << endl << endl << endl;
                                menu = false;
                            }
                        }
                    }

                    else if (fightChoice == 3)
                    {
                        cout << "\n**Going Back To Options! "; pressEnterKey(); pressEnterKey();
                        cout << endl << endl << endl << endl;
                        menu = false;
                    }
                }

                else if (option == 2)
                {
                    if (level == 0)
                    {
                        cout << "\n**You do not have access to any items right now! "; pressEnterKey(); pressEnterKey();
                        cout << endl << endl << endl << endl;
                        menu = false;
                    }

                    else
                    {
                        cout << "\n\nChoose An Item To Use...\n" << item1 << " Potion (1)\n" << item2 << " Potion   (2)\n" << item3 << " Potion (3)" << "\nNothing       (4)\n";

                        int itemChoice;
                        cin >> itemChoice;

                        itemChoice = invalidInput (1, 4, itemChoice);

                        if (itemChoice == 1)
                        {
                            if (checkPotions (healthPotions) == true)
                            {
                                cout << "\n\n***You do not have enough health potions to use! "; pressEnterKey(); pressEnterKey();
                                cout << "\n\n\n";
                                menu = false;
                            }

                            else if (checkPotions (healthPotions) == false)
                            {
                                if (healthRemain == healthMax)
                                {
                                    cout << "\n**You are already at maximum health! Going back to options! "; pressEnterKey(); pressEnterKey();
                                    cout << "\n\n\n";
                                    menu = false;
                                }

                                else
                                {
                                    healthRemain += 50;
                                    healthPotions -= 1;
                                    cout << "\n\n**You use 1 Health Potion! "; pressEnterKey();
                                    cout << "\n**You heal yourself for 50 HP! "; pressEnterKey();
                                    if (healthRemain > healthMax)
                                    {
                                        healthRemain = healthMax;
                                    }
                                    menu = true;
                                }
                            }
                        }

                        else if (itemChoice == 2)
                        {
                            if (checkPotions (manaPotions) == true)
                            {
                                cout << "\n\n***You do not have enough mana potions to use! "; pressEnterKey(); pressEnterKey();
                                cout << "\n\n\n";
                                menu = false;
                            }

                            else if (checkPotions (manaPotions) == false)
                            {
                                if (manaRemain == manaMax)
                                {
                                    cout << "\n**You are already at maximum mana! Going back to options! "; pressEnterKey(); pressEnterKey();
                                    cout << "\n\n\n";
                                    menu = false;
                                }

                                else
                                {
                                    manaRemain += 50;
                                    manaPotions -= 1;
                                    cout << "\n\n**You use 1 Mana Potion! "; pressEnterKey();
                                    cout << "\n**You refill for 50 MP! "; pressEnterKey();
                                    if (manaRemain > manaMax)
                                    {
                                        manaRemain = manaMax;
                                    }
                                    menu = true;
                                }
                            }
                        }

                        else if (itemChoice == 3)
                        {
                            if (checkPotions (attackPotions) == true)
                            {
                                cout << "\n\n***You do not have enough attack potions to use! "; pressEnterKey(); pressEnterKey();
                                cout << "\n\n\n";
                                menu = false;
                            }

                            else if (checkPotions (attackPotions) == false)
                            {
                                cout << "\n\n**You use 1 Attack Potion! "; pressEnterKey();
                                cout << "\n**You raise your attack by 10 points! "; pressEnterKey();
                                totalDamage += 15;
                                attackPotions -= 1;
                                menu = true;
                            }
                        }

                        else if (itemChoice == 4)
                        {
                            cout << "\n**Going Back To Options! "; pressEnterKey(); pressEnterKey();
                            cout << endl << endl << endl << endl;
                            menu = false;
                        }
                    }
                }

                else if (option == 3)
                {
                    cout << "\n**You DEFEND Yourself! "; pressEnterKey();
                    enemyDamageDone = totalEnemyDamage - (rand() % totalEnemyDamage);
                    menu = true;
                }

                else if (option == 4)
                {
                    int randNum = rand() % 50;

                    if (randNum < 35)
                    {
                        cout << "\n**You Escape! "; pressEnterKey();
                        escape = true;
                        break;
                    }

                    else if (randNum > 35)
                    {
                        cout << "\n**You Could Not Escape! "; pressEnterKey();
                        menu = true;
                    }

                    else
                    {
                        cout << "\n**You Could Not Escape! "; pressEnterKey();
                        menu = true;
                    }
                }
            } while (menu == false);

            if (escape == true)
            {
                return false;
            }

            if (enemyHealth < 0 || enemyHealth == 0)
            {
                pressEnterKey();
                cout << "\n\n\n**THE ENEMY'S HEALTH REACHES ZERO!\n**THE ENEMY HAS BEEN SLAIN! ";
                death = true;
                break;
                return true;
            }

            cout << "\n**The Enemy Has " << enemyHealth << " HP Left! "; pressEnterKey();
            cout << "\n**The Enemy Attacks For " << enemyDamageDone << " Damage! "; pressEnterKey();

            healthRemain -= enemyDamageDone;

            if (healthRemain < 0 || healthRemain == 0)
            {
                cout << "\n\n\n**YOUR HEALTH REACHES ZERO!\n**YOU HAVE BEEN SLAIN! "; pressEnterKey();
                cout << "\n\nYOUR FINAL GAME STATS:\nLevel: " << level << "\nCoins Left: " << coins << " "; pressEnterKey();
                cout << "\n\n\n\n\nYour time has come, my friend... "; pressEnterKey();
                cout << "You have gone through a mysterious and interesting journey... "; pressEnterKey();
                cout << "I wish the very best upon your future endeavors... "; pressEnterKey(); cout << "\nGoodbye... "; pressEnterKey();
                exit(1);
            }

            cout << endl << endl << endl << endl << endl << endl << endl;
        } while (death == false);
    }*/
}