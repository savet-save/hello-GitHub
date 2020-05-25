#include <stdio.h>
#include "test5.c"

extern int temp;

int main(int argc, char const *argv[])
{
    temp = 0;
    printf("%d\n", temp);
    return 0;
}
