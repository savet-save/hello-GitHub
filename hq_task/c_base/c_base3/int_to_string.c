#include <stdio.h>
#include <stdlib.h>

//src数字转换为字符串，存放在dst指向的地址中,失败返回-1,成功返回转换的字符串长度
int int_to_string(char *dst, int src);

int main(int argc, char const *argv[])
{
    char *str = (char *)malloc(100);

    int_to_string(str, 123);
    printf("%s\n", str);
    free(str);
    return 0;
}


/*因为不希望在主函数中调用，就声明在这里*/
//倒叙字符串
int reverse_order_str(char *str);
//int转换为倒叙对应的字符串
int int_to_string_reverse_order(char *dst, int src);
//求出字符串有效字符长度
int my_strlen(const char *str);

int int_to_string(char *dst, int src)
{
    if(dst == NULL)
    {
        return -1;
    }
    if(src < 0)//如果是负数
    {
        *dst++ = '-';//添加-号
        src = ~src + 1;//转换为正数
    }
    if(int_to_string_reverse_order(dst, src)== -1) return -1;
    if(reverse_order_str(dst)== -1 ) return -1;

    return my_strlen(dst);
}

int int_to_string_reverse_order(char *dst, int src)
{
    if(dst == NULL)
    {
        return -1;
    }
    while (src)
    {
        *dst++ = src % 10 + '0';
        src = src / 10;
    }
    *dst = '\0';
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
    len = my_strlen(str);
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

int my_strlen(const char *str)
{
    int len = 0;//保存字符串的长度,从0开始
    if(str == NULL)
    {
        return -1;
    }
    while (*str != '\0')
    {
        len++;
        str++;
    }
    return len;
}