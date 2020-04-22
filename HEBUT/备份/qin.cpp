#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

//定义结构体
typedef struct GradeLinkList {
    string Enumber;//考生号
    string Name;//姓名
    double Math;//数学成绩
    double English;//英语成绩
    double Chinese;//语文成绩
    double Sum;//总成绩
    struct GradeLinkList *next;//指针
} GLL,*Glist;

//创建新的链表，并定义链表长度
void New_LinkList(Glist L, int n) {
    int i;
    string en,na;
    double sx,yy,yw;
    Glist p;
    L->next=NULL;
    cout << "录入考生信息" << endl;
    cout << "--------------------------" << endl;
    for(i=n; i>0; i--)
    {
        p= (Glist)malloc(sizeof(GLL));
        cout << "请录入第" <<n-i+1<<"个考生信息！"<< endl;
        cout << "考生考号：";
        cin >> en;
        p->Enumber=en;
        cout << "考生姓名：";
        cin >> na;
        p->Name=na;
        cout << "语文成绩：";
        cin >> yw;
        p->Chinese=yw;
        cout << "数学成绩：";
        cin >> sx;
        p->Math=sx;
        cout << "英语成绩：";
        cin >> yy;
        p->English=yy;
        p->Sum=yw+sx+yy;
        cout << "保存成功!!" << endl;
        cout << endl;
        p->next=L->next;
        L->next=p;
    }
    cout << "所有信息录入完毕，已保存!" << endl;
    cout << "--------------------------" << endl;
}

//对链表中的元素进行排序
void Order_LinkList(Glist L,int n)
{
    int i,j;
    Glist r,p,q;
    r=L;
    p=L->next;
    q=p->next;
    for(i=0; i<n-1; i++)
    {
        for(j=0; j<n-i-1; j++)
        {
            if((p->Sum)<(q->Sum))
            {
                r->next=q;
                p->next=q->next;
                q->next=p;
                q=p;
                p=r->next;
            }
            r=r->next;
            p=p->next;
            q=q->next;
        }
        r=L;
        p=L->next;
        q=p->next;
    }
}

//输出第一名信息
void Print_LinkList(Glist L)
{
    cout << endl;
    cout << "第一名信息：" << endl;
    cout << "考号：" <<L->next->Enumber << endl;
    cout << "姓名：" <<L->next->Name << endl;
    cout << "语文：" <<L->next->Chinese <<"分"<< endl;
    cout << "数学：" <<L->next->Math << "分"<<endl;
    cout << "英语：" <<L->next->English <<"分"<<endl;
    cout << "总分：" <<L->next->Sum <<"分"<<endl;
    cout<<endl;
    cout << "--------------------------" << endl;
}

//输出平均成绩
void Average_LinkList(Glist L,int n)
{
    int i;
    double yw=0,sx=0,yy=0;
    Glist p;
    p=L->next;
    cout << endl;
    for(i=n; i>0; i--)
    {
        yw+=p->Chinese;
        sx+=p->Math;
        yy+=p->English;
        p=p->next;
    }
    cout << "语文平均成绩：" <<yw/n<<"分"<< endl;
    cout << "数学平均成绩：" <<sx/n<<"分"<< endl;
    cout << "英语平均成绩：" <<yy/n<<"分"<< endl;
    cout <<endl;
    cout << "--------------------------" << endl;
}

int main()
{
    int n;
    GLL L;
    cout << "请输入考生个数：";
    cin >> n;
    New_LinkList(&L,n);
    Order_LinkList(&L,n);
    Print_LinkList(&L);
    Average_LinkList(&L,n);
    return 0;
}
