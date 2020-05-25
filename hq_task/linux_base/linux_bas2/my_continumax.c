#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//功能：在字符串中找出连续最长的数字串，并把这个串的长度返回，并把这个最长数字串付给其中一个函数参数outputstr所指内存。
int my_continumax(char *outputstr,const char *intputstr);

int main(int argc, char const *argv[])
{
    char *str_input = (char *)malloc(200);
    strcpy(str_input, "test123abr12413we12345689");
    char *output_str = (char *)malloc(200);
    int ret_len = my_continumax(output_str, str_input);

    printf("max len : %d str:%s", ret_len, output_str);

    free(str_input);
    free(output_str);
    return 0;
}

int my_continumax(char *outputstr,const char *intputstr)
{
    
    int input_len = strlen(intputstr);//保存保存输入的字符串的长度
    char *str_input = (char *)malloc(input_len + 1);//用于保存输入的字符串，防止更改其值
    char * const str_input_head = str_input;//主要用于释放内存
    int temp_len = 0;//暂存字符串的长度

    if(outputstr == NULL || intputstr == NULL)
    {
        return -1;
    }

    strcpy(str_input, intputstr);
    *outputstr = '\0';//保证最开始的outputstr存放的字符串长度为0

    while(*str_input != '\0')
    {
        if(*str_input < '0' || *str_input > '9')//去非数字
        {
            *str_input = '\0';
        }
        str_input++;
    }

    str_input = str_input_head;
    while(input_len > 0)
    {
        if(*str_input != '\0')
        {
            if((temp_len = strlen(str_input)) > strlen(outputstr))//如果更长就改变其输出字符串的值
            {
                strcpy(outputstr, str_input);
            }

            input_len -= temp_len;//长度对应减少
            str_input += temp_len;//偏移到当前子字符串的'\0'
        }
        else
        {
            input_len--;//长度减1
            str_input++;//偏移到下一个字符
        }
    }

    free(str_input_head);
    return strlen(outputstr);
}