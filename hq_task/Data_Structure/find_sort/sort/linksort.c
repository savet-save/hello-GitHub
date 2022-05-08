#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int data_t;
typedef struct node{
	data_t data;
	struct node *next;
}linklist;

linklist *createLinklist()
{
	linklist *head = (linklist *)malloc(sizeof(linklist));
	if(NULL == head)
		return NULL;
	head->data = -1;
	head->next = NULL;
	
	return head;
}

int getLengthLinklist(linklist *head)
{
	if(NULL == head)
		return -1;
	int len = 0;
	linklist *p = head;
	while(NULL != p)
	{
		len++;
		p = p->next;
	}
		
	return len;
}

int insertLinklist(linklist *head, int pos, data_t data)
{
	if(NULL == head)
		return -1;
	int len = getLengthLinklist(head);
	if(pos < 0 || pos > len)
		return -1;
	linklist *new = (linklist *)malloc(sizeof(linklist));
	if(NULL == new)
		return -1;
	new->data = data;
	new->next = NULL;

	linklist *p = head;
	while(pos--)
		p = p->next;
	new->next = p->next;
	p->next = new;

	return 0;
}

void printLinklist(linklist *head)
{
	if(NULL == head)
		return ;
	linklist *p = head->next;
	while(p != NULL)
	{
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");
	
	return ;
}

int linkSort(linklist *head)
{
	if(NULL == head)
		return -1;
	linklist *p = head->next;//p为待插入节点
	linklist *q = NULL;
	linklist *u = NULL;
	linklist *r = NULL;
	head->next = NULL;//将链表置空

	while(p != NULL)
	{
		r = head;
		q = r->next;
		while(q != NULL)//找到p的位置
		{
			if(q->data <= p->data)
			{
				r = q;//r为要插入位置的前一个位置
				q = q->next;
			}
		}
		u = p->next;
		p->next = r->next;
		r->next = p;
		p = u;
	}
	return 0;
}	

int main()
{
	linklist *head = createLinklist();	
	if(NULL == head)
	{
		printf("malloc failed\n");
		return -1;
	}

	int i = 0;
	while(i < 10)
	{
		insertLinklist(head, i, i+1);
		i++;
	}
	printLinklist(head);

	linkSort(head);
	printLinklist(head);



	return 0;
}
