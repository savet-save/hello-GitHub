#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 100

typedef int data_t;

//封装顺序表
typedef struct seqlist{
	data_t data[SIZE];//顺序表
	int last;//记录顺序表中最后一个元素的下标
}SeqList;

//创建空顺序表
SeqList * createSeqlist(void)
{
	 SeqList* seq = (SeqList*)malloc(sizeof(SeqList));//在堆区给结构体开辟空间
	if(NULL == seq)//出错处理
		return NULL;

	memset(seq->data,0,sizeof(seq->data));//给data空间清零,  bzero()可以内存清零
	
	//bzero(seq->data, sizeof(seq->data));
	seq->last = -1;//表示顺序表为空

	return seq;//返回顺序表的首地址
}

//顺序表判满
int seqlist_is_full(SeqList *seq)
{
	if(NULL != seq)
		return((seq->last == SIZE-1) ? 1 : 0);
	else
		return -1;
}

//顺序表判空
int seqlist_is_empty(SeqList *seq)
{
	if(NULL != seq)
		return ((seq->last == -1) ? 1 : 0);
	else
		return -1;
}

//求顺序表长度
int getLengthSeqlist(SeqList *seq)
{
	if(NULL != seq)
		return (seq->last+1);
	else
		return -1;
}

/*******************************************************
功能：按位置插入元素
参数：
	seq:顺序表的首地址
	pos:指定添加的位置
	data:指定添加的数据值
返回值：
	成功：0
	失败：-1
*********************************************************/
int insertSeqlistByPos(SeqList *seq, int pos, data_t data)
{

	if(seqlist_is_full(seq))//判满
		return -1;

	if(pos < 0 || pos > seq->last+1)//判断位置的合法性
		return -1;

	int i = 0;
	for(i=seq->last;i>=pos;i--)//腾出pos位置
		seq->data[i+1] = seq->data[i];//将pos位置及后边所有元素的值向后移动一个位置
	seq->data[pos] = data;//在pos位置添加data
	
	seq->last++;//最后一个元素下标自增
	
	return 0;
}


/***********************************************************
功能：删除顺序表中pos位置处的值
参数：
	seq:顺序表的首地址
	pos:指定要删除元素的位置
返回值：
	成功：0
	失败：-1
***********************************************************/
int deleteSeqlistByPos(SeqList *seq, int pos)
{
	if(seqlist_is_empty(seq))//判空
		return -1;
	int len = getLengthSeqlist(seq);//获取顺序表中元素个数

	if(pos < 0 || pos > len-1)//判断位置的合法性
		return -1;
	
	int i = 0;

#if 0
	for(i=pos;i<seq->last;i++)
		seq->data[i] = seq->data[i+1];
#else
	for(i=pos+1;i<=seq->last;i++)//将pos后所有元素依次向前移动一个位置
		seq->data[i-1] = seq->data[i];
#endif
	seq->last--;//元素减1

	return 0;
}

//按值查找，返回查找到的值对应的位置
int findSeqlistByData(SeqList *seq, data_t data);
//按值删除
int deleteSeqlistByData(SeqList *seq, data_t data)
{
	int pos = findSeqlistByData(seq, data);
	if(pos == -1)
	{
		return -1;
	}

	return deleteSeqlistByPos(seq, pos);
}

//按值查找，返回查找到的值对应的位置
//查找到返回位置
//未查找到返回-1
int findSeqlistByData(SeqList *seq, data_t data)
{
	int pos = -1;
	int i;
	if(seq == NULL)//错误的参数
	{
		return -1;
	}
	//查找第一个匹配值
	for(i = 0;i <= seq->last; i++)
	{
		if(seq->data[i] == data)
		{
			pos = i;
			break;
		}
	}

	return pos;
}

//按值修改
int changeSeqlistByData(SeqList *seq, data_t old_data, data_t new_data)
{
	int pos;
	if(seq == NULL)//错误的返回
	{
		return -1;
	}
	pos = findSeqlistByData(seq, old_data);
	if(pos == -1)//没有找到
	{
		return -1;
	}
	//找到了
	seq->data[pos] = new_data;
	return 0;
}



//打印顺序表中的各个元素
void printSeqlist(SeqList *seq)
{
	
	int len = getLengthSeqlist(seq);//求顺序表中元素的个数
	int i = 0;
	for(i = 0;i < len;i++)
		printf("%d ",seq->data[i]);

	printf("\n");
}


int main()
{
	SeqList * seq = createSeqlist();//创建顺序表
	if(NULL == seq)
	{
		printf("malloc failed\n");
		return -1;
	}

	int ret = seqlist_is_empty(seq);
	printf("ret=%d\n",ret);


	int i = 0;
	while(i < 10)//给顺序表中添加元素
	{
		ret = insertSeqlistByPos(seq, i, i);
		i++;
	}

	printSeqlist(seq);//打印顺序表中各个元素的值
		
	ret = insertSeqlistByPos(seq, 5, 50);//在5号位置添加50
	printSeqlist(seq);//打印顺序表中各个元素的值
	
	ret = insertSeqlistByPos(seq, 0, 100);//在0号位置添加100
	if(-1 == ret)
	{
		printf("insert error\n");
		return -1;
	}
	printSeqlist(seq);//打印顺序表中各个元素的值


	i = 0;
	while(i < 5)//删除顺序表中的前5个元素
	{
		ret = deleteSeqlistByPos(seq, 0);
		i++;
	}
	printSeqlist(seq);//打印顺序表中各个元素的值
	changeSeqlistByData(seq, 6, 52);//按值修改为指定值
	printSeqlist(seq);
	deleteSeqlistByData(seq, 50);//按值删除指定值
	printSeqlist(seq);
	return 0;
}
