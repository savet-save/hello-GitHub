#include <stdio.h>
#include <stdlib.h>

//使arr数组中的元素循环右移move_m个元素,成功返回0,失败返回-1,并打印错误
int array_rotate_right(int *arr , int move_n, int move_m);

int main(int argc, char const *argv[])
{
    int n = 0, m = 0, i;
    int *arr;

    printf("请输入数组长度n和右移个数m : ");
    scanf("%d%*c%d%*c", &n, &m);//获取长度n和移动数m
    arr = (int *)malloc(n * sizeof(int));
    printf("右移%d个元素前数组的值为 : ", m);
    for(i = 0; i < n; i++)//初始化数组中的值
    {
        *(arr + i) = i + 1;//值为1-n
        printf("%d ", *(arr + i));
    }
    printf("\n");
    
    if(array_rotate_right(arr, n, m) >= 0)//成功打印出
    {
        printf("右移%d个元素后数组的值为 : ", m);
        for(i = 0; i < n; i++)//打印右移后数组的值
        {
            printf("%d ", *(arr + i));
        }
        printf("\n");
    }
    else
    {
        printf("移动失败!\n");
    }

    free(arr);
    return 0;
}

int array_rotate_right(int *arr , int move_n, int move_m)
{
    int move_x;//用于保存n-m的值
    int *temp;//暂存移动的值
    int i;

    if(arr == NULL)//错误处理
    {
        fprintf(stderr, "parameter error : NULL pointer\n");
        return -1;
    }
    if(move_m > move_n)
    {
        fprintf(stderr, "error value : n need more than the m\n");
        return -1;
    }
    
    move_x = move_n - move_m;//获取n-m的位置,保证是最后m个
    temp = (int *)malloc(move_m * sizeof(move_m));//存放右移出来的数
    
    for(i = 0; i < move_m; i++)
    {
        *(temp + i) = *(arr + move_x + i);//暂存最后m个数
    }
    
    int *tail = arr + move_n - 1;//指向数组最后一个元素
    for(i = 0; i < move_x; i++)//要移动的元素的次数
    {
        *(tail - i) = *(tail - i - move_m);
    }
    for(i = 0; i < move_m; i++)
    {
        *(arr + i) = *(temp + i);//返回暂存的数
    }
    
    free(temp);
    return 0;
}