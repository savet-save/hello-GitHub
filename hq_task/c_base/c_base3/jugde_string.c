#include <stdio.h>

//0是相等，非零是不相等
int cmp_str_distinguish(const char *dst, const char *src);
int cmp_str_not_dis(const char *dst, const char *src);

int main(int argc, char const *argv[])
{
    char *dst = "this is a string!";
    char *src = "this is a String!";
    printf("区分大小写的判断 被判断字符串: %s  匹配字符串 : %s\n", dst ,src);
    if(cmp_str_distinguish(dst, src) != 0)
    {
        printf("结果 : 不相等!\n");
    }
    else
    {
        printf("结果 : 相等!\n");
    }
    printf("不区分大小写的判断 被判断字符串: %s  匹配字符串 : %s\n", dst ,src);
    if(cmp_str_not_dis(dst, src) != 0)
    {
        printf("结果 : 不相等!\n");
    }
    else
    {
        printf("结果 : 相等!\n");
    }
    return 0;
}

int cmp_str_distinguish(const char *dst, const char *src)
{
    while(*dst == *src)
    {
        if(*dst <= '\0'|| *src <= '\0')// <= '\0'的判断是为了防止出现EOF的问题
        {
            return (*dst - *src);
        }
        dst++;
        src++;
    }
    return (*dst - *src);
}

int cmp_str_not_dis(const char *dst, const char *src)
{
    //异或0x20会把大写转换为小写，小写转换为大写
    while(*dst == *src || *dst == (*src^0x20) || (*dst^0x20) == *src)
    {
        if(*dst != *src)//防止是非字母的情况
        {
            if((*dst < 'a' || *dst > 'z') && (*dst < 'A' || *dst > 'Z'))
                return (*dst - *src);
            if((*src < 'a' || *src > 'z') && (*src < 'A' || *src > 'Z'))
                return (*dst - *src);
        }
        if(*dst <= '\0'|| *src <= '\0')//<= '\0'防止出现EOF的问题
        {
            return (*dst - *src);
        }
        dst++;
        src++;
    }
    return (*dst - *src);
}