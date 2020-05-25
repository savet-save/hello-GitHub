#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    char buf[10] = "12345";//设置要输入的内容
    /*开始设置输入缓冲数据*/
    memcpy(stdin->_base, buf, 6);//写入要输入内容
    stdin->_cnt = 6;//设置写入了多少字节,要和实际写入字节相对应
    /*结束设置*/
    int ch;//接收字符
    while(stdin->_cnt)//判断输入缓冲中拥有的字符个数，防止阻塞当前线程
    {
        ch = getchar();//获取字符,然后_ptr++,且_cnt--,
        printf("%c ", ch);
        //printf("p:%p \n", ch, stdin->_ptr);
    }
    printf("\nend\n");
    //putchar( getc(stdin));
    return 0;
}
