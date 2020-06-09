#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//函数功能：在以name作为名字的24位BMP图像(star_x, star_y)作为起点，画一个宽width，高height的黑色矩形
//返回值:
//  成功返回0
//  失败返回-1，并在stderr流对应的设备中打印错误原因      
int BMP_24bit_add_mosaic(const char *name, const int star_x, const int star_y, const int width, const int height);

int main(int argc, char const *argv[])
{
    int x = 0, y = 0, w = 0, h = 0;
    if(argc == 6)
    {
        x = atoi(argv[2]);//获取起点的x坐标
        y = atoi(argv[3]);//获取起点的y坐标
        w = atoi(argv[4]);//获取矩形的宽
        h = atoi(argv[5]);//获取矩形的高
        if(BMP_24bit_add_mosaic(argv[1], x, y, w, h) == 0)
        {
            printf("complite\n");
        }
    }
    else
    {
        printf("%s <file_name> <star_x> <star_y> <width> <height>\n", argv[0]);
    }
    
    return 0;
}

//判断指定文件是否是BMP图像且位24bit
//是返回1 不是返回0 错误返回-1
int judge_BMP_24bit(const char *name)
{
    FILE *fp = fopen(name, "rb");
    if(fp == NULL)
    {
        return -1;
    }

    char BM[3] = "";
    fread(BM, 1, 2, fp);//获取文件头
    int IS_BM_HEAD = strncmp("BM", BM, 2) == 0?1:0;
    int BIT = 0;
    fseek(fp, 0x1c, SEEK_SET);//跳转到位深
    fread((void *)&BIT, 1, 2, fp);//获取位深，有2个字节
    fclose(fp);

    return ((BIT == 24 && IS_BM_HEAD) ? 1 : 0);
}

int BMP_24bit_add_mosaic(const char *name, const int star_x, const int star_y, const int width, const int height)
{
    //先判断
    // printf("%d\n", judge_BMP_24bit(name));
    if(judge_BMP_24bit(name) != 1)//判断是否是24位的BMP图像
    {
        fprintf(stderr, "BMP_24bit_add_mosaic funtion: not is BMP or 24bit picture\n");
        return -1;
    }

    FILE *fp = fopen(name, "rb+");
    if(fp == NULL)
    {
        perror("BMP_24bit_add_mosaic funtion: fopen");
        return -1;
    }

    int BMP_width = 0;//代表每行的像素
    int BMP_height = 0;//代表有多少行
    fseek(fp, 0x12, SEEK_SET);//跳转到图片宽度(像素)存放的位置
    fread((void *)&BMP_width, 1, 4, fp);//读取宽度(x)
    fread((void *)&BMP_height, 1, 4, fp);//读取高度(y)
    if(BMP_height < 0)//如果是正序的BMP图片
    {
        BMP_height = -BMP_height;//保证是正数
    }
    if(star_x < 0 || star_x + width > BMP_width || star_y < 0 || star_y + height > BMP_height)//错误的参数
    {
        fprintf(stderr, "BMP_24bit_add_mosaic funtion: too low or to higt parameter\n");
        return -1;
    }

    const int BMP_ROW_btye = BMP_width * 24 / 8;//代表一行的字节数,24代表位深
    int w, h;//用于循环写
    const char write_pixel[3] = {0x00, 0x00, 0x00};//分别代表BGR,表示一个像素
    int ret_fseek = 0;//接收fseek函数返回值
    // printf("%d\n", BMP_ROW_btye);//debug
    fseek(fp, 0x36, SEEK_SET);//跳转第一个存放图像像素的数据,24位BMP字节排序为BGR,三个字节代表一个像素
    if((ret_fseek = fseek(fp, BMP_ROW_btye * star_y + star_x * 3, SEEK_CUR)) != 0)//跳转到开始像素
    {
        fclose(fp);
        fprintf(stderr, "BMP_24bit_add_mosaic funtion: fseek function fail! ret: %d\n", ret_fseek);
        return -1;
    }

    for(h = 0; h < height; h++)//改变height行
    {
        for(w = 0; w < width; w++)//改变一行指定(width)的像素个数
        {
            fwrite(&write_pixel, 1, sizeof(write_pixel), fp);
        }
        if((ret_fseek = fseek(fp, BMP_ROW_btye - width * 3, SEEK_CUR)) != 0)//跳过这一行的剩余像素
        {
            fclose(fp);
            fprintf(stderr, "BMP_24bit_add_mosaic funtion: fseek function fail! ret: %d\n", ret_fseek);
            return -1;
        }
    }


    fclose(fp);
    return 0;
}
