//
// Created by jdinh on 10/2/2020.
//

#include "Dialogue.h"

void Dialogue::printNewLine(int n)
{
    cout << string(n, '\n') << endl;
}


sf::Text Dialogue::returnIntroText()
{
    if (!introFont.loadFromFile("arialbd.ttf"))
    {
        exit(1);
    }

    introText.setFont(introFont);
    introText.setFillColor(sf::Color::White);
    introText.setCharacterSize(30);
    introText.setPosition(5, 300);

    return introText;
}


sf::String Dialogue::returnIntroString(int n)
{
    if (n == 1)
    {
        introDialogue = "This game is intended for entertainment purposes only.\n";
    }

    else if (n == 2)
    {
        introDialogue = "This game does not influence any type of murder nor does it condone violence.\n";
    }

    else if (n == 3)
    {
        introDialogue = "Please be aware of the decisions you make in this game as you only have one life...\n";
    }

    return introDialogue;
}