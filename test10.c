#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int delay_ms(int de_time);

int main(int argc, char const *argv[])
{
    printf("a : %d\n", clock());
    delay_ms(1000);
    printf("b : %d\n", clock());
    delay_ms(1200);
    printf("c : %d\n", clock());
    return 0;
}

int delay_ms(int de_time)
{
    clock_t c_star = clock() * (CLOCKS_PER_SEC / 1000);
    if(de_time <= 0)
    {
        return -1;
    }
    while((abs((clock() - c_star) * (CLOCKS_PER_SEC / 1000))) < de_time);
    return 0;
}