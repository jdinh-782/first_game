//
// Created by jdinh on 10/2/2020.
//

#ifndef FIRST_GAME_DIALOGUE_H
#define FIRST_GAME_DIALOGUE_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <thread>

using namespace std;
using std::this_thread::sleep_for;
using std::chrono::milliseconds;

class Dialogue
{
private:
    sf::Font introFont;
    sf::Clock clock;
    sf::Time elapsedTime;

public:
    sf::Text introText;
    sf::String introDialogue;
    void printNewLine(int n);

    sf::Text returnIntroText();
    sf::String returnIntroString(int n);

    //virtual void draw(sf::RenderTarget &window, sf::RenderStates state) const;
};


#endif //FIRST_GAME_DIALOGUE_H
