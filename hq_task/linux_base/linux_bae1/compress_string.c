/*
已知bug：当字符串同样连续的字符大于2位数上时，会出现问题
修改方法：可以用递归的方式，取出(number%10)个位,然后除10(number/10)，一种到除到商为0(number/10==0);
*/
#include <stdio.h>
#include <stdlib.h>


int compress_string(char *dst, char const *src);

int main(int argc, char const *argv[])
{
    char src[] = "aaaabbbbeeeee";
    char *dst = (char *)malloc(2 * sizeof(src));
    if(dst == NULL)
    {
        perror("malloc fail :");
        return -1;
    }
    printf("%p\n",dst);
    compress_string(dst,src);
    printf("待压缩字符串为 : %s\n", src);
    printf("压缩完成后的字符串为 : %s\n", dst);
    free(dst);
    return 0;
}

int compress_string(char *dst, char const *src)
{
    int number = 1;
    if(*src == '\0' || src == NULL || dst == NULL)//字符串不是有效的情况
    {
        fprintf(stderr, "parameter error : NULL pointer\n");
        return -1;
    }

    while(*src != '\0')
    {
        if(*src == *(src + 1) && number > 0)
        {
            src++;
            number++;
        }
        else
        {
            *dst++ = *src;
            *dst++ = number + '0';
            src++;
            number = 1;
        }
    }
    *dst = '\0';
    return 0;
}
