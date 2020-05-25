#include <stdio.h>

int copy_str(char *dst, char const *src);

int main(int argc, char const *argv[])
{
    char dst[20] = "";
    char *src = "this is src!";
    printf("目标字符串 : %s\t 需复制字符串 : %s\n", dst, src);
    copy_str(dst,src);
    printf("目标字符串 : %s\n", dst);
    return 0;
}

int copy_str(char *dst, char const *src)
{
    while((*dst = *src) != '\0')
    {
        dst++;
        src++;
    }
    return 0;
}
