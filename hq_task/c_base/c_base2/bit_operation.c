#include <stdio.h>

int main(int argc, char const *argv[])
{
    int i = 240;
    //实现对i的第5位清零
    i = i & ~(1<<4);
    printf("i:%d\n", i);

    i = 240;
    //实现对i的第2位置1
    i = i | (1<<1);
    printf("i:%d\n", i);

    i = 240;
    //实现对i的第6、7位清零
    i = i & ~(3<<5);
    printf("i:%d\n", i);
    return 0;
}
