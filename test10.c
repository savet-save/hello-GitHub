#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int fun(int , int);

int main(int argc, char const *argv[])
{
    fun(1, 2);
    return 0;
}

int fun(a, b)
int a, b;
{
    printf("%d %d\n", a, b);
    return 0;
}