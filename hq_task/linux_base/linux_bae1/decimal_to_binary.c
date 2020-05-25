/*
已知bug:
    1.当输入大于1023或小于-1023时，会出现无法的转换，原因是因为超过了int类型存放数值的上限
    2.负数的处理是，取绝对值的数之后，转换为对应的二进制，然后加上-号
修复方法：
    1.考虑用long long型变量，或者放弃用整数类型接收，改用字符串类型接收
    2.应该换成字符串类型的接收
*/
#include <stdio.h>
#include <stdlib.h>

//int类型可以存放十进制位数是10位
#define int_limt 10

//将一个10进制数number转换为二进制数，成功保存ret_num中，并返回0；失败打印出错误原因，并返回-1
int decimal_to_binary(int number, int *ret_num);

int main(int argc, char const *argv[])
{
    int num = 0;
    printf("请输入要转换的数十进制数(负数不是其对应的补码) : ");
    scanf("%d", &num);//结束数据
    getchar();//清除缓存中的\n

    if(decimal_to_binary(num , &num) == 0)//转换十进制到二进制数
        printf("该数转换成二进制为 : %d\n", num);//成功
    else
        printf("错误！\n");//失败
    return 0;
}

/*因为不希望在主函数中调用,就声明在这里*/
//倒叙字符串,0转换成功,-1转换失败,并打印错误原因
int reverse_order_str(char *str);
//字符串转换为数字,0转换成功,-1转换失败,并打印错误原因
int string_to_int(const char *str, int *ret_int);

int decimal_to_binary(int number, int *ret_num)
{
    int ret = -1;
    char *bin_str_reverse = (char *)malloc(32);//倒叙存放二进制数
    char* const bin_str_head = bin_str_reverse;//如果用偏移的访问方式就可以不用再创建一个指针
    int negative_num = 0;//默认正数
    if(number < 0)
    {
        number = abs(number);//强制以正数处理
        negative_num = 1;//标记是个负数
        *bin_str_reverse++ = '-';//添加负号
    }
    
    while((unsigned)number > 0)//以倒序方式存放其对应的二进制数
    {
        *bin_str_reverse++ = (unsigned)number % 2 + '0';
        number /= 2;
    }
    *bin_str_reverse = '\0';//添加字符串结尾标记
    //字符串顺序的调整
    if(negative_num == 0)//正数的情况
    {
        reverse_order_str(bin_str_head);//倒叙排放字符串
    }
    else
    {
        reverse_order_str(bin_str_head + 1);//防止-号被倒叙
    }

    if(string_to_int(bin_str_head, ret_num) >= 0)//判断是否成功转换为数字
    {
       ret = 0;//成功转换
    }

    free(bin_str_head);
    return ret;
}

int string_to_int(const char *str, int *ret_int)
{
    int temp_int = 0;//暂存返回结果
    int carry = 1;//进位
    int len = 0;//判断长度
    int negative_num = 0;
    if(str == NULL || ret_int == NULL)//错误参数的处理
    {
        fprintf(stderr, "parameter error : NULL pointer\n");
        return -1;
    }
    if(*str == '-')
    {
        negative_num = 1;
        str++;
    }
    while(*str != '\0')//获得尾指针,指向'\0'
    {
        str++;//指针向后偏移
        len++;//获取长度
    }
    if(len > int_limt)//根据ret_int的类型可以存放的十进制位数而改变
    {
        fprintf(stderr, "overflow int type limit\n");
        return -1;
    }
    
    str--;//指向'\0'前一个字符
    while(len > 0)
    {
        if(*str >= '0' && *str <= '9')//转换为字符串
        {
            temp_int = temp_int + (*str - '0') * carry;
            carry = carry * 10;
        }
        str--;
        len--;
    }
    //成功返回
    if(negative_num == 0)//正数
    {
        *ret_int = temp_int;
    }
    else//负数
    {
        //负数的处理,最高位设为1，然后值加1,若int所占字节为4个字节，可改为(~temp_int| 0x80000000) + 1;
        temp_int = (~temp_int | (1 << (8 * sizeof(int) - 1))) + 1;
        *ret_int = temp_int;
    }
    return 0;
}


int reverse_order_str(char *str)
{
    int len = 0;//用于表示字符串长度
    int i;
    char ch_temp = '\0';
    if(str == NULL)
    {
        fprintf(stderr, "parameter error : NULL pointer\n");
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