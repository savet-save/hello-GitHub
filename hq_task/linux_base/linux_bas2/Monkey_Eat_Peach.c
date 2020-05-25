/*
    已知bug:
    1.当输入大于32时,会达到size_t类型的上限
解决办法:
    1.改用字符串类型接收
*/
#include <stdio.h>

//猴子偷桃实现
size_t Monkey_Eat_Peach(int day);

int main(int argc, char const *argv[])
{
    int day;
    printf("请输入天数 : ");
    scanf("%d%*c", &day);
    printf("猴子一共偷了 : %Iu个桃子!\n", Monkey_Eat_Peach(day));
    return 0;
}

//猴子每天吃一半+1个,反过来就是每天多1个再乘2
size_t Monkey_Eat_Peach(int day)
{
    if(day <= 0)
    {
        return 0;
    }
    size_t Peach_number = 1;
    while (day > 1)//从1开始算，没有第0天
    {
        Peach_number = (Peach_number + 1) * 2;
        day--;
    }

    return Peach_number;
}
