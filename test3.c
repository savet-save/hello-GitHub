#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

int *do_somethings(int *temp);

int main(int argc, char const *argv[])
{
    pthread_t newthid;
    int c = 2;
    printf("thread_id:%I64u\n", pthread_self());;
    if(pthread_create(&newthid, NULL, (void *)do_somethings, (void *)&c) == 0)
    {
        printf("thread_id:%I64u\n", pthread_self());
    }
    pthread_join(newthid, NULL);

    return 0;
}


int *do_somethings(int *temp)
{
    *temp = *temp * *temp;
    printf("new thread_id:%Iu  temp:%d\n", pthread_self(), *temp);
    return NULL;
}
