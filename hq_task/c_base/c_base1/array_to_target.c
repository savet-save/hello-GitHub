#include <stdio.h>

//函数功能,查找数组中任意两个元素的和等于目标值starget的第一数组元素组下标
//arr是数组,arr_num是数组元素个数,ret_subscript1是接收的第一个下标,ret_subscript1是接收的第二个下标
//成功返回0,并返回下标,失败返回-1，并且不返回下标
int array_to_target(int *arr, int arr_num, int target , int *ret_subscript1, int *ret_subscript2);

int main(int argc, char const *argv[])
{
    int arr[10] = {2, 7, 11, 15, 8, 10 ,20, 11, 50, 78};
    int ret1 = 0, ret2 = 0;
    int target = 0;
    int i;
    printf("当前数组的值为 : ");
    for(i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    printf("请输入要判断目标值 : ");
    scanf("%d%*c", &target);
    if(array_to_target(arr, 10, target, &ret1, &ret2) == 0)//成功
    {
        printf("成功找到了!下标是 : [%d, %d]\n", ret1, ret2);
    }
    else
    {
        printf("没有找到\n");
    }
    return 0;
}

int array_to_target(int *arr, int arr_num, int target , int *ret_subscript1, int *ret_subscript2)
{
    int offset1 = 0, offset2 = 1;//用于指向两个不同的元素
    if(arr == NULL || ret_subscript1 == NULL || ret_subscript2 == NULL)//错误参数处理
    {
        fprintf(stderr, "parameter error : NULL pointer\n");
        return -1;
    }
    while(offset1 < arr_num - 1)//遍历整个数组
    {
        
        if(*(arr + offset1) + *(arr + offset2) == target)//如果找到
        {
            *ret_subscript1 = offset1;
            *ret_subscript2 = offset2;
            return 0;
        }

        offset2++;//偏移2++
        if(offset2 == arr_num)//防止溢出
        {
            offset1++;//偏移1++
            offset2 = offset1 + 1;//防止两个数相等的情况
        }
    }
    //没有找到
    return -1;
}
