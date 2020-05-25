#include <stdio.h>

//str是用于判断的字符串，ret_number用于接收数字个数,后来两个依次为字母个数和其他字符个数
int count_characters(char const *str, int *ret_number, int *ret_letter, int *ret_other);

int main(int argc, char const *argv[])
{
    char *str = "this a test string! 0101 &*()()W(*U#wAIJpJ2";
    int number = 0, letter = 0, other = 0;
    if(count_characters(str, &number, &letter, &other) == 0)
    {
        printf("当前判断字符串为 : %s\n", str);
        printf("其中数字个数为 : %d  字母个数为 : %d  其他字符个数为 : %d\n", number, letter, other);
    }
    else
    {
        printf("error\n");
    }
    return 0;
}

int count_characters(char const *str, int *ret_number, int *ret_letter, int *ret_other)
{
    int number = 0;//存放数字个数
    int letter = 0;//存放字母个数
    int other = 0;//存放其他字符个数
    if(str==NULL || ret_letter==NULL || ret_number==NULL || ret_other== NULL)
    {
        fprintf(stderr, "parameter error : NULL pointer\n");
        return -1;
    }
    while(*str != '\0')
    {
        if(*str >= '0' && *str <= '9')
        {
            number++;
        }
        else if((*str >= 'a' && *str <= 'z')||(*str >= 'A' && *str <= 'Z'))
        {
            letter++;
        }
        else
        {
            other++;
        }
        str++;
    }
    *ret_number = number;
    *ret_letter = letter;
    *ret_other = other;

    return 0;
}
