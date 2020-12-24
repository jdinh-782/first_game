//
// Created by jdinh on 12/12/2020.
//

#include "IntroDialogue.h"


IntroDialogue::IntroDialogue()
= default;


void IntroDialogue::display()
{
    cout << "The wind blows by... "; Validity::pressEnterKey();
    cout << "The leaves rustle in response... "; Validity::pressEnterKey();
    cout << "The air is cold... "; Validity::pressEnterKey();
    cout << "You feel cold... "; Validity::pressEnterKey();
    cout << "\n(You): Owww...my...head... "; Validity::pressEnterKey();
    cout << "(You): Whe...Where...Where am I? "; Validity::pressEnterKey();
    cout << "\n\nYou stare out at the open grass, filled with game that you have never seen before. "; Validity::pressEnterKey();
    cout << "\n\n(You): Man...What am I doing here? Matter of fact...who...am I? "; Validity::pressEnterKey();
    cout << "(You): N...Never mind that. I need to go find food and shelter. "; Validity::pressEnterKey();
    cout << "\n\nYou begin to roam around, looking at the vast majority of land. "; Validity::pressEnterKey();
    cout << "You see something shining behind a stone as its gaze mysteriously sets upon you. "; Validity::pressEnterKey();
    cout << "You notice it is a sword and without hesitation, you retrieve it. "; Validity::pressEnterKey();
    cout << "\n\n-> Obtained \"Mysterious Sword\" "; Validity::pressEnterKey();
    cout << "\n\nYou continue to move on while looking at the scenery. "; Validity::pressEnterKey();
    cout << "From a distance, you see an old man sitting on top a rock... "; Validity::pressEnterKey();
    cout << "The man is bothered by your sword and inspects it inescapably. "; Validity::pressEnterKey();
    cout << "\n\n(Old Man): My child! You must be the chosen one! "; Validity::pressEnterKey();
    cout << "\n(You): Excuse me??? "; Validity::pressEnterKey();
    cout << "\n(Old Man): You have the magical sword that was lost from the Valapolic War! YOU ARE OUR SAVIOR! "; Validity::pressEnterKey();
    cout << "\n(You): Uhhhhh...Whatever you say grandpa! "; Validity::pressEnterKey();
    cout << "\n\nYou leave him, unbothered by the old man's loud chants. "; Validity::pressEnterKey();

    cout << endl << endl;
    for (int i = 0; i < 3; i++)
	{
    	cout << "(Old Man): OUR SAVIOR!!! OUR SAVIOR!!! THE LORD HAS BLESSED US!!! "; Validity::pressEnterKey();
	}

	cout << "\n\nAs you continue roaming around, looking for amenities, you notice something awfully unfamiliar. "; Validity::pressEnterKey();
	cout << "You look at the bears closer and realize...they aren't real animals??? "; Validity::pressEnterKey();
	cout << "These creatures look like demons as they have bat-like wings and razor sharp claws! "; Validity::pressEnterKey();
	cout << "One of the creatures begin to run towards you! You quickly draw out your sword! "; Validity::pressEnterKey();
	cout << endl << endl << endl;
}