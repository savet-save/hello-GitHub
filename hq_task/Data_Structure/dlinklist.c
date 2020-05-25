#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef int data_t;

//构造双向链表节点类型
typedef struct node{

	data_t data;//数据域
	struct node *next;//保存下一个节点的地址
	struct node *prior;//保存前一个节点的地址

}dlinklist;

//创建空双向链表
dlinklist *createDlinklist(void)
{
	dlinklist *head = (dlinklist *)malloc(sizeof(dlinklist));
	if(NULL == head)
		return NULL;
	
	head->data = -1;
	head->next = NULL;
	head->prior = NULL;
		
	return head;
}

//判空
int dlinklist_is_empty(dlinklist *head)
{
	if(NULL != head)
		return ((head->next == NULL)?1:0);
	else
		return -1;
}

//获取链表中节点个数
int getLengthDlinklist(dlinklist *head)
{
	if(NULL == head)
		return -1;
	int len = 0;
	dlinklist *p = head->next;
	while(p != NULL)
	{
		len++;
		p = p->next;
	}

	return len;
}

//按位置插入
//pos：0～len
int insertDlinklistByPos(dlinklist *head, int pos, data_t data)
{
	int len = getLengthDlinklist(head);
	if(-1 == len)
		return -1;
	if(pos < 0 || pos > len)//判断位置的合法性
		return -1;

	//准备新节点
	dlinklist *new = (dlinklist *)malloc(sizeof(dlinklist));
	if(NULL == new)
		return -1;
	new->data = data;
	new->next = NULL;
	new->prior = NULL;


	dlinklist *p = head;
	//得到pos-1位置处节点的地址p
	while(pos--)
		p = p->next;
	
	//在pos位置插入新节点new
	if(p->next == NULL)//说明在表尾插入新节点new
	{
		new->next = p->next;
		new->prior = p;	
		p->next = new;
	}
	else//在中间位置插入节点new
	{
		new->next = p->next;
		new->prior = p;
		p->next->prior = new;
		p->next = new;
	}

	return 0;
}

//按位置删除
//pos: 0~len-1
int deleteDLinklistByPos(dlinklist *head, int pos)
{
	if(dlinklist_is_empty(head))//判空
		return -1;
	int len = getLengthDlinklist(head);
	if(pos < 0 || pos > len-1)//判断位置的合法性
		return -1;
	
	dlinklist *p = head;
	dlinklist *q = NULL;

	while(pos--)//得到pos-1位置节点的地址p
		p = p->next;

		
	q = p->next;
	if(p->next->next == NULL)//说明要删除节点为表尾节点
	{
		p->next = NULL;
	}
	else//说明要删除节点为中间位置节点
	{
		p->next = q->next;
		q->next->prior = p;
	}
	free(q);
	q = NULL;
	
	return 0;
}

//按值删除节点
int deleteDlinklistByData(dlinklist *head, data_t data)
{
	if(head == NULL)
	{
		return -1;
	}
	dlinklist *p = head; 
	dlinklist *q = NULL;//用于删除
	while (p->next)
	{
		if(p->next->data == data)
		{
			q = p->next;
			p->next = q->next;
			if(q->next != NULL)//不是最后一个节点
				q->next->prior = p;
			free(q);
			break;
		}
		p = p->next;
	}
	
	return 0;
}

//按位置查找节点，返回节点的地址
dlinklist *findDlinklistByPos(dlinklist *head, int pos)
{
	dlinklist *ret_dlinklist = NULL;
	int len = getLengthDlinklist(head);
	if(len < 0 || pos > len - 1|| pos < 0)
	{
		return NULL;
	}
	ret_dlinklist = head->next;//获取最开始的成员地址
	while (pos--)
	{
		ret_dlinklist = ret_dlinklist->next;
	}
	
	return ret_dlinklist;
}

//按值查找节点，返回节点的地址
dlinklist *findDlinkByData(dlinklist *head, data_t data)
{
	if(head == NULL)
	{
		return NULL;
	}
	dlinklist *ret_dlinklist = head->next;//获取最开始的成员地址
	while (ret_dlinklist)
	{
		if(ret_dlinklist->data == data)//找到匹配值
		{
			return ret_dlinklist;
		}
		ret_dlinklist = ret_dlinklist->next;
	}
	
	return NULL;
}

//按位置修改
int changeDlinkByPos(dlinklist *head, int pos, data_t new_data)
{
	dlinklist *p = findDlinklistByPos(head, pos);
	if(p == NULL)
	{
		return -1;
	}
	p->data = new_data;

	return 0;
}

//按值修改
int changeDlinkByData(dlinklist *head, data_t old_data, data_t new_data)
{
	dlinklist *p = findDlinkByData(head , old_data);
	if(p == NULL)
	{
		return -1;
	}
	p->data = new_data;

	return 0;
}

//清空链表
void clearDlinklist(dlinklist *head)
{
	if(head == NULL)
	{
		return ;
	}
	dlinklist *p = head ->next;
	dlinklist *del = NULL;
	while (p)
	{
		del = p;
		p = p->next;
		free(del);
	}
	head->next = NULL;
	return ;
}

//销毁链表
void destoryDlinklist(dlinklist **head)
{
	clearDlinklist(*head);
	*head = NULL;
}

//打印链表节点的data值
void printDlinkist(dlinklist *head)
{
	if(NULL == head)
		return ;
	dlinklist *p = head->next;
	while(p != NULL)
	{
		printf("%d ",p->data);
		p = p->next;
	}

	printf("\n");
	
	return ;
}


int main()
{

	dlinklist *head = createDlinklist();
	if(NULL == head)
	{
		printf("malloc failed\n");
		return -1;
	}

	int len = getLengthDlinklist(head);
	if(-1 == len)
	{
		printf("getLengthDlinklist\n");
		return -1;
	}
	
	printf("len=%d\n",len);

	int i = 0;
	while(i < 10)
	{	
		insertDlinklistByPos(head, i, i+1);
		i++;	
	}
	printDlinkist(head);
	
	insertDlinklistByPos(head, 5, 50);//5号位置添加50
	printDlinkist(head);

	i = 0;
	//删除链表中前五个节点
	while(i < 5)
	{
		deleteDLinklistByPos(head, 0);
		i++;
	}
	printDlinkist(head);

	deleteDLinklistByPos(head, 5);
	printDlinkist(head);

	deleteDlinklistByData(head, 9);
	printDlinkist(head);

	changeDlinkByPos(head, 3, 20);
	printDlinkist(head);

	changeDlinkByData(head, 20, 40);
	printDlinkist(head);

	destoryDlinklist(&head);
	return 0;
}
