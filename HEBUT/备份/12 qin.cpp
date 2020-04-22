#include <iostream>
#include <stdio.h>
#include <malloc.h>
using namespace std;

//�����ṹ��
typedef struct DLinkList
{
    int data;
    struct DLinkList *next;
} DLL, *Dlist;

//��������
void New_LinkList(Dlist L, int n)
{
    int i, m;
    Dlist p;
    p = L->next;
    cout << "�����ɹ�������������!!" << endl;
    cout << "-------------------" << endl;
    for (i = n; i > 0; i--)
    {
        p = (Dlist)malloc(sizeof(DLL));
        cin >> m;
        p->data = m;
        cout << "����[" << n - i + 1 << "]����ɹ�," << i - 1 << "�����ݴ�����!" << endl;
        p->next = L->next;
        L->next = p;
    }
    cout << "-------------------" << endl;
    cout << "�������!" << endl;
}

//��������Ԫ������
void Order_LinkList(Dlist L, int n)
{
    int i, j;
    Dlist r;
    Dlist p;
    Dlist q;
    r = L;
    p = L->next;
    q = p->next;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if ((p->data) > (q->data))
            {
                r->next = q;
                p->next = q->next;
                q->next = p;
                q = p;
                p = r->next;
            }
            q = q->next;
            p = p->next;
            r = r->next;
        }
        r = L;
        p = L->next;
        q = p->next;
    }
    cout << n << endl;
}

//��������е���Ϣ
void Print_LinkList(Dlist L, int n)
{
    int i;
    Dlist p;
    p = L->next;
    for (i = 0; i < n; i++)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

//��������
void Insert_LinkList(Dlist L)
{
    Dlist p;
    p = (Dlist)malloc(sizeof(DLL));
    int m;
    cout << "������Ҫ��������ݣ�";
    cin >> m;
    p->data = m;
    p->next = L->next;
    L->next = p;
}

int main()
{
    int n;
    DLL L;
    cout << "�봴����������Ҫ�������ݵĸ�����";
    cin >> n;
    cout << endl;
    New_LinkList(&L, n);

    Order_LinkList(&L, n);
    cout << "�����֮�������Ϊ��" << endl;
    Print_LinkList(&L, n);
    Insert_LinkList(&L);
    Order_LinkList(&L, n + 1);
    cout << "�����֮�������Ϊ��" << endl;
    Print_LinkList(&L, n + 1);
    return 0;
}
