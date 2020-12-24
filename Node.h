//
// Created by jdinh on 12/12/2020.
//

#ifndef FIRST_GAME_NODE_H
#define FIRST_GAME_NODE_H


template <class T>
struct Node
{
    T data;
    Node* next;
    Node* prev;
};

#endif //FIRST_GAME_NODE_H
