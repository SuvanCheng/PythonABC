#include <stdio.h>
#include <string.h>
int main(){
     char snum1[1024], snum2[1024], sop1[1024] = "0", sop2[1024];
     int len, len1, len2, opsign = 0;
     printf("输入两个操作数:\n");
     scanf("%s\n%s", snum1, snum2);
     len1 = strlen(snum1);
     len2 = strlen(snum2);
     if (len1 >= len2)
     {
          strcat(sop1, snum1);//连接sop1 snum1
          strcpy(sop2, snum2);//复制snum2 到 sop2
          len = len1 + 1;
     }
     else
     {
          strcat(sop1, snum2);
          strcpy(sop2, snum1);
          len = len2 + 1;
     }
     for (int i = 0; i != len; i++)
     {
          int k = sop1[strlen(sop1) - 1 - i] - '0';
          int m;
          if (i >= strlen(sop2))
               m = 0;
          else
               m = sop2[strlen(sop2) - 1 - i] - '0';
          if (opsign)
               k++;
          int n = k + m;
          if (n >= 10)
          {
               opsign = 1;
               n = n - 10;
          }
          else
          {
               opsign = 0;
          }
          sop1[strlen(sop1) - 1 - i] = n + '0';
     }
     char *p = sop1;
     if (sop1[0] == '0')
          printf("两个操作数之和为:\n%s", ++p);
     else
          printf("两个操作数之和为:\n%s", p);
     getchar();
     getchar();
     return 0;
}
