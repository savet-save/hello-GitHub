/*
bug汇报：如果数字是超过2位数的，将会出现问题(修复将会增加复杂度，暂不修复)
现在只能根据1位的数字(0-9)解压开对应的前面的那个字符
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_STR 1024

//根据字符前的一个数字解码(解压)
char * decode_string(const char *str);

int main(int argc, char const *argv[])
{
    char *str = "a4b4e5";//带解码的字符串
    char *decode_str = NULL;//用于指向解码后的字符串
    decode_str = decode_string(str);
    if(decode_str == NULL)//解码失败的情况
    {
        printf("解码失败!\n");
        return -1;
    }
    printf("解压前的字符串为 : %s\n", str);
    //成功后输出解码后的字符串
    printf("解压后的字符串为 : %s\n", decode_str);
    free(decode_str);
    return 0;
}

char * decode_string(const char *str)
{
    int len = 0;//存放str的长度
    int offet = 1 , decode_offet = 0;//偏移
    int i;
    char* const decode_str = (char *)malloc(MAX_STR);
    if(str == NULL || decode_str == NULL)//防止指向为空
    {
        fprintf(stderr, "error decode_string() : parameter str is NULL or malloc fail\n");
        return NULL;
    }
    if(*str >= '0' && *str <= '9')//数字出现在开头的情况
    {
        fprintf(stderr, "wrong format : Numbers cannot be at the beginning\n");
        return NULL;
    }
    while(*(str+len) != '\0')//获取长度
    {
        len++;
    }
    if(len == 0)//如果str的长度为0，则这个字符串是个空字符串
    {
        fprintf(stderr, "error parameter : in decode_string function : value is NULL\n");
        return NULL;
    }
    //偏移如果等于长度，会指向str的'\0'
    while(offet < len)
    {
        if((*(str + offet) >= '0') && (*(str + offet) <= '9'))//如果为数字的情况
        {
            for ( i = 0; i < (*(str + offet) - '0'); i++)
            {
                *(decode_str + decode_offet) = *(str + offet - 1);
                decode_offet++;
                if(decode_offet >= MAX_STR)//超过申请的空间
                {
                    fprintf(stderr, " wring : in decode_string function : overtake MAX_STR");
                    *(decode_str + decode_offet) = '\0';
                    return decode_str;
                }
            }
        }
        offet++;
    }
    //字符串结尾添加'\0'
    *(decode_str + decode_offet) = '\0';
    return decode_str;
}