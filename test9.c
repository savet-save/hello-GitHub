#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a[1] = {1};
    int (*p)[1] = &a;

    return 0;
}
