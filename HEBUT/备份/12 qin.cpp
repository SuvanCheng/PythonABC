#include <iostream>
#include <stdio.h>
#include <malloc.h>
using namespace std;

//创建结构体
typedef struct DLinkList
{
    int data;
    struct DLinkList *next;
} DLL, *Dlist;

//创建链表
void New_LinkList(Dlist L, int n)
{
    int i, m;
    Dlist p;
    p = L->next;
    cout << "创建成功，请输入数据!!" << endl;
    cout << "-------------------" << endl;
    for (i = n; i > 0; i--)
    {
        p = (Dlist)malloc(sizeof(DLL));
        cin >> m;
        p->data = m;
        cout << "数据[" << n - i + 1 << "]输入成功," << i - 1 << "个数据待输入!" << endl;
        p->next = L->next;
        L->next = p;
    }
    cout << "-------------------" << endl;
    cout << "输入完毕!" << endl;
}

//给链表中元素排序
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

//输出链表中的信息
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

//插入数据
void Insert_LinkList(Dlist L)
{
    Dlist p;
    p = (Dlist)malloc(sizeof(DLL));
    int m;
    cout << "请输入要插入的数据：";
    cin >> m;
    p->data = m;
    p->next = L->next;
    L->next = p;
}

int main()
{
    int n;
    DLL L;
    cout << "请创建链表，您需要输入数据的个数：";
    cin >> n;
    cout << endl;
    New_LinkList(&L, n);

    Order_LinkList(&L, n);
    cout << "排序过之后的序列为：" << endl;
    Print_LinkList(&L, n);
    Insert_LinkList(&L);
    Order_LinkList(&L, n + 1);
    cout << "插入过之后的序列为：" << endl;
    Print_LinkList(&L, n + 1);
    return 0;
}
