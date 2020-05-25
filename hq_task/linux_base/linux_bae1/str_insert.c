#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//在dst字符串的指定位置n处插入src字符串
int str_insert(char *dst, int n, const char *src);

int main(int argc, char const *argv[])
{
    char *str = (char *)malloc(300);
    strcpy(str, "test123");
    str_insert(str, 0, " hello ");
    printf("%s", str);
    free(str);
    return 0;
}

//把字符串str右移move_n个字符，空出的位置不改变其值
int str_right_move(char *str, int move_n);

int str_insert(char *dst, int n, const char *src)
{
    if(dst == NULL || src == NULL)
    {
        return -1;
    }
    str_right_move(dst + n, strlen(src));
    while(*src != '\0')
    {
        *(dst + n) = *src;
        dst++;
        src++;
    }

    return 0;
}

int str_right_move(char *str, int move_n)
{
    int len;

    if(str == NULL || move_n < 0)
    {
        return -1;
    }
    len = strlen(str);
    str += len;//指向'\0'
    while(len >= 0)
    {
        *(str + move_n) = *str;
        str--;
        len--;
    }
    return 0;
}