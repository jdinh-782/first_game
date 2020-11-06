#include <iostream>
#include <cstring>
#include <ctime>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <chrono>
#include <thread>
#include "Checks.h"
#include "Dialogue.h"
#include <SFML/Graphics.hpp>

using namespace std;

bool minigame (int& coins);
bool checkPotions (int& potionNumber);
void loadSavedFile (int& level, int& exp, int& expMax, int& coins, int& healthMax, int& manaMax, int& weaponDamage, int& enemyHealthMax, int& enemyDamage, int& healthPotions, int& manaPotions, int& attackPotions, string& spell1, string& spell2, string& spell3, string& item1, string& item2, string& item3);
/*
int main()
{


//this function DOES RETURN A VALUE
//battle system for game that references numerous parameters and variables that will be used throughout the entire game



//this function DOES RETURN A VALUE
//returns a boolean value if number of potions is equal or not equal to 0
bool checkPotions (int& potionNumber)
{
    if (potionNumber == 0)
    {
        return true;
    }

    else
    {
        return false;
    }
}


//this function DOES RETURN A VALUE
//checks to see if the user is buying a valid amount of potions
//also checks if user has enough money to buy the desired amount of potions
bool buyingPotions(int& coins, int& potionAmount)
{
    cout << "\nHow many would you like to buy?\n";
    cin >> potionAmount;

    potionAmount = invalidInput (0, 1000000000, potionAmount);

    int total = potionAmount * 25;

    if (coins >= total)
    {
        coins -= total;

        cout << "\nYou bought " << potionAmount << " potion(s)! "; pressEnterKey();
        cout << "\nYou now have " << coins << " coins! "; pressEnterKey();
        return true;
    }

    else
    {
        return false;
    }
}


//this function DOES NOT RETURN A VALUE
//village system where the user will be able to have flexibility on what they want to do
void villageOptions (string& spell1, string& spell2, string& spell3, string& item1, string& item2, string& item3, int& coins, int& level, int& exp, int& weaponDamage, int& manaMax, int& manaRemain, int& healthMax, int& expMax, int& enemyHealthMax, int& healthPotions, int& manaPotions, int& attackPotions, int& enemyDamage)
{
    bool home = true;
    int startingExp = 0;
    int addExp = 0;
    srand(time(0));

    do
    {
        bool battle = false;
        int option, total;
        cout << "\n\n\n\n\nWhat would you like to do? "; pressEnterKey();

        cout << "\nCoins: " << coins; cout << "\n\nVisit Potions Shop     (1)        Battle Monsters  (4)\nVisit Spells Shop      (2)        ?????            (5)\nPlay Numerical Nonsense (3)        Main Menu        (6)\n";
        cin >> option;

        option = invalidInput (1, 6, option);

        if (option == 1)
        {
            int potionChoice, potionAmount;

            cout << "\n\n\nWelcome to the potions shop! We only have a small variety of potions, but they're sure to make you last in battle! "; pressEnterKey();
            cout << "\nHere are all our potions! Each potion costs 25 coins each! What would you like to buy? (Enter A Number For Your Choice) ";
            cout << "\n\nCoins: " << coins << "\n\nHealth Potion ~ Increases Remaining Health By 50 Points (1) \nMana Potion ~ Increases Remaining Mana By 50 Points (2) \nAttack Potion ~ Increases Attack By 5 Points (3) \nNothing (4) \n";
            cin >> potionChoice;

            potionChoice = invalidInput (1, 4, potionChoice);

            if (potionChoice == 1)
            {
                if (buyingPotions(coins, potionAmount) == true)
                {
                    item1 = "Health";
                    healthPotions += potionAmount;
                }

                else
                {
                    cout << "\nSorry, but you do not have enough coins! Come back next time! "; pressEnterKey(); pressEnterKey();
                    cout << endl << endl;
                }
            }

            else if (potionChoice == 2)
            {
                if (buyingPotions(coins, potionAmount) == true)
                {
                    item2 = "Mana";
                    manaPotions += potionAmount;
                }

                else
                {
                    cout << "\nSorry, but you do not have enough coins! Come back next time! "; pressEnterKey(); pressEnterKey();
                    cout << endl << endl;
                }
            }

            else if (potionChoice == 3)
            {
                if (buyingPotions(coins, potionAmount) == true)
                {
                    item3 = "Attack";
                    attackPotions += potionAmount;
                }

                else
                {
                    cout << "\nSorry, but you do not have enough coins! Come back next time! "; pressEnterKey(); pressEnterKey();
                    cout << endl << endl;
                }
            }

            else if (potionChoice == 4)
            {
                cout << "\nCome Back Next time! Going Back To Options! "; pressEnterKey(); pressEnterKey();
                cout << endl << endl;
            }
        }

        else if (option == 2)
        {
            if (level < 5)
            {
                cout << "\nYou must be at least level 5 to unlock spells! "; pressEnterKey(); pressEnterKey();
            }

            else
            {
                int choice, response;

                cout << "\n\n\nWelcome to the spells shop! We have trained and perfected our magic for years so we can teach young masters like you! "; pressEnterKey();
                cout << "\nWhich spell would you like to learn today? (Enter A Number For Your Choice) ";
                cout << "\n\nCoins: " << coins; cout << "\n\nAureobolis (1) \nMenicha (2) \nShadlino (3) \nNothing (4) \n";
                cin >> choice;

                choice = invalidInput (1, 4, choice);

                if (choice == 1)
                {
                    total = 500;
                    cout << "\nThe Aureobolis spell specializes in fire power! It costs 500 coins to learn it! "; pressEnterKey();
                    cout << "\nWould you like to learn this specific spell? (Enter 1 For \"Yes\", Enter 2 For \"No\") \n";
                    cin >> response;

                    response = invalidInput (1, 2, response);

                    if (response == 1)
                    {
                        if (total > coins)
                        {
                            cout << "\nYou do not have enough coins to afford the Aureobolis spell! Going back to options! "; pressEnterKey(); pressEnterKey();
                            cout << endl << endl << endl;
                        }

                        else
                        {
                            cout << "\nYou have learned the Aureobolis spell! It is now equipped to your skillset! Enhance your mastery! "; pressEnterKey(); pressEnterKey();
                            cout << endl;
                            spell1 = "Aureobolis";
                            coins -= 500;
                        }
                    }

                    else if (response == 2)
                    {
                        cout << "\nThat is a shame... "; pressEnterKey(); pressEnterKey();
                        cout << endl << endl << endl;
                    }
                }

                else if (choice == 2)
                {
                    total = 1000;
                    cout << "\nThe Menicha spell specializes in light power! It costs 1000 coins to learn it! "; pressEnterKey();
                    cout << "\nWould you like to learn this specific spell? (Enter 1 For \"Yes\", Enter 2 For \"No\") \n";
                    cin >> response;

                    response = invalidInput (1, 2, response);

                    if (response == 1)
                    {
                        if (total > coins)
                        {
                            cout << "\nYou do not have enough coins to afford the Menicha spell! Going back to options! "; pressEnterKey(); pressEnterKey();
                            cout << endl << endl << endl;
                        }

                        else
                        {
                            cout << "\nYou have learned the Menicha spell! It is now equipped to your skillset! Enhance your mastery! "; pressEnterKey(); pressEnterKey();
                            cout << endl;
                            spell2 = "Menicha";
                            coins -= 1000;
                        }
                    }

                    else if (response == 2)
                    {
                        cout << "\nThat is a shame... "; pressEnterKey(); pressEnterKey();
                        cout << endl << endl << endl;
                    }
                }

                else if (choice == 3)
                {
                    total = 1000;
                    cout << "\nThe Shadlino spell specializes in dark power! It costs 1000 coins to learn it! "; pressEnterKey();
                    cout << "\nWould you like to learn this specific spell? (Enter 1 For \"Yes\", Enter 2 For \"No\") \n";
                    cin >> response;

                    response = invalidInput (1, 2, response);

                    if (response == 1)
                    {
                        if (total > coins)
                        {
                            cout << "\nYou do not have enough coins to afford the Shadlino spell! Going back to options! "; pressEnterKey(); pressEnterKey();
                            cout << endl << endl << endl;
                        }

                        else
                        {
                            cout << "\nYou have learned the Shadlino spell! It is now equipped to your skillset! Enhance your mastery! "; pressEnterKey(); pressEnterKey();
                            cout << endl;
                            spell3 = "Shadlino";
                            coins -= 1000;
                        }
                    }

                    else if (response == 2)
                    {
                        cout << "\nThat is a shame... "; pressEnterKey(); pressEnterKey();
                        cout << endl << endl << endl;
                    }
                }

                else if (choice == 4)
                {
                    cout << "\nCome Back Next Time! Going Back To Options! "; pressEnterKey(); pressEnterKey();
                    cout << endl << endl << endl;
                }
            }
        }

        else if (option == 3)
        {
            if (minigame(coins) == false)
            {
                cin.clear();
                cout << "Going Back To Options! "; pressEnterKey();
                cout << endl << endl;
            }

            else
            {
                cin.clear();
                cout << "Winner! "; pressEnterKey();
                cout << endl << endl;
            }
        }

        else if (option == 4)
        {
            int response;
            cout << "\nAre you ready to go out and fight? (Enter 1 For \"Yes\", Enter 2 For \"No\")\n";
            cin >> response;

            response = invalidInput (1, 2, response);

            if (response == 1)
            {
                cout << "\n\n\nHeading out... "; pressEnterKey(); pressEnterKey();
                cout << "You roam freely into the open grass...searching for the next enemy. "; pressEnterKey();
                cout << "A creature approaches from your blind side! You draw out your sword and commence battle! "; pressEnterKey();
                cout << endl << endl << endl << endl << endl;
                battle = true;
            }

            else if (response == 2)
            {
                cout << "\nIt is better to be be prepared first! "; pressEnterKey(); pressEnterKey();
                cout << endl << endl << endl;
            }
        }

        else if (option == 5)
        {
            cout << "\n\n\nI see you want to venture into the darkness and find this mysterious aura that is coming from the top of the mountains. "; pressEnterKey();
            cout << "Let me ensure that you are ready to accomplish this life-threatening task... "; pressEnterKey();

            if (level < 10)
            {
                cout << "\nIt appears to me that you are not at least level 10...come back when you are more experienced! "; pressEnterKey();
            }

            else
            {
                cout << "\nAre you ready? (Enter 1 For \"Yes\", Enter 2 For \"No\")\n";

                int response;
                cin >> response;

                response = invalidInput (1, 2, response);

                if (response == 2)
                {
                    cout << "\nI see...prepare yourself first! "; pressEnterKey(); pressEnterKey();
                    cout << endl << endl << endl;
                    home == true;
                }

                else if (response == 1)
                {
                    cout << "\n\n\n\n\n\n\n\n\n\nIt is time... "; pressEnterKey(); pressEnterKey();
                    cout << "You have come so far young one...you have put in such tremendous work and have battled countless enemies. "; pressEnterKey();
                    cout << "Now you will find more...more about yourself and why...why you fight! "; pressEnterKey();
                    cout << "\n(You): I feel this power inside of me. I can sense it from all directions. I'm ready... "; pressEnterKey();
                    cout << "(You): The mountain...wonder what's going on top of it... "; pressEnterKey();
                    cout << "\nDark clouds are surrounding the summit as they give off a mysterious yet satisfying aura. "; pressEnterKey();
                    cout << "You make your way up the mountain, fighting off the clouds as they block your vision from moving on up. "; pressEnterKey();
                    cout << "\n(You): Whew...finally made it. This is very weird and creepy. Wait...what's that? "; pressEnterKey();
                    cout << "\nFrom a distance, you see a tall, slim figure with long white hair swaying through the wind. "; pressEnterKey();
                    cout << "\n(Unknown): I have been awaiting you...young one... "; pressEnterKey();
                    cout << "\n(You): Who are you?! What are your intentions?! "; pressEnterKey();
                    cout << "\n(Unknown): You should know by now. You don't remember me? "; pressEnterKey();
                    cout << "\n(You): Huh? Ok, I don't care who you are, but this atmosphere got me feeling tight and you very suspicious! "; pressEnterKey();
                    cout << "\n(Unknown): Heh. You have a very nice tone, don't you? Seems you have grown ever since the start of that war. "; pressEnterKey();
                    cout << "\n(You): What the? How do you know about the war? You know what, let's fight! I'll end it right here! "; pressEnterKey();
                    cout << "\n(Unknown): Sigh...I think you need a little recollection of your past... "; pressEnterKey();
                    cout << "\n*snaps fingers* "; pressEnterKey();
                    cout << "\nYour head throbs in pain! It seems as if the mysterious figure is toying with your memory! "; pressEnterKey();
                    cout << "\n(You): AHHHHHHHH WHAT ARE YOU DOING!!!!! "; pressEnterKey();
                    cout << "\n\n\n\n\n*war sounds and screaming* "; pressEnterKey();
                    cout << "\n(You): There's too many of them! We can't hold on much longer! Just get everyone to safety! "; pressEnterKey();
                    cout << "\n(Eric): We need to drive them back! We can't go out like this! "; pressEnterKey();
                    cout << "\n(You): AHHHH!!! They're too powerful!! Eric, the heli is here! We need to leave..NOW!!! "; pressEnterKey();
                    cout << "\n(Eric): Holy cow! Alright, let's leave! Where the hell is Henry?! "; pressEnterKey();
                    cout << "\n(Henry): They're too strong, holy! I'm getting to the heli right now! "; pressEnterKey();
                    cout << "\n(You): Gather as much people as you can! We're getting out of here!!! "; pressEnterKey();
                    cout << "(You): Jesus...why us? What the hell did we even do to these people? "; pressEnterKey();
                    cout << "(You): Mom, Dad! Where are you guys??? "; pressEnterKey();
                    cout << "(Mom): We're over here son! Please hurry! ";
                    cout << "\n(You): Hold on! I'm coming over right now! Damn the smoke! "; pressEnterKey();
                    cout << "\n\n\n*dark clouds appear* "; pressEnterKey();
                    cout << "\n(Unknown): Run child...run away...I sense your fear... "; pressEnterKey();
                    cout << "\n(You): Argh...Who are you?! No...please...don't hurt them! "; pressEnterKey();
                    cout << "\n(Unknown): Who? These people? They seem innocent and crying for help...I think they want to be saved. "; pressEnterKey();
                    cout << "(Unknown): You don't have much of an option boy...Either spare your life...or theirs... "; pressEnterKey();
                    cout << "\n(You): Dammit...TAKE ME! I don't know who you are, but I'm ready...ready to fight! "; pressEnterKey();
                    cout << "\n(Unknown): Hmm...you seem valuable...your decision is too late! We shall meet again! "; pressEnterKey();
                    cout << "\n(You): No...no...PLEASE...I BEG YOU, PLEASE DON'T DO IT!!! "; pressEnterKey();
                    cout << "\n\n\n*SLASH* "; pressEnterKey();
                    cout << "\n... "; pressEnterKey(); cout << "...... "; pressEnterKey();
                    cout << "\n(You): ...no...way... "; pressEnterKey();
                    cout << "(You): MOM!!!!! DAD!!!!! "; pressEnterKey();
                    cout << "\n\n\n*explosion...* "; pressEnterKey();
                    cout << "\n\n\n\n\n(You): AHHHHH...what...huh...no...way... "; pressEnterKey();
                    cout << "(You): You...you...KILLED MY PARENTS!!! "; pressEnterKey();
                    cout << "\n(Unknown): Yes...bring out that anger...you're too weak! You know it yourself! YOU DON'T REMEMBER ANYTHING! "; pressEnterKey();
                    cout << "\n(You): It's time...now I know why I fight... "; pressEnterKey();
                    cout << "(You): ...TO END VILLIANS LIKE YOU!!! "; pressEnterKey();
                    cout << "\n(Unknown): READY UP BECAUSE YOU JUST WISHED FOR YOUR DEATH BED!!! "; pressEnterKey();
                    break;
                }
            }
        }

        else if (option == 6)
        {
            int choice, response;

            cout << "\n\n\n\n\nMain Menu! "; pressEnterKey(); pressEnterKey();
            cout << "\nWhat would you like to do? ";
            cout << "\nCheck Progress     (1)" << endl << "Save/Load Game     (2)" << endl << "Exit Game          (3)" << endl << "Go Back To Options (4)\n";
            cin >> choice;

            choice = invalidInput (1, 4, choice);

            if (choice == 1)
            {
                cout << "\n\nHere is your progress: \n";
                cout << "Level: " << level << "\nExperience Points: " << exp << "\nMaximum Experience Points: " << expMax << "\nCoins: " << coins << "\nMaximum Health: "
                     << healthMax << "\nMaximum Mana: " << manaMax << "\nWeapon Damage: " << weaponDamage << "\nSpell 1: " << spell1 << "\nSpell 2: " << spell2 << "\nSpell 3: "
                     << spell3 << "\nItem 1: " << healthPotions << " " << item1 << " Potion(s)" << "\nItem 2: " << manaPotions << " " << item2 << " Potion(s)"
                     << "\nItem 3: " << attackPotions << " " << item3 << " Potion(s)" << endl; pressEnterKey(); pressEnterKey();
            }

            else if (choice == 2)
            {
                cout << "\nSAVE new progress or LOAD from a previous save file? (Enter 1 For \"Save\", Enter 2 For \"Load\", Enter 3 For \"None\"): ";
                cin >> response;

                response = invalidInput (1, 3, response);

                if (response == 1)
                {
                    string username;
                    cout << "\nPlease enter a username for your savefile (no spaces): ";
                    cin >> username;

                    ofstream savefile;
                    savefile.open("save.txt");

                    savefile << level << " " << exp << " " << expMax << " " << coins << " " << healthMax << " " << manaMax << " " << weaponDamage << " " << enemyHealthMax << " "
                             << enemyDamage << " " << healthPotions << " " << manaPotions << " " << attackPotions << endl
                             << spell1 << " " << spell2 << " " << spell3 << endl << item1 << " " << item2 << " " << item3 << "\n\n\n";

                    savefile << username << " stats: \n\nLevel: " << level << "\nExperience Points: " << exp << "\nMaximum Experience Points: " << expMax << "\nCoins: "
                             << coins << "\nMaximum Health: " << healthMax << "\nMaximum Mana: " << manaMax << "\nWeapon Damage: " << weaponDamage << "\nSpell 1: " << spell1
                             << "\nSpell 2: " << spell2 << "\nSpell 3: " << spell3 << "\nItem 1: " << healthPotions << " " << item1 << " Potion(s)" << "\nItem 2: " << manaPotions
                             << " " << item2 << " Potion(s)" << "\nItem 3: " << attackPotions << " " << item3 << " Potion(s)" << endl;

                    cout << "\nSaved! "; pressEnterKey(); pressEnterKey();
                    savefile.close();
                }

                else if (response == 2)
                {
                    loadSavedFile(level, exp, expMax, coins, healthMax, manaMax, weaponDamage, enemyHealthMax, enemyDamage, healthPotions, manaPotions, attackPotions, spell1, spell2, spell3, item1, item2, item3);
                    cout << "\nGoing Back To Options! "; pressEnterKey();
                }

                else if (response == 3)
                {
                    cout << "\nGoing Back To Options! "; pressEnterKey(); pressEnterKey();
                }
            }

            else if (choice == 3)
            {
                int decision;

                cout << "\nPlease make sure your game is saved first! Ready to exit out of the game? (Enter 1 For \"Yes\", Enter 2 For \"No\"): ";
                cin >> decision;

                decision = invalidInput (1, 2, decision);

                if (decision == 1)
                {
                    cout << "\nAlright see you soon! "; pressEnterKey();
                    exit (1);
                }

                else if (decision == 2)
                {
                    cout << "\nGoing Back To Options! "; pressEnterKey(); pressEnterKey();
                }
            }

            else if (choice == 4)
            {
                cout << "\nGoing Back To Options! "; pressEnterKey(); pressEnterKey();
            }
            cout << endl << endl;
        }

        if (battle == true)
        {
            if (battleSystem(spell1, spell2, spell3, item1, item2, item3, healthMax, manaMax, expMax, weaponDamage, exp, enemyHealthMax, level, coins, healthPotions, manaPotions, attackPotions, enemyDamage) == true)
            {
                addExp = (expMax / 3) + (25 + (rand() % 25));
                startingExp = addExp;
                exp += startingExp;

                int randCoins = (80 + rand() % 70);
                coins += randCoins;

                pressEnterKey();

                cout << "\n\n\nYou got " << randCoins << " coins! "; pressEnterKey();
                cout << "You gained " << startingExp << " EXPERIENCE POINTS! "; pressEnterKey();
            }

            else
            {
                pressEnterKey();

                cout << "\n\n\nYou got 0 coins! "; pressEnterKey();
                cout << "You gained 0 EXPERIENCE POINTS! "; pressEnterKey();

                coins += 0;
                exp += 0;
            }

            if (exp >= expMax)
            {
                cout << "\nYou have leveled up! "; pressEnterKey();

                level++;
                healthMax += 20;
                manaMax += 10;
                expMax += 100;
                weaponDamage += 30;
                exp = 0;
                enemyHealthMax += 40;
                enemyDamage += 3;

                cout << "\nYour maximum health increases to " << healthMax << "! "; pressEnterKey();
                cout << "Your maximum mana increases to " << manaMax << "! "; pressEnterKey();
                cout << "Your maximum experience increases to " << expMax << "! "; pressEnterKey();
            }

            cout << "\nYou are at Level " << level << "! (EXPERIENCE POINTS: " << exp << "/" << expMax << ") "; pressEnterKey();

            cout << "\nGoing back to the village... "; pressEnterKey();
            cout << endl << endl;
        }

    } while (home == true);
}


//this function DOES NOT RETURN A VALUE
//loads a saved file
void loadSavedFile (int& level, int& exp, int& expMax, int& coins, int& healthMax, int& manaMax, int& weaponDamage, int& enemyHealthMax, int& enemyDamage, int& healthPotions, int& manaPotions, int& attackPotions, string& spell1, string& spell2, string& spell3, string& item1, string& item2, string& item3)
{
    string name;
    ifstream loadFile;
    loadFile.open ("save.txt");

    if ( loadFile.fail() )
    {
        cout << "\nCannot Find Saved File! "; pressEnterKey(); pressEnterKey();
    }

    else
    {
        loadFile >> level >> exp >> expMax >> coins >> healthMax >> manaMax >> weaponDamage >> enemyHealthMax >> enemyDamage >> healthPotions >> manaPotions >> attackPotions
                 >> spell1 >> spell2 >> spell3 >> item1 >> item2 >> item3 >> name;

        cout << "\nLoaded! "; pressEnterKey(); pressEnterKey();

        cout << "\nWelcome back " << name << "! "; pressEnterKey();
        cout << "\nHere are your saved stats: \nLevel: " << level << "\nExperience Points: " << exp << "\nMaximum Experience Points: " << expMax << "\nCoins: "
             << coins << "\nMaximum Health: " << healthMax << "\nMaximum Mana: " << manaMax << "\nWeapon Damage: " << weaponDamage << "\nSpell 1: " << spell1
             << "\nSpell 2: " << spell2 << "\nSpell 3: " << spell3 << "\nItem 1: " << healthPotions << " " << item1 << " Potion(s)" << "\nItem 2: " << manaPotions
             << " " << item2 << " Potion(s)" << "\nItem 3: " << attackPotions << " " << item3 << " Potion(s)" << endl; pressEnterKey();
    }

    loadFile.close();
}


//this function DOES NOT RETURN A VALUE
//prints out the minigame array
void printArray (int arrayList[], int number)
{
    int arrayNumber = 1;

    for (int i = 0; i < number; i++)
    {
        cout << arrayNumber << " ";
        arrayNumber++;
    }
}


//this function DOES NOT RETURN A VALUE
//prints out the minigame matrix
void printMatrix (int arrayMatrix[][100], int numMatrix)
{
    cout << endl;
    for (int row = 0; row < numMatrix; row++)
    {
        for (int column = 0; column < numMatrix; column++)
        {
            cout << "?" << " ";
        }
        cout << endl;
    }
}


//this function DOES RETURN A VALUE
//returns the final prize after the user defeats the minigame
int ultimatePrize (int& coins, int prizeCounter, int counter)
{
    int prize = prizeCounter * counter;

    return prize;
}


//this function DOES RETURN A VALUE
//function for the entire minigame and its contents
bool minigame (int& coins)
{
    int choice;
    cout << "\n\n\nWelcome to Numerical Nonsense! A mysterious game that tests your abilities to think outside the box! "; pressEnterKey();
    cout << "\nWould you like to play? The rewards are endless! (Enter 1 For \"Yes\", Enter 2 For \"No\") \n";
    cin >> choice;

    choice = invalidInput (1, 2, choice);

    if (choice == 1)
    {
        int favNum;

        cout << "\n\nThe rules are simple! \nThere will be a couple of number-based questions in which you can earn coins by answering them correctly! "; pressEnterKey();
        cout << "\nWe'll start off pretty easy...and make sure to always THINK OUTSIDE THE BOX! "; pressEnterKey();
        cout << "\nLet's Begin Numerical Nonsense!!! "; pressEnterKey();

        cout << "\n\n\n\n\nWhat is your favorite triple digit number?\n";
        cin >> favNum;

        favNum = invalidInput (100, 999, favNum);

        for (int i = 0; i < 5; i++)
        {
            srand(time(0));
            int answer;

            int num2 = favNum + (rand() % favNum);
            int product = favNum * num2;

            cout << endl << favNum << " x " << num2 << ": ";
            cin >> answer;

            if (cin.fail() || answer != product) //checks specifically for char inputs
            {
                cout << "Wrong Answer! You Can Try Again One More Time: ";
                cin.clear();
                excess();
                cin >> answer;
            }

            if (answer == product)
            {
                int randCoins = 5 + (rand() % 5);
                coins += randCoins;

                cout << "\nNice! You won " << randCoins << " coins! ";
                cout << "\nYou now have " << coins << " coins! "; pressEnterKey();
                cout << endl << endl;
            }

            else
            {
                cout << "\nYour answer is wrong! Game over! "; pressEnterKey();
                cout << endl;
                return false;
            }
        }

        int num1, response;
        int arrayList[11];

        cout << "\nAlright, time to level up the intensity! "; pressEnterKey();
        cout << "\n\nHere are some random numbers: ";

        do
        {
            cout << endl << endl;
            printArray (arrayList, 5);

            cout << "\nChoose a number you like: ";
            cin >> num1;

            num1 = invalidInput (1, 5, num1);

            cout << "\nAre you positively sure you want to use this number? (Enter 1 For \"Yes\", Enter 2 For \"No\")\n";
            cin >> response;

            response = invalidInput (1, 2, response);
        } while (response == 2);

        int arrayMatrix[100][100];

        cout << "\nThe number you have chosen is " << num1 << ". "; pressEnterKey();
        cout << "\n\n\n\nHere is your board: ";

        printMatrix (arrayMatrix, num1);

        cout << "\nEach row of ?'s will count as one question! "; pressEnterKey();
        cout << "Each question is worth 20 points and for each question you answer correctly, a counter will be applied. "; pressEnterKey();
        cout << "However, once you miss a question, you will lose all your points and counters and the game will end! "; pressEnterKey();
        cout << "Try to answer as many questions as possible for the ultimate prize! "; pressEnterKey();
        cout << "You will now battle against the invisible blackbox! "; pressEnterKey();
        cout << "Ready...BEGIN!!! "; pressEnterKey();

        cout << endl << endl << endl << endl;

        int counter = 0;
        int prizeCounter = 0;

        for (int i = 0; i < 5; i++)
        {
            int answer;
            bool gameover = false;

            if (num1 == 5)
            {
                cout << "\nWho eight nine? (Enter Answer As An Integer): ";
                cin >> answer;

                if (answer != 7 || cin.fail())
                {
                    cout << "\nYou got the question wrong! The answer was 7 because 7 8 9! \nGame over! "; pressEnterKey(); pressEnterKey();
                    cout << endl;
                    return false;
                    break;
                }

                else
                {
                    cout << "\nYou got it right! "; pressEnterKey();
                    counter += 1;
                    prizeCounter += 10;
                }
            }

            if (num1 == 4)
            {
                string response;

                cout << "\nWhat do you call a snake that is 3.14 meters long? (Type Out Your Response ~ Lowercase Only): ";
                cin >> response;

                if (response == "python" || response == "piethon" || response == "pithon")
                {
                    cout << "\nYou got it right! "; pressEnterKey();
                    counter += 1;
                    prizeCounter += 10;
                }

                else
                {
                    cout << "\nYou got the question wrong! The answer was python! Haha get it? \nGame over! "; pressEnterKey();
                    cout << endl << endl;
                    return false;
                    break;
                }
            }

            else if (num1 == 3)
            {
                string input;

                cout << "\nWhich sport can also be called a number? (Type Out Your Response ~ Lowercase Only): ";
                cin >> input;

                if (input == "tennis" || input == "ten is")
                {
                    cout << "\nYou got it right! "; pressEnterKey();
                    counter += 1;
                    prizeCounter += 10;
                }

                else
                {
                    cout << "\nYou got the question wrong! The answer was tennis because ten is a number! \nGame over! "; pressEnterKey();
                    cout << endl << endl;
                    return false;
                    break;
                }
            }

            else if (num1 == 2)
            {
                cout << "\nWhat number is considered both even and odd? (Enter Answer As An Integer): ";
                cin >> answer;

                if (answer != 7 || cin.fail())
                {
                    cout << "\nYou got the question wrong! The answer was 7 because sEVEN is partially EVEN yet still odd! \nGame over! "; pressEnterKey();
                    cout << endl << endl;
                    return false;
                    break;
                }

                else
                {
                    cout << "\nYou got it right! "; pressEnterKey();
                    counter += 1;
                    prizeCounter += 10;
                }
            }

            else if (num1 == 1)
            {
                cout << "\nWe have been dealing a lot with numbers throughout this entire minigame, but you've finally made it to the finale! "; pressEnterKey();
                cout << "For your final question, what was the first number you inputted?\n";
                cin >> answer;

                if (answer != 3 || cin.fail())
                {
                    cout << "\nYou got the question wrong! You didn't think outside the box! The number was 3!\n";
                    cout << "How else would you have started the game?! \nGame over! "; pressEnterKey();
                    cout << endl << endl;
                    return false;
                    break;
                }

                else
                {
                    cout << "\nYou got it right! "; pressEnterKey();
                    counter += 1;
                    prizeCounter += 10;
                    num1 -= 1;
                }
            }

            if (num1 == 0)
            {
                int prize = ultimatePrize (coins, prizeCounter, counter);
                coins += prize;

                cout << "\n\n\nYou have defeated the blackbox and have won the ultimate prize! "; pressEnterKey();
                cout << "Your final counter is " << counter << "! By applying this to your ultimate prize... "; pressEnterKey();
                cout << "\nYou won the ultimate prize of " << prize << " coins! "; pressEnterKey();
                return true;
                break;
            }

            num1 -= 1;

            cout << endl << endl << endl << endl;

            cout << "\n\nHere is your remaining board:";

            printMatrix (arrayMatrix, num1);
        }
    }

    else if (choice == 2)
    {
        cout << "\nAww...we hope you can come again and play next time! "; pressEnterKey(); pressEnterKey();
    }
}


    string spell1, spell2, spell3, item1, item2, item3;
    int exp, expMax, coins, level, manaRemain, weaponDamage, enemyHealthMax, manaMax, healthMax, healthPotions, manaPotions, attackPotions, enemyDamage;

    level = 0;
    expMax = 100;
    healthMax = 100;
    manaMax = 100;
    enemyHealthMax = 100;
    weaponDamage = 0;
    manaRemain = 0;
    healthPotions = 0;
    manaPotions = 0;
    attackPotions = 0;
    exp = 0;
    coins = 0;
    enemyDamage = 5;

    int startinglevel = 0;
    int startingCoins = 0;
    int startingExp = 0;

    spell1 = "N/A";
    spell2 = "N/A";
    spell3 = "N/A";
    item1 = "N/A";
    item2 = "N/A";
    item3 = "N/A";


    //assuming the user only enters lowercase "yes"
    cout << "\nEnter \"yes\" to continue... ";
    string choice;
    cin >> choice;

    if ( choice != "yes" )
    {
        cout << "\nI understand...\n" << "I too have forgotten about myself and can only sink deeper into the unknown...\n" << "Farewell...my friend...\n";
        exit(1);
    }

    cout << "\nLet Us Begin! (Remember To Always Press Enter To Continue Unless Otherwise Stated) "; pressEnterKey(); pressEnterKey();

    int response;
    bool load = false;

    cout << "\nWould you like to load a saved file? (Enter 1 For \"Yes\", Enter 2 For \"No\")\n";
    cin >> response;

    response = invalidInput (1, 2, response);

    if (response == 1)
    {
        loadSavedFile(level, exp, expMax, coins, healthMax, manaMax, weaponDamage, enemyHealthMax, enemyDamage, healthPotions, manaPotions, attackPotions, spell1, spell2, spell3, item1, item2, item3);
        load = true;

        for ( int i = 0; i < 28; i++ )
        {
            cout << endl;
        }
    }

    else
    {
        for ( int i = 0; i < 29; i++ )
        {
            cout << endl;
        }
        cout << "The wind blows by... "; pressEnterKey();
        cout << "The leaves rustle in response... "; pressEnterKey();
        cout << "The air is cold... "; pressEnterKey();
        cout << "You feel cold... "; pressEnterKey();
        cout << "\n(You): Owww...my...head... "; pressEnterKey();
        cout << "(You): Whe...Where...Where am I? "; pressEnterKey();
        cout << "\nYou stare out at the open grass, filled with game that you have never seen before. "; pressEnterKey();
        cout << "\n(You): Man...What am I doing here? Matter of fact...who...am I? "; pressEnterKey();
        cout << "(You): N...Never mind that. I need to go find food and shelter. "; pressEnterKey();
        cout << "\nYou begin to roam around, looking at the vast majority of land. "; pressEnterKey();
        cout << "\nYou see something shining behind a stone as its gaze mysteriously sets upon you. "; pressEnterKey();
        cout << "You notice it is a sword and without hesitation, you retrieve it. "; pressEnterKey();
        cout << "\n\n**Obtained \"Mysterious Sword\" "; pressEnterKey();
        cout << "\n\nYou continue to move on while looking at the scenery. "; pressEnterKey();
        cout << "From a distance, you see an old man sitting on top a rock... "; pressEnterKey();
        cout << "The man is bothered by your sword and inspects it inescapably. "; pressEnterKey();
        cout << "\n(Old Man): My child! You must be the chosen one! "; pressEnterKey();
        cout << "\n(You): Excuse me??? "; pressEnterKey();
        cout << "\n(Old Man): You have the magical sword that was lost from the Valapolic War! YOU ARE OUR SAVIOR! "; pressEnterKey();
        cout << "\n(You): Uhhhhh...Whatever you say grandpa! "; pressEnterKey(); cout << "\nYou leave him, unbothered by the old man's loud chants. "; pressEnterKey();
        cout << endl;

        for (int i = 0; i < 3; i++)
        {
            cout << "(Old Man): Our savior! OUR SAVIOR!!! The LORD HAS BLESSED US!!! "; pressEnterKey();
        }

        cout << "\nAs you continue roaming around, looking for amenities, you notice something awfully unfamiliar. "; pressEnterKey();
        cout << "You look at the bears closer and realize...they aren't real animals??? "; pressEnterKey();
        cout << "These creatures look like demons as they have bat-like wings and razor sharp claws! "; pressEnterKey();
        cout << "One of the creatures begin to run towards you! You quickly draw out your sword! "; pressEnterKey();
        cout << endl << endl << endl;

        srand(time(0));

        if (battleSystem(spell1, spell2, spell3, item1, item2, item3, healthMax, manaMax, expMax, weaponDamage, exp, enemyHealthMax, level, coins, healthPotions, manaPotions, attackPotions, enemyDamage) == true)
        {
            int addExp = 0;
            addExp = 35 + (rand() % (50 - 35 + 1));
            startingExp = addExp;
            exp += startingExp;

            int randCoins = (80 + rand() % 20);
            startingCoins += randCoins;
            coins = startingCoins;

            pressEnterKey();

            cout << "\n\n\nYou got " << coins << " coins! "; pressEnterKey();
            cout << "You gained " << exp << " EXPERIENCE POINTS! "; pressEnterKey();
            cout << "\nYou are at Level 1! (EXPERIENCE POINTS: " << exp << "/" << expMax << ") "; pressEnterKey();
        }

        else
        {
            pressEnterKey();

            cout << "\n\n\nYou got " << coins << " coins! "; pressEnterKey();
            cout << "You gained " << exp << " EXPERIENCE POINTS! "; pressEnterKey();
            cout << "\nYou are at Level 1! (EXPERIENCE POINTS: " << exp << "/" << expMax << ") "; pressEnterKey();
        }

        level = 1;

        cout << "\n\n\nYou've managed to, or maybe not, defeat the enemy with only raw, yet pure skills! "; pressEnterKey();
        cout << "You continue on your way to explore the scenery and what it has to offer. "; pressEnterKey();
        cout << "After roaming around for hours, you stumble upon a village that looks like it has been through some very hard times. "; pressEnterKey();
        cout << "\n(You): Hmm...wonder what this village is like. "; pressEnterKey();
        cout << "(You): I'm going to go check it out. "; pressEnterKey();
        cout << "\nFilled with peasants and merchants, the village seems to be doing pretty well. "; pressEnterKey();
        cout << "You see a man walk up to you. He's dressed in a plain black t-shirt with brown trousers that make him look hideous. "; pressEnterKey();
        cout << "\n(Unknown Man): Hi! It is my pleasure to welcome you to our village! We have been unexpectedly waiting for you sir! "; pressEnterKey();
        cout << "(Unknown Man): I am the village director! I have been watching over everyone and ensuring their safety for years. "; pressEnterKey();
        cout << "\n(You): Yea...it looks like the buildings are burned in major areas...this place doesn't look quite in shape. "; pressEnterKey();
        cout << "\n(Director): It has been very hard to forget the damages caused by the Valapolic War... "; pressEnterKey();
        cout << "\n(You): Wow. So this war must've been terrifying for everyone. I thought some old geezer was talking nonsense. "; pressEnterKey();
        cout << "(You): I don't really know too much. The only thing I can remember is waking up beside a tree on some hill. "; pressEnterKey();
        cout << "(You): I don't know my name, who I am, or where I even came from! Everything so far has been mind-boggling for me. "; pressEnterKey();
        cout << "\n(Director): I understand. Our brave men that we lost in that war...what I would do to bring them back to Earth! "; pressEnterKey();
        cout << "(Director): Nonetheless, I should give you a tour and show you what our village has to offer! "; pressEnterKey();
        cout << "\nYou follow the village director as he shows you various shops and buildings all across the village. "; pressEnterKey();
        cout << "\n(Director): I just realized that large sword you have on you! It looks very appealing and awfully familiar. "; pressEnterKey();
        cout << "\n(You): Yea I found it on a rock...sounds pretty dull I know. Is it somehow yours? "; pressEnterKey();
        cout << "\n(Director): Oh no! No way that sword could be mine. It looks like it's only attracted to certain people. "; pressEnterKey();
        cout << "(Director): Here are our shops where you can buy the proper necessities for your journey! "; pressEnterKey();
        cout << "(Director): This shop on my left sells potions that will supply you with huge benefits! May come in handy one day. "; pressEnterKey();
        cout << "(Director): If you look to your right, our spells shop will teach you unique yet powerful magic! "; pressEnterKey();
        cout << "(Director): A little side note...you may be interested in this minigame! It's offered at this stand over here. "; pressEnterKey();
        cout << "(Director): That should be all for now. Please make yourself feel at home. Thank you...our savior.. "; pressEnterKey();
        load = true;
    }

    if (load == true)
    {
        do
        {
            int response;
            villageOptions (spell1, spell2, spell3, item1, item2, item3, coins, level, exp, weaponDamage, manaMax, manaRemain, healthMax, expMax, enemyHealthMax, healthPotions, manaPotions, attackPotions, enemyDamage);

            cout << "\nARE YOU READY??? (Enter 1 For \"Yes\", Enter 2 For \"No\") \n";
            cin >> response;

            response = invalidInput (1, 2, response);

            if (response == 1)
            {
                enemyHealthMax = 5000;

                cout << "\nLET'S GOOOOOOOOOO!!!!!!!!!! "; pressEnterKey(); pressEnterKey();
                cout << endl << endl << endl;
                enemyHealthMax = 1000;
                enemyDamage = 50;
                battleSystem(spell1, spell2, spell3, item1, item2, item3, healthMax, manaMax, expMax, weaponDamage, exp, enemyHealthMax, level, coins, healthPotions, manaPotions, attackPotions, enemyDamage);
                cout << "\n\n\n\n\n(You): I...I did it... "; pressEnterKey();
                cout << "\nYou fall to the ground, shaken up by that once-in-a-life-time battle you just had with the figure. "; pressEnterKey();
                cout << "The dark clouds disperse and the sun gleams its light upon your sword. "; pressEnterKey();
                cout << "\n(You): This sword. It has saven my life ever since... "; pressEnterKey();
                cout << "(You): Why are you so special? Why did you choose me? Why... "; pressEnterKey();
                cout << "\nYou lay down on your back as you stare at the sky... "; pressEnterKey();
                cout << "You ponder more about what just happened and what will come in the near future. "; pressEnterKey();
                cout << "\n(You): Life is interesting...full of interesting stuff... "; pressEnterKey();
                cout << "(You): Just like that weird spaceship in the sky... "; pressEnterKey();
                cout << "(You): Wait...hold on......NOOOOOO!!! "; pressEnterKey();
                cout << "\n\n\n\n\nTo be continued...\n";
                exit(1);
            }

            else if (response == 2)
            {
                cout << "\nI guess the figure really scared you huh? "; pressEnterKey(); pressEnterKey();
                cout << endl;
            }
        } while (true);
    }

    return 0;
}*/

using std::this_thread::sleep_for;
using std::chrono::milliseconds;

/*const string message = "Hello, my name is Johnson.";

    for (const char c: message)
    {
        cout << c << flush;
        sleep_for(milliseconds(25));
    }
*/

int main()
{
    Dialogue d;

    sf::RenderWindow window(sf::VideoMode{ 1366, 768 , 32}, "Game");
    window.setVerticalSyncEnabled(true);

    sf::Clock clock;
    sf::Time elapsedTime;
    sf::String typedText, typedText1;
    sf::Text text;

    text = d.returnIntroText();
    typedText = d.returnIntroString(1);
    //typedText1 = d.returnIntroString(2);


    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        elapsedTime += clock.restart();

        while (elapsedTime >= sf::seconds(.06f))
        {
            elapsedTime -= sf::seconds(.06f);

            if (typedText.getSize() > 0)
            {
                text.setString(text.getString() + typedText[0]);
                typedText = typedText.toAnsiString().substr(1);
            }
        }

        window.clear();
        window.draw(text);
        window.display();
    }

    return 0;
}