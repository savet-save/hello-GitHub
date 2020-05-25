#include <stdio.h>
#include <string.h>
#include <stdlib.h>

////把字符串str循环右移move_n个字符，空出的位置不改变其值
int string_rotate_right(char *str, int move_n);

int main(int argc, char const *argv[])
{
    char *str = (char *)malloc(300);
    strcpy(str, "testa123aec");

    string_rotate_right(str, 2);
    printf("%s\n", str);
    free(str);
    return 0;
}



int string_rotate_right(char *str, int move_n)
{
    char *temp_str = (char *)malloc(move_n + 1);
    int len;
    char *temp_head = temp_str;
    int times;
    if(str == NULL || move_n < 0)
    {
        return -1;
    }
    
    len = strlen(str);
    str += len;//指向'\0'
    strncpy(temp_str, str - move_n, move_n + 1);
    str--;//指向'\0'前一个字符
    times = len - move_n;//剩余要移动的字符个数
    while(times > 0)
    {
        *str = *(str - move_n);
        str--;
        times--;
    }

    while(move_n)
    {
        move_n--;//指向'\0'前一个字符
        *str = *(temp_str + move_n);
        str--;
    }

    free(temp_head);
    return 0;
}