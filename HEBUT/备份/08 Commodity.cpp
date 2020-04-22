#include <iostream>
#include <string>

class Node
{
public:
    std::string Name;
    float Price;
    size_t Quantity;
    Node *next;
};

class LinkedList
{
private:
    Node *head;
    int size;

public:
    LinkedList()
    {
        head = new Node();
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

    void Sequenceadd(std::string Name, float Price, size_t Quantity)
    {
        if (contains(Name))
        {
            std::cout << "The name is occupied" << std::endl;
        }
        else
        {
            Node *prev = head;
            Node *cur = head->next;

            Node *_new = new Node;
            _new->Name = Name;
            _new->Price = Price;
            _new->Quantity = Quantity;

            while (cur && cur->Price < Price)
            {
                prev = cur;
                cur = cur->next;
            }
            _new->next = cur;
            prev->next = _new;
            size++;
        }
    }

    bool contains(std::string Name)
    {
        Node *cur = head;
        for (int i = 0; i < size; ++i)
        {
            cur = cur->next;
            if (cur->Name == Name)
            {
                return true;
            }
        }
        return false;
    }
    void find(std::string Name)
    {
        Node *cur = head;
        bool flag = 1;
        for (int i = 0; i < size; ++i)
        {
            cur = cur->next;
            if (cur->Name == Name)
            {
                flag = 0;
                PrintCur(cur);
            }
        }
        if (flag)
        {
            std::cout << "This Name does not exist" << std::endl;
        }
    }
    void find(float Price)
    {
        Node *cur = head;
        bool flag = 1;
        for (int i = 0; i < size; ++i)
        {
            cur = cur->next;
            if (cur->Price == Price)
            {
                flag = 0;
                PrintCur(cur);
            }
        }
        if (flag)
        {
            std::cout << "This Price does not exist" << std::endl;
        }
    }
    void find(size_t Quantity)
    {
        Node *cur = head;
        bool flag = 1;
        for (int i = 0; i < size; ++i)
        {
            cur = cur->next;
            if (cur->Quantity == Quantity)
            {
                flag = 0;
                PrintCur(cur);
            }
        }
        if (flag)
        {
            std::cout << "This Quantity does not exist" << std::endl;
        }
    }

    void PrintCur(Node *cur)
    {
        std::cout << "Name: " << cur->Name;
        std::cout << " Price: " << cur->Price;
        std::cout << " Quantity: " << cur->Quantity << std::endl;
    }

    void PrintAll()
    {
        Node *prev = head;
        std::cout << "LinkedList: size = " << size << std::endl;
        for (int i = 0; i < size; ++i)
        {
            prev = prev->next;
            PrintCur(prev);
        }
        std::cout << std::endl;
    }
};

int main()
{
    LinkedList *linkedList = new LinkedList();
    std::string Name;
    float Price;
    size_t Quantity;
    for (int i = 1; i <= 4; i++)
    {
        std::cout << "Please Input Commodity " << i << std::endl;
        std::cout << "Name: ";
        std::cin >> Name;
        std::cout << "Price: ";
        std::cin >> Price;
        std::cout << "Quantity: ";
        std::cin >> Quantity;
        linkedList->Sequenceadd(Name, Price, Quantity);
        linkedList->PrintAll();
    }
    std::cout << "Please Input the name you are looking for: ";
    std::cin >> Name;
    linkedList->find(Name);
    std::cout << "Please Input the Price you are looking for: ";
    std::cin >> Price;
    linkedList->find(Price);
    std::cout << "Please Input the Quantity you are looking for: ";
    std::cin >> Quantity;
    linkedList->find(Quantity);
    return 0;
}
