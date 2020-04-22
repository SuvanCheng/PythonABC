#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

//����ṹ��
typedef struct GradeLinkList {
    string Enumber;//������
    string Name;//����
    double Math;//��ѧ�ɼ�
    double English;//Ӣ��ɼ�
    double Chinese;//���ĳɼ�
    double Sum;//�ܳɼ�
    struct GradeLinkList *next;//ָ��
} GLL,*Glist;

//�����µ�����������������
void New_LinkList(Glist L, int n) {
    int i;
    string en,na;
    double sx,yy,yw;
    Glist p;
    L->next=NULL;
    cout << "¼�뿼����Ϣ" << endl;
    cout << "--------------------------" << endl;
    for(i=n; i>0; i--)
    {
        p= (Glist)malloc(sizeof(GLL));
        cout << "��¼���" <<n-i+1<<"��������Ϣ��"<< endl;
        cout << "�������ţ�";
        cin >> en;
        p->Enumber=en;
        cout << "����������";
        cin >> na;
        p->Name=na;
        cout << "���ĳɼ���";
        cin >> yw;
        p->Chinese=yw;
        cout << "��ѧ�ɼ���";
        cin >> sx;
        p->Math=sx;
        cout << "Ӣ��ɼ���";
        cin >> yy;
        p->English=yy;
        p->Sum=yw+sx+yy;
        cout << "����ɹ�!!" << endl;
        cout << endl;
        p->next=L->next;
        L->next=p;
    }
    cout << "������Ϣ¼����ϣ��ѱ���!" << endl;
    cout << "--------------------------" << endl;
}

//�������е�Ԫ�ؽ�������
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

//�����һ����Ϣ
void Print_LinkList(Glist L)
{
    cout << endl;
    cout << "��һ����Ϣ��" << endl;
    cout << "���ţ�" <<L->next->Enumber << endl;
    cout << "������" <<L->next->Name << endl;
    cout << "���ģ�" <<L->next->Chinese <<"��"<< endl;
    cout << "��ѧ��" <<L->next->Math << "��"<<endl;
    cout << "Ӣ�" <<L->next->English <<"��"<<endl;
    cout << "�ܷ֣�" <<L->next->Sum <<"��"<<endl;
    cout<<endl;
    cout << "--------------------------" << endl;
}

//���ƽ���ɼ�
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
    cout << "����ƽ���ɼ���" <<yw/n<<"��"<< endl;
    cout << "��ѧƽ���ɼ���" <<sx/n<<"��"<< endl;
    cout << "Ӣ��ƽ���ɼ���" <<yy/n<<"��"<< endl;
    cout <<endl;
    cout << "--------------------------" << endl;
}

int main()
{
    int n;
    GLL L;
    cout << "�����뿼��������";
    cin >> n;
    New_LinkList(&L,n);
    Order_LinkList(&L,n);
    Print_LinkList(&L);
    Average_LinkList(&L,n);
    return 0;
}
