#include <stdio.h>
#include <string.h>
void main()
{
    char s[100]; // ���������ַ���
    int i, j, n;
    printf("�����ַ�����");
    gets(s);
    n = strlen(s);
    for (i = 0, j = n - 1; i < j; i++, j--)    //�� i < j ��������
        if (s[i] != s[j])    //��β�Ƚϣ���ȼ���
            break;
    if (i >= j)
        printf("�ǻ��Ĵ�\n");
    else
        printf("���ǻ��Ĵ�\n");
}
