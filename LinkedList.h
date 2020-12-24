//
// Created by jdinh on 12/12/2020.
//

#ifndef FIRST_GAME_LINKEDLIST_H
#define FIRST_GAME_LINKEDLIST_H

#include "Node.h"
#include <iostream>

using namespace std;


template <class T>
class LinkedList
{
private:
    Node<T>* head;
    Node<T>* tail;

    int size = 0;

    static Node<T>* createNode(T item);

public:
    LinkedList();
    LinkedList(const LinkedList& list);
    ~LinkedList();

    bool insertFirst(Node<T>* node);
    bool empty();

    void clear();
    void changeHeadValue(T data);
    void changeMiddleValue(T data);
    void changeTailValue(T data);

    void operator += (T item);

    T headValue();
    T tailValue();
    T returnData();

    template <class S>
    friend ostream& operator << (ostream& outs, const LinkedList<S>& l);
};


#include "LinkedList.cpp"

#endif //FIRST_GAME_LINKEDLIST_H
