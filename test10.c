#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * longestPalindrome(char * s);

int main(int argc, char const *argv[])
{
    printf("%s\n", longestPalindrome("ccc"));
    return 0;
}

char * longestPalindrome(char * s){
    int str_len = strlen(s);
    if(str_len <= 1)
    {
        static char one_char[2] = {0};
        one_char[0] = *s;
        return one_char; 
    }
    char *const s_head = s;//指向字符串第一个字符位置
    int i;
    char *max_star = s;//指向最大的开始
    int max_num = 1;//表示最大的个数
    int n;//当前个数

    s++;//从第二个字母开始
    while(*s != '\0')
    {
        
        if(s[-1] == s[1])//回文字的第一种情况
        {
            n = 1;
            for(i = 0;s[-i-1] == s[i + 1];i++)
            {
                n += 2;
                if(s-i-1 == s_head)
                    break;

            }
            if(max_num < n)
            {
                max_num = n;
                max_star = s-n/2;//指向开头
            }
        }
        if(s[-1] == s[0])//回文字的第二种情况
        {
            n = 0;
            for(i = 0;s[-i-1] == s[i];i++)
            {
                n += 2;
                if(s-i-1 == s_head)
                    break;

            }
            if(max_num < n)
            {
                max_num = n;
                max_star = s-n/2;//指向开头
            }
        }
        s++;
    }

    static char ret_str[1001];

    for(i = 0; i < max_num;i++)
    {
        ret_str[i] = max_star[i];
    }
    ret_str[i] = '\0';
    return ret_str;
}