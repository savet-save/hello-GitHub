#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MSIZE 10 //定义了用栈区创建的杨辉三角的大小

int stack_area_print_YHT(const int *parr, unsigned int m_size);//栈区创建杨辉三角并打印, 参数同下
int dump_area_print_YHT(unsigned int m_size);//堆区创建杨辉三角并打印,m_size表示杨辉三角的大小
int print_arr(const int *parr, unsigned int colunm);//debug用，打印二维数组的所有值

int main(int argc, char const *argv[])
{
#if 0
    //存放在栈区的方式，方法使用了节约时间的一种算法，用了MSIZE * MSIZE个空间 + 1个指针大小, 指针运算少
    int arr[MSIZE][MSIZE] = {{1 , 0, 0}};//相当于{1,0,0,0....};
    stack_area_print_YHT((int *)arr, MSIZE);
#endif

#if 1
    //存放在堆区的方式,方法使用了节约空间的一种算法，用了m_size + 2个指针大小, 指针运算更多
    int m_size = 0;
    printf("请输入杨辉三角大小 : ");
    scanf("%d", &m_size);
    if(m_size <= 0)
    {
        fprintf(stderr, "error input : invalid value input!\n");
        return -1;
    }
    getchar();
    dump_area_print_YHT(m_size);
#endif
    return 0;
}

int stack_area_print_YHT(const int *parr, unsigned int m_size)//使用栈区创建杨辉三角并打印
{
    int (*arr)[m_size] = (int (*)[])parr;//c99版本下可能不能通过编译,可以选择堆区方式
    int i, j;
    /*if(print_arr((int *)arr, m_size) == -1)//尝试打印初始值
    {
        fprintf(stderr, "printf_arr function fail\n");//失败
        return -1;
    }*/

    printf("1\n");
    for(i = 1; i < m_size; i++)
    {
        for (j = 0; j < m_size; j++)
        {
            if(j == 0)
            {
                arr[i][j] = 1;
            }
            else
            {
                arr[i][j] = arr[i-1][j] + arr[i-1][j-1];
            }

            if(arr[i][j])
                printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}

int dump_area_print_YHT(unsigned int m_size)//使用堆区创建杨辉三角并打印
{  
    int i, j, k;
    int *parr = (int *)malloc(m_size * sizeof(int));
    if(parr == NULL)//申请失败
    {
        perror("malloc fail : ");
        return -1;
    }
    memset((void *)parr, 0, m_size  * sizeof(int));//初始化0
    /*for ( i = 0; i < m_size; i++)//用于查看是否初始化成功
    {
        printf("%d ",*(parr+i));
    }
    printf("\n");*/

    int* const YHT = parr;//固定存放首地址
    //开始打印杨辉三角
    for(i = 0; i < m_size; i++)
    {
        parr = YHT + i;//指向行尾
        for (j = 0; j <= i; j++)//从行尾进行修改,若从前面开始会取不到之前的值
        {
            if(j == i || j == 0)//一行的开头和最后为1就行
            {
                *parr  = 1;
            }
            else
            {
                *parr = *parr + *(parr - 1);//第i行的j个数可表示为C(i-1，j-1);
            }
            parr--;
        }
        for (k = 0; k <= i; k++)//打印该行的数据
        {
            printf("%d ",*(YHT + k));
        }
        printf("\n");
    }
    parr = NULL;
    free(YHT);
    return 0;
}

int print_arr(const int *parr, unsigned int colunm)//打印一个二维数组
{
    int i, j;
    if(parr == NULL)
    {
        fprintf(stderr,"NULL Array!\n");
        return -1;
    }
    for(i = 0; i < colunm; i++)
    {
        for (j = 0; j < colunm; j++)
        {
            printf("%d ", *(parr + i*colunm + j));
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}