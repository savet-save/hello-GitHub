#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//最大十进制位
#define MAX_CHAR 512
//字符串做十进制加法, 要保证dst的位置足够大(装得下加完后的字符串).
int add_decimal(char *dst, const char *src);
//用于接收数据
char* receive(char *p);

int main(int argc, char const *argv[])
{
    char *bin_str = (char *)malloc(MAX_CHAR + 1);//保证装得下最高位的进位

    printf("请输入要加一的数(忽略非数字) : ");
    receive(bin_str);//开始接收数据
    add_decimal(bin_str, "1");//进行加'1'操作

    printf("结果是 : %s\n", bin_str);
    free(bin_str);

    return 0;
}


char* receive(char *p)
{
    char *temp = p;
    int i = 0;
    while (1)
    {
        *temp = getchar();
        i++;//接收数据加1
        if(i > (MAX_CHAR - 1))//超出最大输入,空一个做进位,一个做'\0'
        {
            fprintf(stderr,"error input : overtake input max value!\n");
            return NULL;
        }

        if (*temp == '\n' || *temp == '\0' || *temp == ' ')//结束符的判断
        {
            *temp = '\0';
            return p;
        }
        else if(*temp < '0' || *temp > '9')//忽略字符(a-z,A-Z)的处理,只接收数字0-9
        {
            continue;
        }
        else
        {
            temp++;
        }
        
    }
    
    return NULL;
}

/*因为不希望在主函数中调用,就声明在这里*/
//倒叙字符串,0转换成功,-1转换失败,并打印错误原因
int reverse_order_str(char *str);
//字符串右移一个字符,空出的位子填字符'0',需要保证存放区域空间足够,不然可能会引起段错误
int str_right_shift_char(char *str, int number);

int add_decimal(char *dst, const char *src)
{
    char* const head = dst;//保存字符串头的位置
    if(dst == NULL || src == NULL)
    {
        fprintf(stderr, "parameter error : NULL pointer\n");
        return -1;
    }

    char *temp = (char *)malloc(strlen(src) + 1);//用于缓存src的内容,防止修改src的值
    char* const temp_head = temp;//保存该字符串头的位置
    strcpy(temp, src);//完成内容的拷贝
    
    //要空出字符串个数的差值+1
    int len_src = strlen(temp_head);
    int len_dst = strlen(head);
    int number = (len_src - len_dst) > 0 ? (len_src - len_dst) + 1 : 1;
    if(str_right_shift_char(dst, number) < 0)//空出位置,保证两个字符串长度相匹配
    {
        return -1;
    }
    if(reverse_order_str(head) < 0)//从最小开始求和
    {
        return -1;
    }
    if(reverse_order_str(temp_head) < 0)//从最小开始求和
    {
        return -1;
    }

    while(*temp != '\0')//进行十进制加法,'满10进1'
    {
        *dst += *temp - '0';//进行字节位加法运算
        if(*dst >= '9')//判断是否需要进位
        {
            *(dst + 1) += 1;//进行进位+1
            *dst = '0';//如果进位就归0
        }
        dst++;
        temp++;
    }
    while (*dst != '\0')//可能没处理完,保证目标串里不会出现58
    {
        if(*dst >= '9')
        {
            *(dst + 1) += 1;
            *dst -= 10;//归0的第二种方式
        }
        dst++;
    }
    
    if(reverse_order_str(head) < 0)//完成正常顺序
    {
        return -1;
    }

    if(strncmp(head, "0", 1) == 0)//防止开头出现的0
    {
        strcpy(head, head + 1);//删除这个0
    }

    free(temp_head);
    return 0;
}


int reverse_order_str(char *str)
{
    int len = 0;//用于表示字符串长度
    int i;
    char ch_temp = '\0';
    if(str == NULL)
    {
        fprintf(stderr, "parameter error : reverse_order_str() is NULL pointer\n");
        return -1;
    }
    while(*(str+len) != '\0')
    {
        len++;
    }
    if(len <= 1)//不用交换
    {
        return 0;
    }
    len = len - 1;//表示到字符串行尾的的偏移
    for (i = 0; i < len; i++, len--)
    {
        ch_temp = *(str + len);
        *(str + len) = *(str+ i);
        *(str+ i) = ch_temp;
    }

    return 0;
}

int str_right_shift_char(char *str, int number)
{
    
    int str_len = strlen(str);//要拷贝的字符个数
    str = str + str_len + number;//为了指向'\0'
    if(str == NULL)
    {
        fprintf(stderr, "parameter error : str_right_shift_one_char() is NULL pointer\n");
        return -1;
    }
    if(number <= 0)
    {
        return 0;
    }
    while (str_len + 1)//为了拷贝'\0'
    {
        *str = *(str - number);//为了从'\0'开始拷贝
        str--;
        str_len--;
    }

    while(number)//空出的位置填'0'
    {
        *str = '0';
        str--;
        number--;
    }

    return 0;
}
