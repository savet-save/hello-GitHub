#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int data_t;
typedef struct _node
{
    data_t data;
    struct _node *next;
}LinkList;

typedef struct _queue
{
    LinkList *front;
    LinkList *rear;
}LinkQueue;


LinkQueue *creat_linkQueue(void)
{
    LinkQueue *lq = (LinkQueue *)malloc(sizeof(LinkQueue));
    if(NULL == lq)
    {
        return NULL;
    }
    // memset(lq, 0, sizeof(LinkQueue));//可要可不用
    lq->rear = lq->front = (LinkList *)malloc(sizeof(LinkList));
    if(NULL == lq->front)
    {
        return NULL;
    }
    lq->front->data = -1;
    lq->front->next = NULL;

    return lq;
}

int get_linkQueue_lenth(LinkQueue *lq)
{
    if(NULL == lq)
    {
        return -1;
    }
    LinkList *p = lq->front->next;
    int len = 0;
    while(p)
    {
        len++;
        p = p->next;
    }
    return len;
}

int jugde_linkQueue_empty(LinkQueue *lq)
{
    if(NULL == lq || lq->front == NULL)
    {
        return -1;
    }
    // return (lq->front == lq->rear ? 1 : 0);//第一种方法
    return (lq->front->next == NULL ? 1 : 0);//第二种方法
}

int en_linkQueue(LinkQueue *lq, data_t data)
{
    if(NULL == lq)
    {
        return -1;
    }
    LinkList *new_listList = (LinkList *)malloc(sizeof(LinkList));
    if(new_listList == NULL)
        return -1;

    new_listList->next = NULL;
    new_listList->data = data;

    //新节点入队，即新节点添加到队尾
    lq->rear->next = new_listList;//改变队列
    lq->rear = new_listList;

    return 0;
}

int de_listQueue(LinkQueue *lq, data_t *data)
{
    if(jugde_linkQueue_empty(lq) != 0)
    {
        return -1;
    }
    LinkList *de = lq->front->next;
    lq->front->next = de->next;//如果取完lq->front->next的指为NULL
    if(data != NULL)
        *data = de->data;
    free(de);
    
    if(jugde_linkQueue_empty(lq) == 1)//变成了"空"队列,队列中所有成员已经取完了
        lq->rear = lq->front;//初始化,防止队尾指针指向一个已经释放的内存
    return 0;
}

int print_listQueue(LinkQueue *lq)
{
    if(lq == NULL)
    {
        return -1;
    }

    LinkList *pr = lq->front->next;//获取第一个成员
    while(pr)
    {
        printf("%d ", pr->data);
        pr = pr->next;
    }
    printf("\n");
    return 0;
}

int clear_listQueue(LinkQueue *lq)
{
    if(jugde_linkQueue_empty(lq) != 0)//如果是空队列
    {
        return -1;
    }
    LinkList *del;//用于释放
    while(lq->front->next)
    {
        del = lq->front->next;
        lq->front->next = del->next;//指向下一个成员地址
        free(del);
    }
    lq->rear = lq->front;//初始状态
    return 0;
}

void destroy_linkQueue(LinkQueue **lq)
{
    clear_listQueue(*lq);
    free((*lq)->front);
    (*lq)->front = NULL;
    free(*lq);
    *lq = NULL;
    return ;
}

int main(int argc, char const *argv[])
{
    LinkQueue *lq = creat_linkQueue();
    int i;
    for ( i = 1; i <= 10; i++)
    {
        en_linkQueue(lq, i);
    }
    print_listQueue(lq);
    
    printf("len=%d\n", get_linkQueue_lenth(lq));

    int ret = 0;
    for (i = 0; i < 11; i++)
    {
        if(de_listQueue(lq, &ret) != 0)//没有成功
            break;
        printf("%d ", ret);
    }
    printf("\n");

    clear_listQueue(lq);
    en_linkQueue(lq, 66);
    en_linkQueue(lq, 77);
    print_listQueue(lq);

    destroy_linkQueue(&lq);
    
    return 0;
}
