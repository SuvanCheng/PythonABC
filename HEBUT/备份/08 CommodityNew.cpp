#include <iostream>
#include <string>
#include <iomanip>

struct Goods {
    std::string m_Name;
    float m_Price;
    size_t m_Quantity;
    Goods* next;
    //Goods(std::string Name, float Price, size_t Quantity, Goods* next) : m_Name(Name), m_Price(Price), m_Quantity(Quantity), next(next) {
    //}
    //Goods(std::string Name, float Price, size_t Quantity) : m_Name(Name), m_Price(Price), m_Quantity(Quantity), next(nullptr) {
    //}
    //Goods(){
    //}
};


class LinkedList
{
public:
	LinkedList();
	~LinkedList();
    bool contains(std::string Name);
    void orderAdd(std::string Name, float Price, size_t Quantity);
    void toFind(std::string Name);
    void toFind(float Price);
    void toFind(size_t Quantity);
    void PrintCur(Goods* cur);
    void PrintAll();

private:
    Goods* head;
    int size;
};

LinkedList::LinkedList()
{
    head = new Goods();  //head是指针类型 Goods*
    size = 0;
}
LinkedList::~LinkedList()
{
    delete head;
}
bool LinkedList::contains(std::string Name)
{
    Goods* cur = head;  //cur指向链头
    for (int i = 0; i < size; ++i) {
        cur = cur->next;
        if (cur->m_Name == Name)
            return true;
    }
    return false;
}
void LinkedList::orderAdd(std::string Name, float Price, size_t Quantity)
{
    Goods* _new = new Goods;//在堆里新定义一个空结点：_new
    _new->m_Name = Name;
    _new->m_Price = Price;
    _new->m_Quantity = Quantity;
    _new->next = NULL;  //结点赋值完成

    if (size == 0) {
        head->next = _new;
        size++;
        return;
    }
    if (contains(Name))
        return;
    Goods* pre = head;      //pre指向头节点
    Goods* cur = head->next;//cur指向次结点

    while (cur && cur->m_Price < Price)  //只要 下一个结点 小于 新结点 就持续遍历；并且 cur 不能为空
    {
        pre = cur;       //更新后行指针
        cur = cur->next; //更新先行指针
    }
    _new->next = cur;    //新结点 指向 后链表
    pre->next = _new;    //前链表 指向 新结点
    size++;              //更新链表长度
}
void LinkedList::toFind(std::string Name)
{
    Goods* cur = head;  //cur指向链头
    bool flag = 1;
    for (int i = 0; i < size; ++i) {
        cur = cur->next; //cur指向头节点，并随循环逐一指向
        if (cur->m_Name == Name) {
            flag = 0;
            PrintCur(cur);
        }
    }
    if (flag)
        std::cout << "This Item does't exist!" << std::endl;
}
void LinkedList::toFind(float Price)
{
    Goods* cur = head;  //cur指向链头
    bool flag = 1;
    for (int i = 0; i < size; ++i) {
        cur = cur->next; //cur指向头节点，并随循环逐一指向
        if (cur->m_Price == Price) {
            flag = 0;
            PrintCur(cur);
        }
    }
    if (flag)
        std::cout << "This Item does't exist!" << std::endl;
}
void LinkedList::toFind(size_t Quantity)
{
    Goods* cur = head;  //cur指向链头
    bool flag = 1;
    for (int i = 0; i < size; ++i) {
        cur = cur->next; //cur指向头节点，并随循环逐一指向
        if (cur->m_Quantity == Quantity) {
            flag = 0;
            PrintCur(cur);
        }
    }
    if(flag)
        std::cout << "This Item does't exist!" << std::endl;
}
void LinkedList::PrintCur(Goods* cur)
{
        std::cout << "Name: " << std::setw(10) << cur->m_Name;
        std::cout << "\tPrice: " << std::setw(10) << cur->m_Price;
        std::cout << "\tQuantity: " << std::setw(10) << cur->m_Quantity << std::endl;
}
void LinkedList::PrintAll()
{
    Goods* cur = head;
    std::cout << "LinkedList: size = " << size << std::endl;
    for (int i = 0; i < size; ++i)
    {
        cur = cur->next;
        PrintCur(cur);
    }
    std::cout << std::endl;
}
void Input(int n, LinkedList* L) {
    std::string Name;
    float Price;
    size_t Quantity;
    for (int i = 0; i < n; ++i) {
        std::cout << "Please Input Commodity " << i + 1 << std::endl;
        std::cout << "    Name: ";
        std::cin >> Name;
        std::cout << "   Price: ";
        std::cin >> Price;
        std::cout << "Quantity: ";
        std::cin >> Quantity;
        L->orderAdd(Name, Price, Quantity);
    }
}
void Print(LinkedList* L) {
    L->PrintAll();
    char n;
    std::cout << "Press any key to continue";
    std::cin >> n;
    if (n != '%')
    {
        return;
    }
}
void Find(LinkedList* L) {
    std::cout << "\n\n";
    std::cout << "                               ☆   Find   ☆" << std::endl;
    std::cout << "                           ▇▇▇▇▇▇▇▇▇▇▇" << std::endl;
    std::cout << "                           ★                  ★" << std::endl;
    std::cout << "                           ★    1. Name       ★" << std::endl;
    std::cout << "                           ★    2. Price      ★" << std::endl;
    std::cout << "                           ★    3. Quantity   ★" << std::endl;
    std::cout << "                           ★    0. Back       ★" << std::endl;
    std::cout << "                           ★                  ★" << std::endl;
    std::cout << "                           ▇▇▇▇▇▇▇▇▇▇▇";
    char n;
    std::cin >> n;
    std::string Name;
    float Price;
    size_t Quantity;
    switch (n)
    {
    case '1':
        std::cout << "Please Input the name you are looking for: ";
        std::cin >> Name;
        L->toFind(Name);
        std::cout << "Press any key to continue";
        std::cin >> n;
        if (n != '%')
        {
            return;
        }
    case '2':
        std::cout << "Please Input the Price you are looking for: ";
        std::cin >> Price;
        L->toFind(Price);
        std::cout << "Press any key to continue";
        std::cin >> n;
        if (n != '%')
        {
            return;
        }
    case '3':
        std::cout << "Please Input the Quantity you are looking for: ";
        std::cin >> Quantity;
        L->toFind(Quantity);
        std::cout << "Press any key to continue";
        std::cin >> n;
        if (n != '%')
        {
            return;
        }
    default:
        break;
    }
}

int main()
{
    LinkedList* L = new LinkedList();
    char x;
    int n;
    while (1)
    {
        system("cls");
        std::cout << "\n\n\n\n\n\n";
        std::cout << "                              ☆ Storehouse ☆" << std::endl;
        std::cout << "                           ▇▇▇▇▇▇▇▇▇▇▇" << std::endl;
        std::cout << "                           ★                  ★" << std::endl;
        std::cout << "                           ★    1. Input      ★" << std::endl;
        std::cout << "                           ★    2. Print      ★" << std::endl;
        std::cout << "                           ★    3. Find       ★" << std::endl;
        std::cout << "                           ★    4. Delete     ★" << std::endl;
        std::cout << "                           ★    0. Exit       ★" << std::endl;
        std::cout << "                           ★                  ★" << std::endl;
        std::cout << "                           ▇▇▇▇▇▇▇▇▇▇▇";
        std::cin >> x;
        switch (x)
        {
        case '0':
            exit(0);
        case '1':
            system("cls");
            std::cout << "How many items do you need to enter? : ";
            std::cin >> n;
            if (n < 0 || n>20)
                n = 3;
            Input(n, L);
            break;
        case '2':
            system("cls");
            Print(L);
            break;
        case '3':
            system("cls");
            Find(L);
            break;
        case '4':
            break;
        }
    }
       
    return 0;
}
