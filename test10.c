#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int lengthOfLongestSubstring(char * s);

int main(int argc, char const *argv[])
{
    printf("%d\n", lengthOfLongestSubstring("bbbbb"));
    return 0;
}

int lengthOfLongestSubstring(char * s){

    int max = 0;
    char hash[128] = {0};
    char *temp;
    int n = 0;
    while(*s != '\0')
    {
        temp = s;
        n = 0;
        while(*temp != '\0')
        {
            if(hash[(int)*temp]==0)
            {
                hash[(int)*temp]++;
                n++;
            }
            else
            {
                break;
            }
            temp++;
        }
        if(max < n)
            max = n;
        memset(hash, 0, sizeof(hash));
        s++;
    }
    return max;
}