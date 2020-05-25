#include <stdio.h>
#include <stdlib.h>

//查找第一次在dst中出现src的位置，并返回，没有找到就返回NULL
char *my_strstr(char *dst, const char *src);

int main(int argc, char const *argv[])
{
    char *dst = "abcasda";//保存需要被查找的字符串
    char *src = "ca";//保存用于查找的字符串

    printf("需要被查找的字符串是 : %s 用于查找的字符串是 : %s\n", dst, src);
    printf("被查找的字符串的起始地址是 : %p\n", dst);
    //打印查找结果
    printf("查找的结果是 : %p\n", my_strstr(dst, src));
    return 0;
}

/*因为不希望在主函数中调用,就声明在这里*/
//比较前n个字符是否相等，相等返回0
int my_strncmp(const char *dst, int num, const char *src);
//返回字符串有效字符的长度
int my_strlen(const char *str);

char *my_strstr(char *dst, const char *src)
{
    int src_len = my_strlen(src);//保存要查找的字符串的长度

    if(dst == NULL || src == NULL)//错误处理
    {
        fprintf(stderr, "error in my_strstr : NULL pointer");
        return NULL;
    }

    while(*dst != '\0')//结束判断
    {
        if(my_strncmp(dst, src_len, src) == 0)//找到了就返回，找到的位置
        {
            return dst;
        }
        dst++;//没有找到就使指针向后偏移1个字节
    }

    return NULL;
}

int my_strncmp(const char *dst, int num, const char *src)
{
    int i;
    if(dst == NULL || src == NULL)//错误处理
    {
        fprintf(stderr, "error in my_strncmp : NULL pointer");
        return -1;
    }

    for(i = 0; i < num; i++)//比较两个字符串的前num个字符
    {
        if(*dst != *src)
        {
            return (*dst - *src);
        }
        dst++;
        src++;
    }

    return 0;
}

int my_strlen(const char *str)
{
    const char *str_head = str;//保存头部地址
    if(str == NULL)//错误处理
    {
        fprintf(stderr, "error in my_strlen : NULL pointer");
        return -1;
    }
    while(*str != '\0')//指向'\0'
    {
        str++;
    }
    //其差值为长度
    return str - str_head;
}
