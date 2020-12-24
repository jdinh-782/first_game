//
// Created by jdinh on 12/12/2020.
//
#ifndef FIRST_GAME_LINKEDLIST_CPP
#define FIRST_GAME_LINKEDLIST_CPP
#include "LinkedList.h"


template <class T>
LinkedList<T>::LinkedList()
{
    head = nullptr;
    tail = nullptr;
}


template <class T>
LinkedList<T>::LinkedList(const LinkedList& list)
{
    *this = list;
}


template<class T>
LinkedList<T>::~LinkedList()
{
    clear();
}


template<class T>
Node<T>* LinkedList<T>::createNode(T item)
{
    auto* n = new Node<T>;
    n->data = item;
    n->next = nullptr;
    n->prev = nullptr;
    return n;
}


template<class T>
void LinkedList<T>::clear()
{
    Node<T>* object = head;
    Node<T>* previous;

    while (object != nullptr)
    {
        previous = object;
        object = object->next;
        delete previous;
        size--;
    }
    head = nullptr;
    tail = nullptr;
}


template <class T>
void LinkedList<T>::changeHeadValue(T data)
{
    head->data = data;
}


template <class T>
void LinkedList<T>::changeMiddleValue(T data)
{
    head->next->data = data;
}


template <class T>
void LinkedList<T>::changeTailValue(T data)
{
    tail->data = data;
}


template<class T>
bool LinkedList<T>::insertFirst(Node<T>* node)
{
    if (head == nullptr)
    {
        head = node;
        tail = node;
        size++;
        return true;
    }
    return false;
}


template <class T>
bool LinkedList<T>::empty()
{
    if (head == nullptr && tail == nullptr)
    {
        return true;
    }
    return false;
}


template<class T>
void LinkedList<T>::operator += (T item)
{
    Node<T>* temp = createNode(item);

    if (!insertFirst(temp))
    {
        tail->next = temp;
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
        size++;
    }
}


template <class T>
T LinkedList<T>::headValue()
{
    return head->data;
}


template <class T>
T LinkedList<T>::tailValue()
{
    return tail->data;
}


//only returns the middle data (mana potion)
template <class T>
T LinkedList<T>::returnData()
{
    return head->next->data;
}


template<class S>
ostream& operator << (ostream& outs, const LinkedList<S>& l)
{
    for (Node<S>* object = l.head; object != nullptr; object = object->next)
    {
        outs << object->data << " ";
    }
    return outs;
}


#endif //FIRST_GAME_LINKEDLIST_CPP