#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum Mora{ scissors = 0, stone, cloth};
int mora_game();
int mora_star()
{
    printf("******************\n");
    printf("欢迎来参加猜拳游戏\n");
    printf("******************\n");
    do
    {
        mora_game();
        printf("输入'y'重新开始猜拳,其它退出 : ");
    }while(getchar() == 'y');
    
    printf("***********************\n");
    return 0;
}

int mora_game()
{
    srand((unsigned)time(NULL));
    enum Mora NPC = rand() % 3;
    enum Mora user_input;
    printf("请输入:剪刀(0),石头(1),布(2)\n");
    scanf("%d", (int *)&user_input);
    while (!getchar());
    switch (user_input)
    {
    case scissors:
        if(NPC == scissors)
            printf("剪刀VS剪刀--平局\n");
        else if(NPC == stone)
            printf("石头VS剪刀--你赢了\n");
        else
            printf("布VS剪刀--你输了\n");
        break;
    case stone:
        if(NPC == scissors)
            printf("剪刀VS石头--你输了\n");
        else if(NPC == stone)
            printf("石头VS石头--平局\n");
        else
            printf("布VS石头--你赢了\n");
        break;
    case cloth:
        if(NPC == scissors)
            printf("剪刀VS布--你赢了\n");
        else if(NPC == stone)
            printf("石头VS布--你输了\n");
        else
            printf("布VS布--平局\n");
        break;
    default:
        printf("error input!\n");
        break;
    }
    return 0;
}