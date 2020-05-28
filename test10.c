#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * longestPalindrome(char * s);

int main(int argc, char const *argv[])
{
    printf("%s\n", longestPalindrome("babad"));
    return 0;
}

char * longestPalindrome(char * s){
    int str_len = strlen(s);
    char *const s_head = s;//指向字符串第一个字符
    char *const s_rear = s + str_len - 1;//指向字符串最后一个有效字符
    int i;
    char *max_star = NULL;//指向最大的开始
    int max_num = 0;//表示最大的个数
    int n;//当前个数

    s++;//从第二个字母开始
    while(s != s_rear)
    {
        if(s[-1] == s[0])//回文字的第一种情况
        {
            n = 0;
            for(i = 0;s[-i-1] == s[i];i++)
            {
                n += 2;
                if(s-i-1 == s_head)
                    break;
                else if(s+i == s_rear)
                    break;
            }
            if(max_num < n)
            {
                max_num = n;
                max_star = s;
            }
        }
        else if(s[-1] == s[1])//回文字的第二种情况
        {
            n = 1;
            for(i = 0;s[-i-1] == s[i + 1];i++)
            {
                n += 2;
                if(s-i-1 == s_head)
                    break;
                else if(s+i+1 == s_rear)
                    break;
            }
            if(max_num < n)
            {
                max_num = n;
                max_star = s;
            }
        }
        s++;
    }

    char *ret_str = (char *)malloc(max_num + 1);
    for(i = 0; i < max_num;i++)
    {
        ret_str[i] = max_star[i];
    }
    ret_str[++i] = '\0';
    return ret_str;
}