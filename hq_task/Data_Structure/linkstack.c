#include <stdio.h>
#include <stdlib.h>

typedef int data_t;

//构造栈节点
typedef struct node{

	data_t data;//数据域
	struct node *next;
}linkstack;

//创建空栈
linkstack *createLinkstack(void)
{
	linkstack *top = (linkstack *)malloc(sizeof(linkstack));
	if(NULL == top)
		return NULL;
	top->data = -1;
	top->next = NULL;//表示栈为空

	return top;
}

//判空
int linkstack_is_empty(linkstack *top)
{
	if(NULL != top)
		return ((top->next == NULL)?1:0);
	else
		return -1;

}

//计算栈中节点个数
int getLengthLinkstack(linkstack *top)
{
	if(NULL == top)
		return -1;

	int len = 0;
	linkstack *p = top->next;
	while(p != NULL)
	{
		len++;
		p = p->next;
	}
	return len;
}

//入栈(pos=0插入节点)
//返回0:成功
//返回-1:错误
int linkStack_push(linkstack *top, data_t data)
{
	if(NULL == top)
	{
		return -1;
	}

	linkstack *new_linkStack = (linkstack *)malloc(sizeof(linkstack));
	if(NULL == new_linkStack)
	{
		return -1;
	}
	new_linkStack->data = data;
	new_linkStack->next = top->next;
	top->next = new_linkStack;
	return 0;
}


//出栈(删除pos=0节点)
//返回0:成功
//返回-1:错误
int linkStack_pop(linkstack *top, data_t *ret_data)
{
	int ret_error = 0;
	if((ret_error = linkstack_is_empty(top)) != 0)
	{
		return ret_error;
	}

	linkstack *stack_pop = top->next;
	top->next = stack_pop->next;
	if(NULL != ret_data)
	{
		*ret_data = stack_pop->data;
	}
	free(stack_pop);
	stack_pop = NULL;

	return 0;
}

//打印栈中各个节点的值
//返回0:成功
//返回-1:错误
int print_linkStack(linkstack *top)
{
	if(NULL == top)
	{
		return -1;
	}
	linkstack *p = top->next;
	while (p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");

	return 0;
}

//清空栈
//返回0:成功
//返回-1:错误
int clearn_linkStack(linkstack *top)
{
	//while(linkStack_pop(top, NULL) == 0);//第一种方法
	if(top == NULL)
	{
		return -1;
	}
	linkstack *p = top->next;
	linkstack *del = NULL;
	top->next = NULL;
	while(p)
	{
		del = p;
		p = p->next;
		free(del);
	}
	return 0;
}

//销毁栈
void destory_linkStack(linkstack **top)
{
	clearn_linkStack(*top);
	free(*top);
	*top = NULL;
	return ;
}


int main(void)
{
	linkstack *top = createLinkstack();
	int i;
	for(i = 0; i < 10; i++)//压入栈
	{
		if(linkStack_push(top, i) != 0)//如果错误
		{
			return -1;
		}
	}
	print_linkStack(top);

	data_t ret_data = 0;//获取出栈的值
	for(i = 0 ; i< 12; i++)//弹出栈
	{
		linkStack_pop(top, &ret_data);
		printf("%d ", ret_data);
	}
	printf("\n");

	for(i = 0; i < 10; i++)//压入栈
	{
		if(linkStack_push(top, i) != 0)//如果错误
		{
			return -1;
		}
	}
	destory_linkStack(&top);
	return 0;
}







