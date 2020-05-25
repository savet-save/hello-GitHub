#include <stdio.h>
#include <stdlib.h>

#define maxNumber 256

int receive(char *usersName,char *password);

int main(int argc, char const *argv[])
{
    char *usersName = (void *)malloc(maxNumber);
    char *password = (void *)malloc(maxNumber);
    printf("请输入待处理的字符串,'U'表示用户名，‘#’表示密码 : ");
    receive(usersName, password);
    printf("用户名 : %s\n密码 : %s\n", usersName, password);
    free(usersName);
    free(password);
    return 0;
}

int receive(char *usersName,char *password)
{
    int flag = 0;
    while((*usersName = getchar()) != '#')
    {
        if(*usersName == '\n')//防止没有‘#’的情况
        {
            *usersName = '\0';
            *password = '\0';
            return -1;
        }
        if(flag)
        {
            usersName++;
        }
        if(*usersName =='U')//没有U就不接收
        {
            flag = 1;
        }
    }
    *usersName = '\0';

    while((*password = getchar()) != '\n')
    {
        password++;
    }
    *password = '\0';

    return 0;
}
