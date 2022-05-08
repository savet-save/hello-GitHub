#include <stdio.h>
#include <stdlib.h>
#include <string.h>
	
//直接插入排序
int insertSort(int *a, int len)
{
	if(a == NULL || len < 0)
		return -1;

	int i,j,temp;
	for(i=1;i<len;i++)
	{
		temp = a[i];
	
		j = i-1;
		while(j >= 0 && a[j] > temp)//循环找到temp的位置
		{
			a[j+1] = a[j];
			j--;
		}
		//j+1位置是要插入元素的位置
		a[j+1] = temp;
		
	}

	return 0;
}

//折半插入排序
int binSort(int *a,int len)
{
	if(NULL == a || len < 0)
		return -1;
	//j:记录插入元素的前一个位置下标
	int i,j;
	int low,high,mid;
	for(i=1;i<len;i++)
	{
		int temp = a[i];
		low = 0;//记录第一个元素的下标
		high = i-1;//记录最后一个元素的下标
		while(low <= high)
		{
			mid = (low+high) / 2;
			if(temp > a[mid])
				low = mid+1;
			else if(temp < a[mid])
				high = mid - 1;
			else
				low = mid + 1;
		}
		//low位置为要插入元素的位置
		j = i-1;
		for(j=i-1;j >= low; j--)
			a[j+1] = a[j];
		a[low] = temp;	

	}
	return 0;
}
//快速排序, 
int quickSort(int *a, int len)
{
	if(a == NULL || len < 0) {
		return -1;
	}
	if(len == 0 || len == 1) { // not need sort
		return 0;
	}

	int temp = a[0];
	int i = 0;
	int j = len-1;
	while(i < j)
	{
		for(j=len-1;j>i;j--)
		{
			if(a[j] < temp)
			{
				a[i] = a[j];
				break;
			}

		}	
		for(i=0;i<j;i++)
		{
			if(a[i] > temp)
			{
				a[j] = a[i];
				break;
			}
		}
	a[i] = temp;
	}

	quickSort(a, i);//左半部分元素
	quickSort(a+i+1,len-i-1);//右半部分元素
	return 0;
}

int main()
{
	int a[] = {50,36,66,76,95,12,25,36,36,35};
	int len = sizeof(a) / sizeof(a[0]);
	
	//insertSort(a, len);	
		
//	binSort(a,len);
	quickSort(a,len);
	int i=0;
	for(i=0;i<len;i++)
		printf("%d ",a[i]);
	printf("\n");

	return 0;
}
