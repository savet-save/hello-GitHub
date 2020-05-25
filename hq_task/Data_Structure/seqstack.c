#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

typedef int data_t;

//构造顺序栈数据类型
typedef struct stack{
	data_t data[SIZE];
	int top;//记录栈定元素的下标
}seqstack;

//创建空顺序栈
seqstack *createSeqstack(void)
{
	seqstack *stack = (seqstack *)malloc(sizeof(seqstack));
	if(NULL == stack)
		return NULL;

	memset(stack->data, 0, sizeof(stack->data));
	stack->top = -1;//表示空栈

	return stack;
}

//判空
int seqstack_is_empty(seqstack *stack)
{
	if(NULL != stack)
		return ((stack->top == -1)?1:0);
	else
		return -1;
}

//判满
int seqstack_is_full(seqstack *stack)
{
	if(NULL != stack)
		return ((stack->top+1 == SIZE) ?1: 0);
	else
		return -1;
}

//计算栈中元素个数
int getLengthSeqstack(seqstack *stack)
{
	if(NULL == stack)
		return -1;

	return (stack->top+1);
}

//入栈
int pushSeqstack(seqstack *stack, data_t data)
{
	if(NULL == stack)
		return -1;
	if(seqstack_is_full(stack))//判满
		return -1;
		
	stack->data[stack->top+1] = data;//将data添加到top+1位置
	stack->top++;//栈定元素下标自增

	return 0;
}

//出栈
data_t popSeqstack(seqstack *stack)
{
	if(seqstack_is_empty(stack))
		return -1;
	data_t data = stack->data[stack->top];//将栈顶元素值保存在data变量中
	stack->top--;//栈顶下标自减

	return data;

}

//打印栈中各个元素
void printSeqstack(seqstack *stack)
{
	if(NULL == stack)
		return;
	int i = 0;
	for(i=stack->top;i>=0;i--)
		printf("%d ",stack->data[i]);
	printf("\n");

	return ;
}

//清空栈
void clearSeqstack(seqstack *stack)
{
	if(NULL == stack)
		return ;

	stack->top = -1;
	
	return ;
	
}

//销毁栈
void destorySeqstack(seqstack **stack)
{
	free(*stack);
	*stack = NULL;
	
	return ;

}

int main()
{
	seqstack *stack = createSeqstack();
	if(NULL == stack)
	{
		printf("malloc failed\n");
		return -1;
	}
	
	int i = 0;
	while(i < 10)
	{
		pushSeqstack(stack, i+1);
		i++;
	}

	printSeqstack(stack);

	int ret = pushSeqstack(stack, 11);
	if(-1 == ret)
	{
		printf("stack is full\n");
		return -1;
	}
	printSeqstack(stack);

	i = 0;
	data_t data;
	while(i < 5)
	{
		data = popSeqstack(stack);
		printf("%d ",data);
		i++;
	}
	printf("\n");
	printSeqstack(stack);
	
	return 0;
}
