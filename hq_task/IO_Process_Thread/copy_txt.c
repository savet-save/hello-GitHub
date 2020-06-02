#include <stdio.h>

//复制src文件的内容到dst文件中
int copy(const char *dst_filename, const char *src_filename);

int main(int argc, char const *argv[])
{
    if(argc == 3)//如果带参数启动
        copy(argv[2], argv[1]);
    else//没带参数
        copy("2.txt", "1.txt");

    return 0;
}

int copy(const char *dst_filename, const char *src_filename)
{
    if(dst_filename == NULL || src_filename == NULL)
    {
        fprintf(stderr, "error parameter : copy function\n");
        return -1;
    }
    FILE *fp_dst = fopen(dst_filename, "wb");
    if(fp_dst == NULL)
    {
        perror("fopen dst fail");
        return -1;
    }
    FILE *fp_src = fopen(src_filename, "rb");
    if(fp_src == NULL)
    {
        perror("fopen src fail");
        return -1;
    }
    int ch;
    while((ch = fgetc(fp_src)) != EOF)
    {
        fputc(ch, fp_dst);
    }

    return 0;
}