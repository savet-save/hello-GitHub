#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* read_stdin(char *str);

int main(int argc, char const *argv[])
{
    pthread_t pid;
    char *str = (char *)malloc(100);
    pthread_create(&pid, NULL, (void* (*)(void *))read_stdin , (void *)str);
    char *ret;
    pthread_join(pid, (void **)&ret);
    printf("%s\n", str);
    printf("%s\n", ret);

    pthread_create(&pid, NULL, (void* (*)(void *))read_stdin, (void *)str);
    pthread_detach(pid);
    printf("%s\n", str);

    free(str);
    return 0;
}

void* read_stdin(char *str)
{
    int ch;
    while((ch = getchar()) != '\n' && (ch != EOF))
    {
        *str++ = ch;
    }
    *str = '\0';
    fprintf(stderr,"over\n");
    return "success complete read_stdin function";
}