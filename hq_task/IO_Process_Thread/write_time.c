#include <stdio.h>
#include <time.h>
#include <string.h>

//向指定文件中写入时间带行号
int write_time(const char *path);
//延迟指定毫秒
int delay_ms(int de_time);
//获取一个已经打开的流对应的文件的行数
int get_line(FILE *fp);

int main(int argc, char const *argv[])
{
    if(argc == 2)
        write_time(argv[1]);
    else
        write_time("3.txt");
    return 0;
}

int write_time(const char *path)
{
    time_t t = time(NULL);
    struct tm* lt = localtime(&t);
    FILE *fp = fopen(path, "a+");
    if(fp == NULL)
    {
        perror("fopen");
        return -1;
    }
    int line = get_line(fp);
    if(line == -1)
    {
        fprintf(stderr, "get_line funtion fail\n");
        return -1;
    }
    while(1)
    {
        fprintf(fp, "%d,  %04d-%02d-%02d %02d:%02d:%02d\n", line, lt->tm_year+1900, lt->tm_mon+1,
                lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec);
        delay_ms(1000);//延迟1s
        t = time(NULL);
        lt = localtime(&t);
        line++;
        fflush(fp);
    }
    return 0;
}
//获取一个打开的文件的行数
int get_line(FILE *fp)
{
    if(fp == NULL)
    {
        return -1;
    }
    int line = 1;
    char buf[40];
    while(fgets(buf, sizeof(buf), fp) != NULL)
    {
        if(buf[strlen(buf) - 1] == '\n')
        {
            line++;
        }
    }
    return line;
}

int delay_ms(int de_time)
{
    clock_t c_star = clock();
    if(de_time <= 0)
    {
        return -1;
    }
    while(clock() - c_star < de_time);
    return 0;
}