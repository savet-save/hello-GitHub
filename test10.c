#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char const *argv[])
{
    FILE *fp = fopen("2.txt", "rb");
    if(fp == NULL)
    {
        perror("error fopen fail");
        return -1;
    }
    int ch;
    while((ch = fgetc(fp)) != EOF)
    {
        putchar(ch);
    }
    fclose(fp);
    return 0;
}
