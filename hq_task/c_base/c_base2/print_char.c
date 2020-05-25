#include <stdio.h>

int print_char(char recive);//recive作为开始字符

int main(int argc, char const *argv[])
{
    char char_recive = 'F';
    print_char(char_recive);
    return 0;
}

int print_char(char recive)
{
    char ch1 = '\0', ch2 = '\0';
    for(ch1 = recive; ch1 >= 'A' && ch1 <= 'Z'; ch1--)// A(65)-Z(90)
    {
        for(ch2 = recive; ch2 > ch1; ch2--)
            printf("_");
        for(ch2 = recive; ch2 >= ch1; ch2--)
            printf("%c", ch2);
        printf("\n");
    }

    for(ch1 = recive; ch1 >= 'a' && ch1 <= 'z'; ch1--)// a(97)-z(122)
    {
        for(ch2 = recive; ch2 > ch1; ch2--)
            printf("_");
        for(ch2 = recive; ch2 >= ch1; ch2--)
            printf("%c", ch2);
        printf("\n");
    }
    
    return 0;
}