#include <stdio.h>
#include <stdlib.h>

int jseph_ring_game();

int main(int argc, char const *argv[])
{
    jseph_ring_game();//开始出圈游戏

    return 0;
}


int jseph_ring_game()
{
    unsigned int number = 0;//保存总共人数
    unsigned int have_number;//用于保存现在还有多少人
    int *arr;
    int i;

    printf("请输入开始人数 : ");
    scanf("%u%*c", &number);//获取人数
    arr = (int *)malloc(number * sizeof(number));
    if(arr == NULL)//失败处理
    {
        return -1;
    }
    for(i = 0; i < number; i++)//初始化1-N号
    {
        *(arr + i) = i + 1;
    }
    
    have_number = number;//保存现在还有多少人

    int count = 0; //默认还没开始报数
    while(have_number > 1)
    {
        for(i = 0; i < number; i++)
        {
            if(*(arr + i) != 0)count++;//如果有人就报数,计数值+1
            if(count == 3)
            {
                *(arr + i) = 0;//0表示没有人
                have_number--;//还有的人数-1
                count = 0;//默认还没开始报数
            }
        }
    }
    
    for( i = 0; i < number; i++)
    {
        if(*(arr + i) != 0)//0表示已经退圈，找到没有退圈的人
        {
            printf("最后留下的是原来第 %d 号\n", *(arr+ i));//打印出来
            break;
        }
    }
    free(arr);
    return 0;
}