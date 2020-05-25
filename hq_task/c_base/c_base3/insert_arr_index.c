#include <stdio.h>


int insert_arr_index(int *arr, int number, int index, int inset_value);

int main(int argc, char const *argv[])
{
    int a[10]={12, 23, 34, 45, 56, 67, 78, 89, 11};
    for (size_t i = 0; i < 10; i++)
    {
       printf("%d ", a[i]);
    }
    printf("\n");
    insert_arr_index(a, 10, 5, 44);
    for (size_t i = 0; i < 10; i++)
    {
       printf("%d ", a[i]);
    }
    return 0;
}

int insert_arr_index(int *arr, int number, int index, int inset_value)
{
    int i;
    if(arr == NULL)//错误处理
    {
        return -1;
    }
    arr = arr + number - 1;//指向最后一个元素
    for(i = index; i< number - 1; i++)//空出要插入的位置
    {
        *arr = *(arr - 1);
        arr--;
    }
    *(arr + index) = inset_value;//插入值

    return 0;
}