#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int guess_number();

int guess_number_star()
{
    printf("*************************\n");
    printf("欢迎来参加猜数字游戏(0-100)\n");
    printf("*************************\n");
    do
    {
        guess_number();
        printf("输入'y'继续猜数字,其它退出 : ");
    }while(getchar() == 'y');
    printf("***********************\n");
    return 0;
}

int guess_number()
{
    srand((unsigned)time(NULL));
    int computer_number = rand() % 101;
    int receive_number = 0;
    do
    {
        printf("请输入你猜的的数(-1放弃) : ");
        while(!scanf("%d" , &receive_number))
        {
            while (getchar() != '\n');//处理垃圾字符
        }
        while (getchar() != '\n');//处理垃圾字符
        if(receive_number < 0)//退出
        {
            return 0;
        }

        if(receive_number> computer_number)
        {
            printf("大了\n");
        }
        else if(receive_number < computer_number)
        {
            printf("小了\n");
        }
        
        
    }while(computer_number != receive_number);
    printf("恭喜你，猜正确了!\n");
    
    return 0;
}