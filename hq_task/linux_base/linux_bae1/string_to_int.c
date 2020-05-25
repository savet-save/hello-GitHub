#include <stdio.h>

//指定字符串转换为数字
int string_to_int(const char *str);

int main(int argc, char const *argv[])
{
    printf("%d\n", string_to_int("1234567"));
    return 0;
}


int string_to_int(const char *str)
{
    int num = 0;
    if(str == NULL)
    {
        return 0;
    }
    while (*str != '\0')
    {
        num = num * 10 + *str - '0';
        str++;
    }
    return num;
}
