#include <stdio.h>
#include <stdlib.h>

#define MAX 1024

char* receive(char* const p);
int judge_back_text(const char* const p);//return value(0==false 1==ture)

int main(int argc, char const *argv[])
{
    char *p = (char *)malloc(MAX);
   
    if(argc == 2)//如果带参数启动
    {
        if(judge_back_text(argv[1]))
            printf("%s is back text\n", argv[1]);
        else
            printf("%s not is back text\n", argv[1]);
            
    }
    else//直接启动
    {
        printf("请输入需判断的回文字:");
        if(judge_back_text(receive(p)))
        {
            printf("%s is back text(是回文字)\n",p);
        }
        else if(p != NULL && *p != '\0')
        {
            printf("%s not is back text(不是回文字)\n",p);
        }
    }

    free(p);
    return 0;
}

char* receive(char* const p)
{
    char *temp = p;
    int i = 0;
    while (1)
    {
        *temp = getchar();
        i++;//接收数据加1
        if(i > (MAX-1))//超出最大输入
        {
            fprintf(stderr,"error input : overtake input max value!\n");
            return NULL;
        }

        if (*temp == '\n' || *temp == '\0')//回车符的判断
        {
            *temp = '\0';
            return p;
        }
        /*else if(*temp > '9' || *temp < '0')//忽略字符(a-z,A-Z)的处理,只接收数字0-9
        {
            continue;
        }*/
        else
        {
            temp++;
        }
        
    }
    
    return NULL;
}

int judge_back_text(const char* const p)
{
    int offset = 0, advance = 0;//offset表示后偏移,advance是一个前偏移
    if( !p || *p == 0)//p == NULL的情况和*p == (int)0
    {
        fprintf(stderr,"error input : NULL input!\n");
        return 0;
    }

    while (*(p + offset + 1) != '\0')//获得字符串长度(不含'\0')
    {
        offset++;
    }
    if(!offset)//个位数是回文字
    {
        return 1;
    }

    while(*(p + advance) == *(p + offset))//回文字的判断
    {
        offset--;
        advance++;
        if( advance == offset || offset == (advance + 1))
        {
            return 1;//是回文字
        }
    }
    //不是回文字
    return 0;
}