#include <stdio.h>

int string_to_int(const char *str, int *ret_int);

int main(int argc, char const *argv[])
{
    char *a = "12345";
    int i;
    string_to_int(a , &i);
    printf("%d\n", i);
    return 0;
}

int string_to_int(const char *str, int *ret_int)
{
    int temp_int = 0;//暂存返回结果
    int carry = 1;//进位
    int len = 0;//判断长度
    if(str == NULL)//错误参数的处理
    {
        return -1;
    }
    while(*str != '\0')//获得尾指针,指向'\0'
    {
        str++;
        len++;
    }
    str--;//指向'\0'前一个字符
    while(len > 0)
    {
        if(*str >= '0' && *str <= '9')//转换为字符串
        {
            temp_int = temp_int + (*str - '0') * carry;
            carry = carry * 10;
        }
        str--;
        len--;
    }
    //成功返回
    *ret_int = temp_int;
    return 0;
}
