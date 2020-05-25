#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int licensing();
int twenty_one_clock();

int G_end = 0;//用于判断双方都不要牌的情况

int twenty_one_clock_star()
{
    char next = 'y';

    printf("******************\n");
    printf("欢迎来参加21点游戏\n");
    printf("******************\n");
    while(next == 'y' || next == 'Y')
    {
        G_end = 0;
        twenty_one_clock();
        printf("输入'y'重新开始21点,其它退出 : ");
        next = getchar();
        if(next == '\n')//不用按2次回车就能退出
        {
            break;
        }
        while (getchar() != '\n');
    }
    printf("***********************\n");
    return 0;
}

int twenty_one_clock()
{
    srand((unsigned)time(NULL));
    int player1 = 0 ;
    int player2 = 0 ;
    while (player1 < 21 && player2 < 21)
    {
        if(G_end >= 2)//表示双方都放弃要牌
        {
            break;
        }

        printf("玩家 1(点数:%d)\n你是否要牌(输入'y'表示要) : ", player1);
        player1 += licensing();

        printf("玩家 2(点数:%d)\n你是否要牌(输入'y'表示要) : ", player2);
        player2 += licensing();
        
    }
    if(player1 > player2 && player1 <= 21)
    {
        printf("玩家1的点数:%d, 玩家2的点数:%d\n玩家 1 胜利!\n", player1, player2);
    }
    else if(player2 > player1 && player2 <= 21)
    {
        printf("玩家1的点数:%d, 玩家2的点数:%d\n玩家 2 胜利!\n", player1, player2);
    }
    else
    {
        if(player1 > 21 && player2 < 21)
        {
            printf("玩家1的点数:%d, 玩家2的点数:%d\n玩家 2 胜利!\n", player1, player2);
        }
        else if(player1 < 21 && player2 > 21)
        {
            printf("玩家1的点数:%d, 玩家2的点数:%d\n玩家 1 胜利!\n", player1, player2);
        }
        else
        {
            printf("玩家1的点数:%d, 玩家2的点数:%d\n平局!\n", player1, player2);
        }
    }

    return 0;
}

int licensing()
{
    char flag ;
    int rand_ponit = rand() % 9 + 1;//1-9点
    if((flag = getchar()) == '\n')
    {
        G_end += 1;
        return 0;
    }
    if(flag == 'y' || flag == 'Y' )
    {
        while(getchar() != '\n');
        G_end = 0;
        printf("你抽到点数是 : %d \n", rand_ponit);
        return rand_ponit;
    }
    else
    {
        while(getchar() != '\n');
        G_end += 1;
        return 0;
    }
    
    return  -1;
}