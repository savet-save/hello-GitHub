#include <stdio.h>

//求n及以下所有的阶乘数和
int factorial_sum(int n);

int main(int argc, char const *argv[])
{
    int input_num = 0;
    int sum_fac = 0;
    printf("请输入需要求阶乘和的数 : ");
    scanf("%d", &input_num);
    getchar();
    sum_fac = factorial_sum(input_num);
    printf("%d及以下所有阶乘数和为 : %d\n", input_num, sum_fac);
    return 0;
}

int factorial_sum(int n)
{
    int i, j;
    int mul = 1, sum = 0; //初始化一定要是这个
    for ( i = n; i > 0; i--)
    {
        for ( j = i; j > 0 ; j--)
        {
            mul *= j;//保存阶乘
        }
        sum += mul;//保存所有阶乘和
        mul = 1;//重新初始化
    }
    
    return sum;
}