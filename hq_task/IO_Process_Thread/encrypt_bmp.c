#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int encrypt_bmp(const char *en_bmp_path);

int main(int argc, char const *argv[])
{
    encrypt_bmp("1.bmp");
    return 0;
}

int encrypt_bmp(const char *en_bmp_path)
{
    int fd = open(en_bmp_path, O_RDWR);
    if(fd < 0)
    {
        perror("open");
        return -1;
    }
    char arr[10] = {0};
    char temp;
    read(fd, (void *)arr, sizeof(arr));
    temp = arr[0];//chang
    arr[0] = arr[1];
    arr[1] = temp;
    lseek(fd, 0, SEEK_SET);
    write(fd, (void *)arr, sizeof(arr));
    return 0;
}