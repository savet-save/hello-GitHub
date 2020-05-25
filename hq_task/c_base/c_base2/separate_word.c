#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxWord 1024

int separate_word(char* const words,char *lower, char *capital);

int main(int argc, char const *argv[])
{
    char *words = (void *)malloc(MaxWord);
    printf("请输入要分割的单词(忽略所有非字母) : ");
    fgets(words, MaxWord/2, stdin);//前一半存小写，后一半存大写，防止超过
    char *lower = words;//小写
    char *capital = words + MaxWord/2;//大写
    separate_word(words, lower, capital);
    printf("小写字母 : %s\n大写字母 : %s\n", lower, capital);
    free(words);
    return 0;
}

int separate_word(char* const words,char *lower, char *capital)
{
    int offset = 0;//偏移量
    while(*(words + offset)!='\0')
    {
        if(*(words + offset) >= 'a' && *(words + offset) <= 'z')
        {
            *lower = *(words + offset);
            lower++;
        }
        else if (*(words + offset) >= 'A' && *(words + offset) <= 'Z')
        {
            *capital = *(words + offset);
            capital++;
        }
        offset++;
    }
    *lower = '\0';
    *capital = '\0';
    return 0;
}
