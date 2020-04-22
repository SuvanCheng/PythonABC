#include <iostream>
#include <list>
using namespace std;

template <class T>
struct Node //节点结构体
{
    T data;        //数据
    Node<T> *next; //指针
};

template <class T> //尾插建立循环单链表
Node<T> *creat_back(Node<T> *first, int len)
{
    Node<T> *r = first;           //增加尾指针 r
    for (int i = 0; i < len; i++) //遍历
    {
        int data;
        cin >> data;                 //键入新数据data
        Node<T> *pnew = new Node<T>; //pnew 指向新申请的结点
        pnew->data = data;           //给pnew->data赋值 data
        pnew->next = r->next;        //更新新节点的next指向头指针
        r->next = pnew;              //pnew连接到链表上
        r = pnew;                    //更新尾指针
    }
    r->next = first;
    return first;
}

template <class T> //输出链表循环单链表
void show(Node<T> *first)
{
    Node<T> *p = first->next; //定义指向头节点的指针
    while (p != first)        //遍历链表
    {
        cout << p->data << ' '; //输出该指针指向的元素
        p = p->next;            //指针++
    }
    cout << endl
         << endl; //换行
}

template <class T>
void DePatch(Node<T> *L1, Node<T> *L2) //将单循环链表L1拆成L1和L2两个单循环链表
{
    L2->next = L2; //循环化

    Node<T> *cur = L1->next; //cur指向
    L1->next = NULL;

    Node<T> *r = L1;  //L1的尾指针
    Node<T> *r2 = L2; //L2的尾指针
    int i = 1;

    Node<T> *u = NULL;

    while (cur != L1) //遍历L1
    {
        if (i % 2 == 1) //奇数
        {
            u = cur->next; //u指向
            cur->next = L1;
            r->next = cur;
            r = cur;
            cur = u;
            i++;
        }
        else
        {
            u = cur->next;
            cur->next = L2;
            r2->next = cur;
            r2 = cur;
            cur = u;
            i++;
        }
    }
}

int main()
{
    Node<int> *first = new Node<int>; //初始化空表 first
    first->next = NULL;               //定义头节点为空
    Node<int> *L2 = new Node<int>;    //初始化空表 L2
    L2->next = NULL;                  //定义头节点为空
    first = creat_back(first, 6);     //建立循环单链表 first，五个元素
    DePatch(first, L2);               //拆分循环单链表为 first 与 L2
    show(first);                      //打印 first
    show(L2);                         //打印 L2
    return 0;
}