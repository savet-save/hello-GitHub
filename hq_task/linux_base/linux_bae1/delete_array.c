#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//求数组个数
#define ARR_NUM(arr) sizeof((arr))/sizeof((arr[0]))
//删除int型的数组成员
int delete_int_array_number(int *arr, int arr_num, int del_num);

int main(int argc, char const *argv[])
{
    srand((unsigned)time(NULL));
    int arr[10] = {0};
    int del_num = -1;
    int i;
    printf("当前数组为的值为：");
    for ( i = 0; i < ARR_NUM(arr); i++)
    {
        arr[i] = rand()% 101;
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("请输入要删除的下标 : ");
    scanf("%d", &del_num);
    getchar();//去除\n

    if(delete_int_array_number(arr, ARR_NUM(arr), del_num) == 0)//判断是否删除成功
    {
        printf("删除成功,当前数组的值为(-1表示已被删除,不使用):\n");
        for ( i = 0; i < ARR_NUM(arr); i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    else
    {
        printf("删除失败\n");
    }
     
    return 0;
}

int delete_int_array_number(int *arr, int arr_num, int del_num)
{
    int i;
    if(del_num < 0 ||del_num > arr_num)
    {
        printf("error parameter\n");
        return -1;
    }
    for (i = del_num; i < arr_num; i++)
    {
        if(i < arr_num -1)
        {
            *(arr + i) = *(arr + i + 1);
        }
        else
        {
            *(arr + i) = -1;
        }
    }
    return 0;
}