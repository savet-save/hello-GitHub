#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef int data_t;
typedef struct node{//构建链表节点
	data_t key;
	struct node *next;
}linklist; 


//哈希表的构建
int insertHash(linklist *renode[], int size, int *a, int len)
{
	if(NULL == renode || a == NULL)
		return -1;
	if(len < 0 || size < 0)
		return 0;

	int i,temp;
	for(i=0;i<len;i++)
	{
		temp = a[i];
		
		//创建新节点，将key值赋给新节点的data
		linklist *new = (linklist *)malloc(sizeof(linklist));
		if(new == NULL)
			return -1;
		new->key = temp;
		new->next = NULL;


		int pos = temp % len;//确认a[i]在renode中的位置
		if(renode[pos] == NULL)//说明pos位置无节点
			renode[pos] = new;
		else
		{
			new->next = renode[pos];
			renode[pos] = new;
		}

	}

	return 0;
}

//hash的查找 
linklist *hashSearch(linklist *renode[], int size, int key)
{
	if(renode == NULL || size < 0)
		return NULL;
	//由key得到key在renode中的位置
	int pos = key % size;
	if(renode[pos] == NULL)
		return NULL;
	else
	{
		linklist *p = renode[pos];
		while(p != NULL)//循环遍历pos位置处的链表
		{
			if(p->key == key)
				return p;
			else
				p = p->next;
		}
		return NULL;
	}

}

//hash表的打印
void printHash(linklist **renode, int size)
{
	if(renode == NULL || size < 0)
		return;
	int i = 0;
	linklist *p = NULL;
	for(i=0;i<size;i++)
	{
		if(renode[i] != NULL)
		{	
			p = renode[i];
			printf("i=%d ",i);
			while(p != NULL)
			{
				printf("%d ",p->key);
				p = p->next;
			}
			printf("\n");
		}
		
	}
}

int main()
{
	int a[13] = {23,34,14,38,46,16,68,15,7,31,26};//key值的集合
	int len = sizeof(a) / sizeof(a[0]);

	linklist *renode[13] = {NULL};//构建指针数组，用来保存链表节点的地址
	int size = sizeof(renode) / sizeof(renode[0]);

	int ret = insertHash(renode, size, a, len);
	printHash(renode, size);

	linklist *p = hashSearch(renode, size, 68);
	if(p == NULL)
	{
		printf("No find data\n");
		return -1;
	}
	printf("p->key=%d\n",p->key);



	return 0;
}
