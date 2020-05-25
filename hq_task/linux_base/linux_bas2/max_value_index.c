#include <stdio.h>

int max_value_index(int *arr, int arr_number, int *ret_max, int *ret_index);

int main(int argc, char const *argv[])
{
    int a[10] = {1, 23, 412, 23, 11 ,0 ,-4};
    int max;
    int index;
    max_value_index(a, 10, &max, &index);
    printf("max:%d index:%d", max, index);
    return 0;
}

int max_value_index(int *arr, int arr_number, int *ret_max, int *ret_index)
{
    int i;
    int max;//存放最大值
    int indax = 0;//存放最大值索引
    if(arr == NULL || ret_max == NULL || ret_index == NULL)//错误处理
    {
        return -1;
    }
    max = *arr;
    for(i = 1; i < arr_number; i++)//寻找最大值
    {
        if(max < *(arr + i))
        {
            max = *(arr + i);
            indax = i;
        }
    }
    //成功返回
    *ret_max = max;
    *ret_index = indax;
    return 0;
}
