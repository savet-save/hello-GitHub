#include <stdio.h>
#include <stdlib.h>

typedef int data_t;

//构造节点类型
typedef struct node{
	data_t data;
	struct node *next;
}linklist;

//构造链式队列类型
typedef struct queue{

	linklist *front;//指向队头节点的前一个节点指针
	linklist *rear;//指向队尾节点的指针
}lqueue;

//创建空链式队列,即队列中只有头节点
lqueue *createLqueue(void)
{
	lqueue *lq = (lqueue *)malloc(sizeof(lqueue));//给队列开辟空间
	if(NULL == lq)
		return NULL;
	
	lq->rear = lq->front = (linklist *)malloc(sizeof(linklist));//给链表头节点开辟空间
	if(lq->front == NULL) 
		return NULL;

	lq->front->data = -1;//操作头节点的data
	lq->front->next = NULL;//表示队列为空
	

	return lq;

}

//判空
int lqueue_is_empty(lqueue *lq)
{
	if(NULL != lq)
		return ((lq->front == lq->rear)?1:0);
	else
		return -1;
}

//计算节点个数
int getLengthLqueue(lqueue *lq)
{
	if(NULL == lq)
		return -1;

	int len = 0;
	linklist *p = lq->front->next;//p指向队头节点
	while(p != NULL)
	{
		len++;
		p = p->next;
	}

	return len;
}

//入队
int enLqueue(lqueue *lq, data_t data)
{
	if(NULL == lq)
		return -1;
	
	//准备新节点
	linklist *new = (linklist *)malloc(sizeof(linklist));
	if(NULL == new)
		return -1;
	new->data = data;
	new->next = NULL;

	//新节点入队，即新节点添加到队尾
	lq->rear->next = new;
	lq->rear = new;//rear指针指向队尾节点(即new节点)

	return 0;
}

//出队
data_t deLqueue(lqueue *lq)
{
	if(lqueue_is_empty(lq))
		return -1;
	
	linklist *p = lq->front->next;//p指向队头节点的指针
	data_t data = p->data;//data保存队头节点的data
	lq->front->next = p->next;//将头节点和新的队头节点关联起来
	free(p);
	p = NULL;

	//判断队列是否为空
	if(lq->front->next == NULL)
		lq->rear = lq->front;//让rear指针指向头节点

	return data;
}

//打印队列中各个节点的data
void printLqueue(lqueue *lq)
{
	if(NULL == lq)
		return ;
	linklist *p = lq->front->next;//p指向队头节点
	while(p != NULL)
	{
		printf("%d ",p->data);
		p = p->next;
	}

	printf("\n");

	return ;
}

//清空队列
void clearLqueue(lqueue *lq)
{
	if(lqueue_is_empty(lq) != 0)//如果是空队列
    {
        return ;
    }
    linklist *del;//用于释放
    while(lq->front->next)
    {
        del = lq->front->next;
        lq->front->next = del->next;//指向下一个成员地址
        free(del);
    }
    lq->rear = NULL;

	return ;
}

//销毁队列
void destoryLqueue(lqueue **lq)
{
	clearLqueue(*lq);
    free((*lq)->front);
    (*lq)->front = NULL;
    free(*lq);
    *lq = NULL;
    return ;


}

int main()
{
	lqueue *lq = createLqueue();
	if(NULL == lq)
	{
		printf("malloc failed\n");
		return -1;
	}
	int i = 0;
	while(i < 10)
	{	
		enLqueue(lq, i+1);
		i++;
	}

	printLqueue(lq);

	int len = getLengthLqueue(lq);
	printf("len=%d\n",len);

	i = 0;
	data_t data;
	while(i < 12)
	{
		data = deLqueue(lq);
		printf("%d ",data);
		i++;
	}
	printf("\n");

	enLqueue(lq, 22);
	enLqueue(lq, 33);
	printLqueue(lq);

	destoryLqueue(&lq);

	return 0;
}
