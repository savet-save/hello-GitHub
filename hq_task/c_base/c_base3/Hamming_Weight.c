#include <stdio.h>

//返回参数对应的汉明重量
int Hamming_Weight(unsigned int num);

int main(int argc, char const *argv[])
{
    int num = 0;//保存待转换的数
    printf("请输入要获取汉明重量的正整数 : ");
    scanf("%d%*c", &num);//接收数据
    if(num < 0)//强制转换为正数
    {
        num = ~num + 1;
    }
    //输出数据
    printf("正整数 %u 的汉明重量为 : %u\n", 
            (unsigned int)num, 
            Hamming_Weight((unsigned int)num));

    return 0;
}

int Hamming_Weight(unsigned int num)
{
    int ret_num = 0;//保存返回的汉明重量
    while(num > 0)//进行判断
    {
        if(num%2 == 1)//最低位为1时数+1
        {
            ret_num++;
        }
        num = num / 2;//整体右移一位
    }
    return ret_num;
}