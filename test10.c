#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int myAtoi(char * str);

int main(int argc, char const *argv[])
{
    printf("%d\n", myAtoi("10"));
    return 0;
}

#define MY_INT_MAX 2147483647
#define MY_INT_MIN -2147483648
int myAtoi(char * str){
    int num = 0;
    int flag = 0;//还没有处理数字
    while(*str != 0)
    {
        if(*str >= '0' && *str <= '9')
        {
            if((long)num*10 + (*str - '0')*flag > MY_INT_MAX)
                return MY_INT_MAX;
            if((long)num*10 + (*str - '0')*flag < MY_INT_MIN)
                return MY_INT_MIN;
            if(flag == 0)//默认正数
                flag = 1;
            num = num*10 + (*str - '0')*flag;
            str++;
        }
        else if(*str == ' ' && flag == 0)//数字前的空格的去除
            str++;
        else if(*str == '-' && flag == 0)//负数
        {
            flag = -1;
            str++;
            if(*str >= '0' && *str <= '9')
                num = -(*str-'0');
            else
                break;
            str++;
        }
        else if(*str == '+' && flag == 0)//正数
        {
            flag = 1;
            str++;
        }
        else//异常字符
            break;
    }

    return num;
}