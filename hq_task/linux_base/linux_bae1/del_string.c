#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//删除字符串中指定的字符串
int del_string(char *str, const char *del_str);

int main(int argc, char const *argv[])
{
    char *str = (char *)malloc(300);
    
    strcpy(str, "testab123abc");
    del_string(str, "ab");

    printf("%s\n", str);

    free(str);
    return 0;
}

int del_string(char *str, const char *del_str)
{
    char *del_index = NULL;//保存要删除的字符串的位置
    if(str== NULL || del_str == NULL)
    {
        return -1;
    }

    while(( del_index = strstr(str, del_str)) != NULL)
    {
        strcpy(del_index, del_index + strlen(del_str));//删除其子字符串
    }

    return 0;
}
