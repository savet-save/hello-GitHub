#include <stdio.h>

//进行正整数的开方运算,并返回其开方后的整数部分
int my_sqrt(int num);

int main(int argc, char const *argv[])
{
    int need_sqrt_num = 0;//保存待开方数
    printf("请输入待开方的正整数 : ");
    scanf("%d%*c", &need_sqrt_num);//接收数据
    //输出结果
    printf("正整数 %d 开方后为 : %d\n", need_sqrt_num, my_sqrt(need_sqrt_num));
    return 0;
}

int my_sqrt(int num)
{
    int ret_sqrt_num;//保存用于返回的开发后的值

    if(num < 1)//<0的虚数不做处理, num >= 1时才做处理
    {
        return 0;
    }
    //最小为1开始
    for ( ret_sqrt_num = 1; ret_sqrt_num * ret_sqrt_num <= num; ret_sqrt_num++);//获取到比开方num大1的值

    //获得正确的开方值
    return (ret_sqrt_num - 1);
}