#include <stdio.h>

int nine_nine_Mul_Tab(int num1);//num1为开始数字,到九结束

int main(int argc, char const *argv[])
{
    nine_nine_Mul_Tab(1);//打印九九乘法表
    return 0;
}

int nine_nine_Mul_Tab(int num1)
{
    int num2 = num1;
    if(num1 > 9)//结束的判断
    {
       return 0;//退出递归
    }
    else
    {
        nine_nine_Mul_Tab(num2+1);//递归调用
    }
    while (num1)
    {
        printf("%d * %d = %d   ", num1, num2, num1*num2);
        num1--;
    }

    printf("\n");

    return 0;//正常退出
}