#include <stdio.h>

//删除字符串中重复的字符
int delete_repeat_string(char *str);

int main(int argc, char const *argv[])
{
    char str[] = "aaaabbbbccccc";
    printf("当前字符串为 : %s\n", str);
    if(delete_repeat_string(str) >= 0)//尝试删除重复字符
    {
        printf("删除成功，删除后的字符串为 : %s\n", str);//成功输出结果
    }
    else
    {
        printf("删除失败!\n");//失败告诉异常
    }
    return 0;
}

/*因为不希望在主函数中调用，就声明在这里*/
//删除一个字符串中的字符
int delete_char(char *del_cp);

int delete_repeat_string(char *str)
{
    int i = 0;
    if(str == NULL)
    {
        fprintf(stderr, "parameter error : NULL pointer\n");
        return -1;
    }

    while(*(str + i + 1) != '\0')//结束情况的跳出
    {
        if(*(str + i) == *(str + i + 1))
        {
            if(delete_char((str + i + 1)) < 0)//删除这个字符
            {
                return -1;//如果失败就返回-1
            }
        }
        else
        {
            i++;
        }
    }
    return 0;
}

int delete_char(char *del_cp)
{
    if(del_cp == NULL || *del_cp == '\0')//异常情况的处理
    {
        fprintf(stderr, "parameter error : NULL pointer or NULL string\n");
        return -1;
    }
    while(*del_cp != '\0')//覆盖掉该字符
    {
        *del_cp = *(del_cp + 1);
        del_cp++; 
    }

    return 0;
}