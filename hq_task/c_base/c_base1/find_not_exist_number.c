#include <stdio.h>

//获得数组元素个数
#define ARR_NUM(arr) sizeof((arr))/sizeof((arr[0]))
//查找不再其自增数组中的值
int find_not_exist_number(int *arr, int arr_num);

int main(int argc, char const *argv[])
{
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 16};
    int i;
    printf("当前数组的值 : ");
    for(i = 0; i < ARR_NUM(arr); i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    printf("不在其数组中的数字是 : %d\n", find_not_exist_number(arr, ARR_NUM(arr)));
    return 0;
}

int find_not_exist_number(int *arr, int arr_num)
{
    int i;
    int max_times = arr_num;//二分法最大运行次数
    if(arr == NULL)//错误的参数
    {
        fprintf(stderr, "error in find_not_exist_number : NULL pointer");
        return -1;
    }
    if(*arr >= 1)//保证第一个是0
    {
        return 0;
    }

    //普通方法
    //逻辑简单,但效率比较低
    //for(i = 0; i == *(arr + i); i++);

    /*二分法*/
    //逻辑更为复杂,但效率高(数据量很大的情况),且对格式要求严格(要求是一个递增排序数组)
    if(*(arr + arr_num - 1) != arr_num)//防止最后一个元素不正确
    {
        return -1;
    }
    i = arr_num / 2;
    int right_two_divide = arr_num / 2;//保存增加的二分值
    while(max_times--)
    {
        
        if(i >= arr_num)//防止访问超过数组大小
        {
            return -1;
        }

        if(i == *(arr + i))//在右边
        {
            right_two_divide = right_two_divide / 2;
            if(right_two_divide == 0) right_two_divide = 1;//保证至少增量为1
            i = i + right_two_divide;
        }
        else
        {
            i = i / 2;
        }

        if(*(arr + i) - *(arr + i - 1) == 2)//和前一个数的差为2就是其值
        {
            return i;
        }

        if(*(arr + i + 1) - *(arr + i) == 2)//后一个数的和其的差为2就是其值
        {
            return i + 1;
        }

    }
    
    //普通方法的返回
    /*if(i < arr_num)//在数组内，正常返回
    {
        return i;
    }
    else//错误的情况
    {
        return -1;
    }*/

    //二分法的错误返回(超时的情况)
    return -1;
}
