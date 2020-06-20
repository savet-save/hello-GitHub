#include <stdio.h>

void quickSort(int *p,int len);
int print_arr(int *arr, int len);

int main(int argc, char const *argv[])
{
    int arr[20] = {44, 12, 41, 33, 68, 77, 3, 2, 88, 10};
    quickSort(arr, 10);
    print_arr(arr, 10);
    return 0;
}

//快速排序算法
void quickSort(int *p, int len)
{
	if(p == NULL || len <= 0)
 		return ;
	int i = 0;//i记录第一个元素下标
	int j = len-1;//j记录最后一个元素下标
	int temp = p[0];//记录基准值
    print_arr(p, len);
    printf("\n");
	while(i < j)
    {
        for(; i < j; j--)//循环遍历右边的数据元素
        {
            if(p[j] < temp)//如果小于基准值到左边
            {
                p[i] = p[j];
                break;
            }
        }
        for(; i <j; i++)//循环遍历左边的数据元素
        {
            if(p[i] > temp)//如果大于基准值到右边
            {
                p[j] = p[i];
                break;
            }
        }
    }
	p[i] = temp;//恢复
    print_arr(p, len);
    printf("\n");
	if(i > 1)quickSort(p, i);//左边元素快排
	if(len - i - 1 > 1)quickSort(p + i + 1, len - i - 1);//右边元素快排
    return ;
}

int print_arr(int *arr, int len)
{
    int n = 0;
    while(n < len)
    {
        printf("%d ", arr[n]);
        n++;
    }
    return 0;
}