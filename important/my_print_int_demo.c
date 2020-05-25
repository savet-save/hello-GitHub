#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

int __cdecl my_print_int(const char *str, ...);

int main(int argc, char const *argv[])
{
    my_print_int("my_print_int : $d,$d $$", 123, 435);
    return 0;
}

//int转为字符串
int int_to_string(char *dst, int src);

int my_print_int(const char *str, ...)
{
    va_list list;
    va_start(list, str);
    char *temp = (char *)malloc(64);//保证转换后的数字存放的下
    char* const temp_head = temp;//保存申请的堆区的首地址，主要用于释放
    int i;
    while (*str != '\0')
    {
        if(*str != '$')//判断关键字符
        {
            putchar(*str);
        }
        else
        {
            str++;//判断$的下一个字符
            if(*str == '\0')
                return -1;
            else
            {
                if(*str == 'd')
                {
                    i = va_arg(list, int);
                    temp = temp_head;
                    int_to_string(temp, i);
                    while (*temp != '\0')
                    {
                        putchar(*temp);
                        temp++;
                    }
                    
                }
                else
                {
                    putchar(*str);
                }
            }
        }
        str++;
    }
    va_end(list);//清空栈区
    free(temp_head);//清空堆区

    return 0;
}

/*因为不希望在其它函数中调用，就声明在这里*/
//倒叙字符串
int reverse_order_str(char *str);
//int转换为倒叙对应的字符串(因为使用的递归方式)
int int_to_string_reverse_order(char *dst, int src);

int int_to_string(char *dst, int src)
{
    if(src < 0)//如果是负数
    {
        *dst++ = '-';//添加-号
        src = ~src + 1;//转换为正数
    }
    int_to_string_reverse_order(dst, src);
    return reverse_order_str(dst);
}

int int_to_string_reverse_order(char *dst, int src)
{
    if(dst == NULL)
    {
        fprintf(stderr, "error parameter pointer :int to str fail %p", dst);
        return -1;
    }
    do
    {
        *dst = src %10 + '0';
        src = src / 10;
        dst++;
    }while(src);

    *dst = '\0';//添加结尾标准符
    
    return 0;
}

int reverse_order_str(char *str)
{
    int len = 0;//用于表示字符串长度
    int i;
    char ch_temp = '\0';
    if(str == NULL)
    {
        fprintf(stderr, "parameter error : NULL pointer\n");
        return -1;
    }
    while(*(str+len) != '\0')
    {
        len++;
    }
    if(len <= 1)//不用交换
    {
        return 0;
    }
    len = len - 1;//表示到字符串行尾的的偏移
    for (i = 0; i < len; i++, len--)
    {
        ch_temp = *(str + len);
        *(str + len) = *(str+ i);
        *(str+ i) = ch_temp;
    }

    return 0;
}