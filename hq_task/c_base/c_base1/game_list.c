#include <stdio.h>
#include "game.h"

int game_list();//游戏列表

int main(int argc, char const *argv[])
{
    char next = 'y';//第一次不提醒

    printf("**********************\n");
    printf("* 欢迎使用本游戏系统 *\n");
    printf("**********************\n");
    while(next == 'y' || next == 'Y')
    {
        game_list();
        printf("输入'y'重新选择游戏,其它退出 : ");
        next = getchar();
        if(next == '\n')//不用按2次回车就能退出
        {
            break;
        }
        while (getchar() != '\n');
    }
    printf("******本游戏系统结束运行*******\n");
    return 0;
}

int game_list()
{
    printf("*****************************\n");
    printf("1.猜拳游戏  2.猜数字  3.21点\n");
    printf("请选择你要游玩的游戏 : ");
    switch (getchar())
    {
    case '1':
        while (getchar() != '\n');//处理垃圾字符
        mora_star();
        break;
    case '2':
        while (getchar() != '\n');//处理垃圾字符
        guess_number_star();
        break;
    case '3':
        while (getchar() != '\n');//处理垃圾字符
        twenty_one_clock_star();
        break;
    default:
        printf("error input\n");
        break;
    }

    return 0;
}