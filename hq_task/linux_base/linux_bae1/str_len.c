#include <stdio.h>

int str_len(const char *p, int *ret_num, int *ret_let);

int main(int argc, char const *argv[])
{
    char *a = "test 123";
    int n;
    int l;
    str_len(a, &n, &l);
    printf("%d,%d\n", n, l);
    return 0;
}

int str_len(const char *p, int *ret_num, int *ret_let)
{
    int number = 0;//存放数字个数
    int letter = 0;//存放字母个数
    if(p == NULL || ret_num == NULL || ret_let == NULL)//无效参数的处理
    {
        return -1;
    }
    while(*p != '\0')//统计个数
    {
        if((*p >= 'a' && *p <= 'z') || (*p >= 'A' && *p <= 'Z'))//字母的情况
        {
            letter++;
        }
        else if(*p >= '0' && *p <= '9')//数字的情况
        {
            number++;
        }
        p++;
    }
    //返回结果
    *ret_num = number;
    *ret_let = letter;
    return 0;
}