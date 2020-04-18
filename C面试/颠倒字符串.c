int main()
{
    char str[] = "hello,world";
    int len = strlen(str);  //获取字符串长度
    char t;  //中间变量
    for (int i = 0; i < len / 2; i++)
    {
        //首尾交换
        t = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = t;
    }
    printf("%s", str);
    return 0;
}
