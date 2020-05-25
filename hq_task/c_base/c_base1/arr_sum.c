#include <stdio.h>

//求出二维数组的元素个数
#define ARR_NUM(arr) sizeof((arr))/sizeof((arr[0][0]))

//用于保存二维数组的坐标
typedef struct _My_Position
{
    int x;//横值坐标
    int y;//竖值坐标
}MyPosition;

//普通指针方式求二维数组的和,返回0代表成功，返回-1代表失败
int arr_sum(int *arr, int arr_number, int *ret_sum);
//数组指针方式求二维数组的和,返回0代表成功，返回-1代表失败
int arr_pointer_sum(int (*arr_ptr)[], MyPosition pos, int *ret_sum);

int main(int argc, char const *argv[])
{
    int arr[2][3] = {{0}};//申请空间并全部初始化为0
    MyPosition pos = {2 ,3};//初始化和该二维数组的行列值一样就行
    int i;
    int sum = 0;//保存和
    //数据的接收
    printf("请输入数 : ");
    for(i = 0; i < ARR_NUM(arr); i++)
    {
        scanf("%d%*c", &arr[0][i]);
    }
    //数据处理
    //arr_sum((int *)arr, ARR_NUM(arr), &sum);
    arr_pointer_sum(arr, pos, &sum);
    //输出
    printf("该数组元素的和为 : %d\n", sum);
    return 0;
}

int arr_sum(int *arr, int arr_number, int *ret_sum)
{
    int sum = 0;
    int i;
    if(arr == NULL || ret_sum == NULL)//错误的参数处理
    {
        fprintf(stderr, "parameter error : NULL pointer\n");
        return -1;
    }
    for(i = 0; i < arr_number; i++)
    {
        sum += *(arr + i);
    }
    //成功设置和值
    *ret_sum = sum;
    return 0;
}

int arr_pointer_sum(int (*arr_ptr)[], MyPosition pos, int *ret_sum)
{
    int (*arr)[pos.y] = arr_ptr;
    int sum = 0;
    int i, j;
    if(arr == NULL || ret_sum == NULL)//错误的参数处理
    {
        fprintf(stderr, "parameter error : NULL pointer\n");
        return -1;
    }
    for(i = 0; i < pos.x; i++)
    {
        for(j = 0; j<pos.y; j++)
        {
            sum += *(*(arr + i) + j);
        }
    }
    //成功设置和值
    *ret_sum = sum;
    return 0;
}