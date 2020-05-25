#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//求出数组元素的个数
#define ARR_NUM(arr) sizeof((arr))/sizeof((arr[0]))

//找第二大的数并返回
int serch_second_largest_number(int *arr_p, int arr_num);

int main(int argc, char const *argv[])
{
    int arr[10] = {0};
    srand((unsigned)time(NULL));
    int i;
    int sec_max;
    printf("当前数组的值 : ");
    for (i = 0; i < ARR_NUM(arr); i++)
    {
        arr[i] = rand() % 101;
        printf("%d ",arr[i]);
    }
    printf("\n");
    sec_max = serch_second_largest_number(arr, ARR_NUM(arr));
    printf("第二大的数 : %d\n", sec_max);
    
    return 0;
}

int serch_second_largest_number(int *arr_p, int arr_num)
{
    int max, sec_max;
    int i;
    max = sec_max = *arr_p;
    for ( i = 1; i < arr_num; i++)
    {
        if(max < *(arr_p + i))//获得最大值
        {
            sec_max = max;//防止最后一个数是最大值
            max = *(arr_p + i);
        }
        else if(sec_max < *(arr_p + i) || sec_max >= max)//获得第二大的值
        {
            sec_max = *(arr_p + i);
        }

    }

    
    return sec_max;
}