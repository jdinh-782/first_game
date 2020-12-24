cmake_minimum_required(VERSION 3.17)
project(first_game)

set(CMAKE_CXX_STANDARD 14)

add_executable(first_game main.cpp Dialogue.cpp Dialogue.h IntroDialogue.cpp IntroDialogue.h BattleSystem.cpp BattleSystem.h LinkedList.cpp LinkedList.h Node.h Items.cpp Items.h Spells.cpp Spells.h LevelCoinsExperience.cpp LevelCoinsExperience.h Player.cpp Player.h VillageDialogue.cpp VillageDialogue.h Village.cpp Village.h Validity.cpp Validity.h)