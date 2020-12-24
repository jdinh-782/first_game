#include "Player.h"
#include "IntroDialogue.h"
#include "VillageDialogue.h"


int main()
{
//    IntroDialogue i;
//    i.display();

    BattleSystem<string> b(0, 0, 100, 0, 100);
    Player<string> p("Johnson", 1, 0, 100, 0, 10, 100, 100, 100);
    Items<int> i;
    Spells<string> s;

//    if (b.battle(i, s))
//    {
//        p.addToTotalCoins();
//        p.addToTotalExp();
//    }
//    p.display();

//    VillageDialogue vd;
//    vd.display();

    p.goToVillage();

    return 0;
}
