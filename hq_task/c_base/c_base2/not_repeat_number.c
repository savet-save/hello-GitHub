/*
已知bug:
    1.当输入4个相同的数时,会导致可能不是预期结果
    2.当输入不是个数数时,无法输出要求的三位数
解决办法:
    1.只能要求用户输入正确,如果不正确就不进行组合操作
    2.同上
*/
#include <stdio.h>

//打印出由四个参数组合成不同的实数的个数和其值
int print_not_repeat_number(int n1, int n2, int n3, int n4);

int main(int argc, char const *argv[])
{
    int n1 = 1, n2 = 2, n3 = 3, n4 = 4;
    printf("请输入要组合的4个不相同的数 : ");
    scanf("%d%*c%d%*c%d%*c%d%*c", &n1, &n2, &n3, &n4);
    print_not_repeat_number(n1, n2, n3, n4);

    //一种特殊写法,当数为1、2、3和4时
    /*int i, j, k;
    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
        {
            for(k=0;k<4;k++)
                printf("%d%d%d ", i+1,j+1,k+1);
            printf("\n");
        }
    */
    return 0;
}

//4个数组合成不同的3个位置的数的可能性有 4*4*4 = 64种
/*因为不希望在主函数中调用,就声明在这里*/
//更具i的值选择返回n1-n4其中一个
int select_vaule_return(int i, int n1, int n2, int n3, int n4);
//代表传入数的个数,应该和print_not_repeat_number函数的参数个数保持一致
#define NUM_NUM 4
int print_not_repeat_number(int n1, int n2, int n3, int n4)
{
    int i, j, k;
    int t1, t2, t3;//存放组合后的数三个位置
    printf("实数%d、%d、%d和%d总共能组合成无重复的数有 : %d种\n",
             n1, n2, n3, n4, NUM_NUM * NUM_NUM * NUM_NUM);
    printf("以下为组合成的数 : \n");
    for(i = 0; i < NUM_NUM; i++)//打印多少行
    {
        t1 = select_vaule_return(i, n1, n2, n3, n4);
        for(j = 0; j < NUM_NUM; j++)//打印一行数
        {
            t2 = select_vaule_return(j, n1, n2, n3, n4);
            for(k = 0; k < NUM_NUM; k++)//打印一行的一列
            {
                t3 = select_vaule_return(k, n1, n2, n3, n4);
                printf("%d%d%d ", t1, t2, t3);
            }
            printf("\n");
        }
    }
    return 0;
}


int select_vaule_return(int i, int n1, int n2, int n3, int n4)
{
    if(i % 4 == 0)//设置第一个位置的数
    {
        return n1;
    }
    else if(i % 4 == 1)
    {
        return n2;
    }
    else if(i% 4  == 2)
    {
        return n3;
    }
    else
    {
        return n4;
    }
}
