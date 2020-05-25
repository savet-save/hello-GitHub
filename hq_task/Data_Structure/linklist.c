#include <stdio.h>
#include <stdlib.h>

typedef int data_t;


//构造链表节点类型
typedef struct node{
	data_t data;//数据域
	struct node *next;//指针域 值为下一个节点的地址
}LinkList;

//创建空链表，即链表中只有一个头节点
LinkList *createLinklist(void)
{
	LinkList *head = (LinkList *)malloc(sizeof(LinkList));//在堆区给头节点申请空间
	if(NULL == head)
		return NULL;

	head->data = -1;//任意值
	head->next = NULL;//表示链表中只有头节点，即链表为空
		
	return head;//返回头节点的首地址
}

//判空
int linklist_is_empty(LinkList *head)
{
	if(NULL != head)	
		return ((head->next == NULL)?1:0);//判断头节点的next是否为NULL,如果为NULL,则说明链表为空
	else
		return -1;
}

//计算链表中节点的个数
int getLengthLinklist(LinkList *head)
{
	if(NULL == head)
		return -1;

	int len = 0;//计数
	LinkList *p = head->next;//p指向第一个有效节点
	while(p != NULL)
	{
		len++;	
		p = p->next;//p指向下一个节点
	}

	return len;
}

/***********************************************************************
功能：在pos位置处添加新节点 pos从0开始
参数：
	head:头节点的首地址
	pos:要插入节点的位置 pos从0开始,pos的合法值为0~len
	data:新节点的数据域
返回值：
	成功：0
	失败：-1
***********************************************************************/
int insertLinklistByPos(LinkList *head, int pos, data_t data)
{
	if(NULL == head)
		return -1;
	int len = getLengthLinklist(head);
	if(-1 == len)
		return -1;
	
	if(pos < 0 || pos > len)//判断位置的合法性
		return -1;

	//准备新节点
	LinkList *new = (LinkList *)malloc(sizeof(LinkList));
	if(NULL == new)
		return -1;
	new->data = data;//给new节点的data赋值
	new->next = NULL;//将new节点的next值为NULL

	LinkList *p = head;

	//find pos-1
	while(pos--)
		p = p->next;
	
	new->next = p->next;
	p->next = new;

	return 0;
}

//delete node by pos
int deleteLinklistByPos(LinkList *head, int pos)
{
	if(NULL == head)
		return -1;
	if(linklist_is_empty(head))
		return -1;

	int len = getLengthLinklist(head);
	if(pos < 0 || pos > len-1)
		return -1;
	
	LinkList *p = head;
	LinkList *q = NULL;
	
	while(pos--)//pos-1
		p = p->next;
	
	q = p->next;
	p->next = q->next;
	free(q);
	q = NULL;

	return 0;
}

//delete node by data
int deleteLinklistByData(LinkList *head, data_t data)
{
	if(NULL == head)
		return -1;
	LinkList *p = head;
	LinkList *q = NULL;
	while(p->next != NULL)
	{
		if(p->next->data == data)//p是值为data节点的前一个节点的地址
		{
			q = p->next;
			p->next = q->next;
			free(q);
			q = NULL;
			return 0;
		}
		else
			p = p->next;
	}

	return -1;

}

//find node by pos
LinkList *findLinklistByPos(LinkList *head, int pos)
{
	int len = getLengthLinklist(head);
	if(-1 == len)
		return NULL;
	if(pos < 0 || pos > len-1)
		return NULL;
#if 0
	LinkList *p = head->next;
	while(pos--)
		p = p->next;

	return p;
#else
	LinkList *p = head;
	while(pos--)
		p = p->next;

	return (p->next);
	

#endif
}

//find node by data
LinkList *findLinklistBydata(LinkList *head, data_t data)
{
	if(NULL == head)
		return NULL;
	LinkList *p = head->next;
	while(p != NULL)
	{
		if(p->data == data)
			return p;
		else
			p = p->next;
	}
	
	return NULL;
}

//change node by pos
int changeLinklistByPos(LinkList *head, int pos, data_t new_data)
{
	LinkList *p = findLinklistByPos(head, pos);
	if(NULL == p)
		return -1;
	p->data = new_data;
		
	return 0;
}


//change node by data
int changeLinklistByData(LinkList *head, data_t old_data, data_t new_data)
{
	LinkList *p = findLinklistBydata(head, old_data);
	if(NULL == p)
		return -1;
	
	p->data = new_data;

	return 0;
}

//clear linklist
void clearLinklist(LinkList *head)
{
	if(NULL == head)
		return;
	
	LinkList *p = head->next;
	LinkList *q = NULL;
	head->next = NULL;
	
	while(p != NULL)
	{
		q = p->next;
		free(p);
		p = q;
	}

	return ;

}

//destory linklist
void destoryLinklist(LinkList **head)
{
	
	clearLinklist(*head);
	free(*head);
	*head = NULL;

	return ;
}


//printf node of linklist
void printfLinklist(LinkList *head)
{
	if(NULL == head)
		return ;
#if 0
	LinkList *p = head->next;
	while(NULL != p)
	{
		printf("%d ",p->data);
		p = p->next;
	}
#else
	LinkList *p = head;
	while(p->next != NULL)
	{
		printf("%d ",p->next->data);
		p = p->next;
	}
#endif
	printf("\n");
	
	return ;
}

//链表逆序
void reverseLinkList(LinkList *head)
{
	if(NULL == head)
	{
		return ;
	}
	LinkList* p = head->next;//指向第一个成员
	if(NULL == p)//没有成员
	{
		return ;
	}

	LinkList* q = NULL;//保存正序的下一个地址
	head->next = NULL;
	while(p)//进行逆序
	{
		q = p->next;//获取正序下一个地址

		p->next = head->next;//头插
		head->next = p;

		p = q;//用于下次插入
	}

	
	return ;
}

int main()
{
	LinkList *head = createLinklist();//创建头节点
	if(NULL == head)
	{
		printf("malloc failed\n");
		return -1;
	}

	int ret = linklist_is_empty(head);//判断链表是否为空
	printf("ret = %d\n",ret);

	int len = getLengthLinklist(head);
	if(-1 == len)
	{
		printf("getLengthLinklist error\n");
		return -1;
	}
	printf("len=%d\n",len);

	int i = 0;
	while(i < 10)
	{
		insertLinklistByPos(head, i, i);
		i++;
	}
	printfLinklist(head);

	ret = insertLinklistByPos(head, 5, 50);
	printfLinklist(head);

	i = 0;
	while(i < 5)
	{
		deleteLinklistByPos(head, 0);
		i++;
	}
	
	printfLinklist(head);
		
	deleteLinklistByPos(head, 4);//
	printfLinklist(head);


	LinkList *p = findLinklistByPos(head, 3);
	if(NULL == p)
		return -1;
	printf("p->data=%d\n",p->data);	

	changeLinklistByPos(head, 3, 300);
	printfLinklist(head);

	reverseLinkList(head);
	printfLinklist(head);
	
	destoryLinklist(&head);
	return 0;
}
