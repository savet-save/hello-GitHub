#include <stdio.h>
#include <stdlib.h>

#define size_arr(arr_name) sizeof((arr_name))/sizeof((arr_name)[0])
//使数组最大和最小值为0
int bzero_array_highest_and_lowest_number(int *parr, unsigned int array_size);

int main(int argc, char const *argv[])
{
    int scores[10] = {0};
    int i , sum = 0;
    printf("请输入成绩 :\n");
    for ( i = 0; i < size_arr(scores); i++)
    {
        while(!scanf("%d", &scores[i]))
        {
            getchar();
        }
    }

    if(bzero_array_highest_and_lowest_number(scores ,size_arr(scores)) < 0)
    {
        fprintf(stderr, "error: call fuction remove_.._number fail\n");
        return -1;
    }

    for ( i = 0; i < size_arr(scores); i++)
    {
        sum += scores[i];
    }
    sum = sum / (size_arr(scores) - 2);//求平均值

    printf("去掉最高和最低值后的平均值是 : %d\n", sum);
    return 0;
}

int bzero_array_highest_and_lowest_number(int *parr, unsigned int array_size)
{
    int i;
    int *ptemp = parr;
    if(parr == NULL )//空指针的处理
    {
        fprintf(stdin, "error:NULL Pointer\n");
        return -1;
    }

    for ( i = 0; i < array_size; i++)//去掉最小值
    {
        if(*ptemp > *(parr+i))
        {
            ptemp = parr + i;
        }
    }
    *ptemp = 0;

    ptemp = parr;     //去掉最大值
    for (i = 0; i < array_size; i++)
    {
        if(*ptemp < *(parr+i))
        {
            ptemp = parr + i;
        }
    }
    *ptemp = 0;

    return 0;
}
