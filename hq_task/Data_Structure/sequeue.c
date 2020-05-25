#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

typedef struct _queue
{
    int data[SIZE];
    int front;
    int rear;
}SeQueue;

//创建顺序队列
SeQueue* creatSeQueue(void)
{
    SeQueue *qu = (SeQueue *)malloc(sizeof(SeQueue));
    if(qu == NULL)
    {
        return NULL;
    }
    memset(qu->data, 0, sizeof(qu->data));
    qu->front = 0;
    qu->rear = 0;
    return qu;
}

//判断队列是否为空
//为空返回1
//不为空返回0
int judge_seQueue_empt(SeQueue *qu)
{
    if(qu == NULL)
    {
        return -1;
    }
    return (qu->front == qu->rear ? 1 : 0);
}

//判断队列是否满
//满返回1
//不满返回0
int judge_seQueue_full(SeQueue *qu)
{
    if (qu == NULL)
    {
        return -1;
    }

    if((qu->front - qu->rear) == 1 || (qu->rear - qu->front) == SIZE -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//入顺序队列
int Enqueue_seQueue(SeQueue *qu, int data)
{
    if(judge_seQueue_full(qu) != 0)
    {
        return -1;
    }
    qu->data[qu->rear] = data;
    qu->rear++;
    qu->rear %= SIZE;
    return 0;
}

//出顺序队列
int Dequeue_seQueue(SeQueue *qu, int* ret_data)
{
    if(judge_seQueue_empt(qu) != 0)
    {
        return -1;
    }
    if(ret_data != NULL)
        *ret_data = qu->data[qu->front];
    qu->front++;
    qu->front %= SIZE;
    return 0;
}

int print_seQueue(SeQueue *qu)
{
    if(NULL == qu)
    {
        return -1;
    }
    int i = qu->front;
    while(i != qu->rear)
    {
        printf("%d ", qu->data[i++]);
        i %= SIZE;
    }
    printf("\n");
    return 0;
}

int clear_seQueue(SeQueue *qu)
{
    if(NULL == qu)
    {
        return -1;
    }
    qu->front = 0;
    qu->rear = 0;
    return 0;
}

void destroy_seQueue(SeQueue **qu)
{
    clear_seQueue(*qu);
    free(*qu);
    *qu = NULL;
    return ;
}

int main(int argc, char const *argv[])
{
    SeQueue *qu = creatSeQueue();
    int i = 0;
    while(i < 20)
    {
        Enqueue_seQueue(qu, i++);
    }
    print_seQueue(qu);
    
    int ret = 0;
    for (i = 0; i < 20; i++)
    {
        if(Dequeue_seQueue(qu, &ret) == -1)
            break;
        printf("%d ", ret);
    }
    printf("\n");

    for ( i = 0; i < 20; i++)
    {
        Enqueue_seQueue(qu, 20 + i);
    }
    print_seQueue(qu);

    for (i = 0; i < 20; i++)
    {
        if(Dequeue_seQueue(qu, &ret) == -1)
            break;
        printf("%d ", ret);
    }
    printf("\n");

    print_seQueue(qu);

    clear_seQueue(qu);
    i = 0;
    while(i < 20)
    {
        Enqueue_seQueue(qu, i++);
    }
    print_seQueue(qu);

    destroy_seQueue(&qu);
    printf("%p\n", qu);
    return 0;
}
