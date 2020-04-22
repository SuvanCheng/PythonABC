#include <iostream>
#include <list>
using namespace std;

template <class T>
struct Node //�ڵ�ṹ��
{
    T data;        //����
    Node<T> *next; //ָ��
};

template <class T> //β�彨��ѭ��������
Node<T> *creat_back(Node<T> *first, int len)
{
    Node<T> *r = first;           //����βָ�� r
    for (int i = 0; i < len; i++) //����
    {
        int data;
        cin >> data;                 //����������data
        Node<T> *pnew = new Node<T>; //pnew ָ��������Ľ��
        pnew->data = data;           //��pnew->data��ֵ data
        pnew->next = r->next;        //�����½ڵ��nextָ��ͷָ��
        r->next = pnew;              //pnew���ӵ�������
        r = pnew;                    //����βָ��
    }
    r->next = first;
    return first;
}

template <class T> //�������ѭ��������
void show(Node<T> *first)
{
    Node<T> *p = first->next; //����ָ��ͷ�ڵ��ָ��
    while (p != first)        //��������
    {
        cout << p->data << ' '; //�����ָ��ָ���Ԫ��
        p = p->next;            //ָ��++
    }
    cout << endl
         << endl; //����
}

template <class T>
void DePatch(Node<T> *L1, Node<T> *L2) //����ѭ������L1���L1��L2������ѭ������
{
    L2->next = L2; //ѭ����

    Node<T> *cur = L1->next; //curָ��
    L1->next = NULL;

    Node<T> *r = L1;  //L1��βָ��
    Node<T> *r2 = L2; //L2��βָ��
    int i = 1;

    Node<T> *u = NULL;

    while (cur != L1) //����L1
    {
        if (i % 2 == 1) //����
        {
            u = cur->next; //uָ��
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
    Node<int> *first = new Node<int>; //��ʼ���ձ� first
    first->next = NULL;               //����ͷ�ڵ�Ϊ��
    Node<int> *L2 = new Node<int>;    //��ʼ���ձ� L2
    L2->next = NULL;                  //����ͷ�ڵ�Ϊ��
    first = creat_back(first, 6);     //����ѭ�������� first�����Ԫ��
    DePatch(first, L2);               //���ѭ��������Ϊ first �� L2
    show(first);                      //��ӡ first
    show(L2);                         //��ӡ L2
    return 0;
}