#include <stdio.h>
#include <string.h>
#include <pthread.h>

#define uchar unsigned char 

int main(void)
{
    int ret, a = 1, b = 2;
    ret = a+++b;
    printf("ret : %d, a : %d, b : %d", ret, a, b);
    return 0;
}