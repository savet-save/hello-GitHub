#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Fibonacci_sequence(int n);

int main(int argc, char const *argv[])
{
    printf("%d\n", Fibonacci_sequence(10));
    return 0;
}

int Fibonacci_sequence(int n)
{
    int *num;//用于指向保证其斐波那契数列
    int *head_num;//用于释放
    int ret_num = 0;//保存返回结果
    int i = 0;
    if(n <= 0)//错误参数的处理
    {
        return 0;
    }

    num = (int *)malloc( n * sizeof(int));
    head_num = num;

    *num++ = 1;//前两项为1
    *num++ = 1; 
    for(i = 2; i < n; i++)//进行求斐波那契数
    {
        *num = *(num - 1) + *(num - 2);
        num++;
    }

    ret_num = *(head_num + n -1);//获取要返回的数
    free(head_num);
    return ret_num;
}