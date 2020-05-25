#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//二维数组的行数
#define ROW 3
//二维数组的列数
#define COLUMN 4
//用于接收二维数组的坐标
typedef struct _My_Position
{
    int x;//横值坐标
    int y;//竖值坐标
}MyPosition;

//返回一个二维数组的最大值坐标(0为起点),返回一个位置(MyPosition)
MyPosition censor_two_dimensional_array_max_index(int row,int column, int (*arr)[]);
//打印出一个二维每一行的累加值
int sum_two_dimensional_arr_row_print(int row,int column, int (*arr)[]);

int main(int argc, char const *argv[])
{
    int num[ROW][COLUMN] = {{0}};
    int i , j;
    srand((unsigned)time(NULL));
    printf("当前二维数组的值为 : \n");
    for (i = 0; i < ROW; i++)//用于二维数组的初始化
    {
        for (j = 0; j < COLUMN; j++)
        {
            num[i][j] = rand()%101;//0-100的随机数
            printf("%d ", num[i][j]);
        }
        printf("\n");
    }
    MyPosition position;
    position = censor_two_dimensional_array_max_index(ROW, COLUMN, num);
    //打印一个二维数组的最大值和其坐标（0为起点）
    printf("最大值为: %d  坐标为:%d,%d\n", num[position.x][position.y], position.x, position.y);
    //打印出一个二维每一行的累加值
    sum_two_dimensional_arr_row_print(ROW, COLUMN, num);

    return 0;
}

MyPosition censor_two_dimensional_array_max_index(int row,int column, int (*arr)[])
{
    int (*this_arr)[column] = (int (*)[column])arr;
    int max = (*this_arr)[0];
    MyPosition positon = {0, 0};//存放用于返回的坐标
    int px, py = 0;
    for (px = 0; px < row; px++)
    {
        for (py = 0; py < column ; py++)
        {
            if (max < *(*(this_arr + px) + py))
            {
                max = *(*(this_arr + px) + py);
                positon.x = px;
                positon.y = py;
            }
        }
    }

    return positon;
}   

int sum_two_dimensional_arr_row_print(int row,int column, int (*arr)[])
{
    int (*this_arr)[column] = (int (*)[column])arr;
    int sum = 0;
    int i, j = 0;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column ; j++)
        {
            sum += *(*(this_arr + i) + j);
        }
        printf("第%d行的和为: %d\n", i, sum);
        sum = 0;
    }

    return 0;
}