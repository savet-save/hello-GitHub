#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//字符串中的'\t'替换为指定4个空格
int char_table_convert_space(char *str);

int main(int argc, char const *argv[])
{
    char *str = (char *)malloc(300);
    strcpy(str, "testa\t123\tbc");

    char_table_convert_four_space(str);
    printf("%s\n", str);
    free(str);
    return 0;
}

////把字符串str右移move_n个字符，空出的位置不改变其值
int str_right_move(char *str, int move_n);

int char_table_convert_space(char *str)
{
    int space_num = 4;//保存要替换空格的个数
    if(str == NULL)
    {
        return -1;
    }
    while(*str != '\0')
    {
        if(*str == '\t')
        {
            str_right_move(str, space_num - 1);//空出替换个数-1个位置(因为'\t'也要被替换)
            while(space_num--)*str++ = ' ';//替换为空格
            space_num = 4;
        }
        else
        {
            str++;
        }
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