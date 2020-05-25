#include <stdio.h>

int max_number(int num1, int num2);

int main(int argc, char const *argv[])
{
    int num1 = 0, num2 = 0;
    printf("请输入要判断的两个数 : ");
    scanf("%d%*c%d%*c", &num1, &num2);
    printf("最大的数为 : %d\n", max_number(num1, num2));
    return 0;
}

int max_number(int num1, int num2)
{
    //i如果大于j,j的结果就>0,其符号位为0,i如果小于j,符号位位
    num2 = num1 - num2;
    //通过符号位判断,如果为0,就不用改变i(-= 0)的值,如果为1,就加上它们之间的差(-= num2(一个负数))
    num1 -= num2 & (num2 >> (sizeof(num2) * 8 - 1));
    return num1;
}
