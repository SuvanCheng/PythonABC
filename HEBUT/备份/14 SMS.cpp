#include <iostream>

template <class T>
class Node
{
public:
    T e;
    Node *next;
};

template <class T>
class LinkedList
{
private:
    Node<T> *head;
    int size;

public:
    LinkedList()
    {
        head = new Node<T>();
        size = 0;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    void add1(T e)
    {
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

    void print()
    {
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

int main() {
    LinkedList<int> *linkedList = new LinkedList<int>();
    linkedList->add1(5);
    linkedList->print();
    linkedList->add1(6);
    linkedList->print();
    linkedList->add1(10);
    linkedList->print();
    linkedList->add1(7);
    linkedList->print();
    linkedList->add1(9);
    linkedList->print();
    linkedList->add1(1);
    linkedList->print();
    linkedList->add1(4);
    linkedList->print();
    linkedList->add1(2);
    linkedList->print();
    linkedList->add1(8);
    linkedList->print();
    linkedList->add1(3);
    linkedList->print();
    linkedList->add1(5);
    linkedList->print();
    linkedList->add1(6);
    linkedList->print();
    linkedList->add1(10);
    linkedList->print();
    return 0;
}
