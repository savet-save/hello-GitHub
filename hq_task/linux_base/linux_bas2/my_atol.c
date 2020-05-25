#include <stdio.h>

long my_atol(const char *str);

int main(int argc, char const *argv[])
{
    long ret = my_atol("123456790");
    printf("%ld", ret);
    return 0;
}

long my_atol(const char *str)
{
    long num = 0;
    if(str == NULL)
    {
        return 0;
    }
    while(*str != '\0')
    {
        if(*str >= '0' && *str <= '9')
        {
            num = num * 10 + (*str - '0'); 
        }
        str++;
    }
    return num;
}
