#include <string.h>
#include <stdio.h>
#include <windows.h>

int binary_one(unsigned int arg);

int (*my_fun_ptr)(const char *, ...) = (void *)0x0000000000402AB0;

#include <stdio.h>

int main(void)
{
    int arr[10] = {[2] = 3, [4] = 5};
    printf("%d  %d  %d\n",arr[0], arr[2], arr[4]);
    return 0;
}

int binary_one(unsigned int arg)
{
    int num = 0;
#if 0
    int i;
    for(i = 0; i < 32; i++)
    {
        if((arg & 0x1) != 0)num++;
        arg = arg >> 1;
    }
#else
    while(arg != 0)
    {
        num = num + (arg % 2);
        arg /= 2;
    }
#endif
    return num;
}