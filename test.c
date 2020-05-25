#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{

    long long unsigned t1 = 0x123456789;
    long unsigned int t2 = 0x12345678;
    unsigned long  t3 = 0x12345678; 
    unsigned int t4 = 0x12345678;
    printf("%Iu %Iu %Iu %Iu\n", sizeof(t1), sizeof(t2), sizeof(t3), sizeof(t4));
    printf("%I64x %lx %lx %x", t1, t2, t3, t4);
    
    return 0;
}