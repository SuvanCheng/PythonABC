#include <stdio.h>
struct Student
{
    int num;
    char name[20];
    float score;
};
int main()
{
   struct Student stu[5] = {{101,"Mike",89.23},{102,"lucy",98.23},{103,"minky",95.23},{104,"mijlh",90.23},{105,"mghky",89.23}};
   struct Student temp;
   int n = 5;
   int i,j,k;
   printf("The order is\n");
   for(i=0;i<n-1;i++)
   {
       k = i;
       for(j=i+1;j<n;j++)
       {
            if(stu[k].score>stu[j].score)
               {
                    temp = stu[k];
                    stu[k]=stu[j];
                    stu[j]=temp;
               }
        }
    }
    for(i=0;i<5;i++)
    {
        printf("学号 %5d 姓名 %8s 分数 %6.2f\n",stu[i].num,stu[i].name,stu[i].score);
    }
}

