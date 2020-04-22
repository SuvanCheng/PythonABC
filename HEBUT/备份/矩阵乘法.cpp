//��������࣬���س˷�������
//���ߣ�nuaazdh
//ʱ�䣺2011��12��1��

#include <iostream>
#include <cstdlib>

using namespace std;

//Matrix������
class Matrix
{
public:
    Matrix(int mm, int nn)//���캯��
    {
        m=mm;
        n=nn;
        int i,j;
        data=new double*[mm];
        for(i=0;i<mm;i++)
            data[i]=new double[nn];
        for(i=0;i<m;i++)//��������Ԫ������
            for(j=0;j<n;j++)
                data[i][j]=0.0;
    } //����M��N�еľ���

    Matrix(const Matrix &src) //�������캯��
    {
        m=src.m;
        n=src.n;
          int i,j;
        data=new double*[m];//��̬������ά����
        for(i=0;i<m;i++)
            data[i]=new double[n];
        for(i=0;i<m;i++)//��̬���鸳ֵ
            for(j=0;j<n;j++)
                data[i][j]=src.data[i][j];
    }

    ~Matrix()//��������
    {
        for(int i=0;i<m;i++)
            delete []data[i];
        delete []data;
    }
    Matrix& operator=(const Matrix &src);//����"="�����
    Matrix operator * (const Matrix &m2); //����˷�
    void display();
    void input();
    private:
        double **data;
    int m,n;//���������������
};//�ඨ�����

Matrix& Matrix::operator=(const Matrix &src) //����"="�����
{
    int i,j;
    for(i=0;i<m;i++)
        delete []data[i];
    delete []data;
    m=src.m;n=src.n;
    data=new double*[m];//��̬������ά����
    for(i=0;i<m;i++)
        data[i]=new double[n];
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            data[i][j]=src.data[i][j];
    return *this;
}

//����*���������
Matrix Matrix::operator *(const Matrix &m2)//����˷���ʵ��
{
    Matrix m3(this->m,m2.n);
    if(this->n!=m2.m)
    {
        cout<<"�������޷����г˷�����.\n"<<endl;
        exit(0);
    }
    int i,j,k,l;
    for(i=0;i<this->m;i++)
        for(j=0;j<m2.n;j++)
        {
            for(k=0;k<this->n;k++)
             {
                m3.data[i][j]+=this->data[i][k]*m2.data[k][j];
             }

        }
    return m3;
}

//�������Ԫ��
void Matrix::input()
{
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            cin>>data[i][j];
}

//��ʾ����Ԫ��
void Matrix::display()
{
    int i,j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<data[i][j]<<" ";
        }
        cout<<endl;
    }
}

//������
int main(int argc, char* argv[])
{
    int x,y;
    cout<<"����1����:";
    cin>>x;
    cout<<"����1����:";
    cin>>y;
    Matrix A(x,y);
    cout<<"���������1Ԫ�أ����У���"<<x*y<<" ����"<<endl;
    A.input();
    cout<<"����1��"<<endl;
    A.display();
    cout<<"����2����:";
    cin>>x;
    cout<<"����2����:";
    cin>>y;
    Matrix B(x,y);
    cout<<"���������2Ԫ�أ����У���"<<x*y<<" ����"<<endl;
    B.input();
    cout<<"����2��"<<endl;
    B.display();
    Matrix C=A*B;
    cout<<"����1 �� ����2 �ĳ˻���"<<endl;
    C.display();
    return 0;
}
