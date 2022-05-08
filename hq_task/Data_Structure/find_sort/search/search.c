#include <stdio.h>
#include <string.h>
#include <stdlib.h>
	
//顺序查找
int seqSearch(int *a, int len, int key)
{
	if(NULL == a || len < 0)
		return -1;
	int i = 0;
	for(i=0;i<len;i++)
	{
		if(a[i] == key)
			return i;//返回值为key的元素的下标
	}

	return -1;
}
//折半查找 只能用于事先排好序的数据
int binSearch(int *a, int len, int key)
{
	if(NULL == a || len < 0)
		return -1;
	//low:记录第一个元素的下标
	//high:记录最后一个元素的下标
	//mid:中间位置元素的下标
	int low,high,mid;
	low = 0;
	high = len-1;

	while(low < high)
	{
		mid = (low+high) / 2;//得到中间位置元素的下标
		//比较mid位置处的值与key的大小关系
		if(a[mid] > key)//说明key如果存在，则在mid的左边，移动high变量
			high = mid-1;
		else if(a[mid] < key)//说明key如果存在，则在mid右边，移动low变量
			low = mid+1;
		else//mid处的值等于key
			return mid;
	}
	return -1;

}


int main()
{
	int a[10] = {1,2,3,4,5,6,7,8,9,10};
	int len = sizeof(a) / sizeof(a[0]);
	
	int key = 5;
//	int pos = seqSearch(&a[0], len, key);
	int pos = binSearch(a, len, key);
	if(-1 == pos)
	{
		printf("No find data\n");
		return -1;
	}
	printf("pos=%d %d\n",pos, a[pos]);


	return 0;
}
