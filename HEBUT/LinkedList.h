//
// Created by Allen on 22/4/2020.
//

#ifndef HEBUT_LINKEDLIST_H
#define HEBUT_LINKEDLIST_H

#include <iostream>

using namespace std;

template <class T>
struct Node{
    T e;
    Node *next;
};

template <class T>
class LinkedList{
    Node<T> *head;
    int size;

public:
    LinkedList(){
        head = new Node<T>();
        size = 0;
    }

    int getSize(){
        return size;
    }

    bool isEmpty(){
        return size == 0;
    }

    void add1(T e){
        Node<T> *prev = head;
        Node<T> *cur = head->next;

        Node<T> *_new = new Node<T>;
        _new->e = e;

        while (cur && cur->e < e){
            prev = cur;
            cur = cur->next;
        }

        _new->next = cur;
        prev->next = _new;
        size++;
    }

    void print(){
        Node<T> *prev = head;
        std::cout << "LinkedList: size = " << size << std::endl;
        std::cout << "[";
        for (int i = 0; i < size; ++i)
        {
            prev = prev->next;
            std::cout << prev->e;
            if (i < size - 1)
            {
                std::cout << "->";
            }
        }
        std::cout << "]" << std::endl;
    }
};

#endif //HEBUT_LINKEDLIST_H
