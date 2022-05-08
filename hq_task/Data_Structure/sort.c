#include <stdio.h>

//插入排序
void insertSort(int *p, int len)
{
	if(NULL == p || len <= 0)
		return ;

	int i;//记录p数组中的元素下标
	int j;//记录i元素前边元素的下标
	int temp;//记录要插入的元素值
	for(i=1;i<len;i++)
	{
		temp = p[i];//要插入的元素
		j = i-1;//j记录i位置的前一个位置元素的下标
		while(temp < p[j] && j>=0)//循环比较p[j]和p[i]的大小并找到p[i]的位置
		{
			p[j+1] = p[j];//元素向后偏移
			j--;
		}
		//j+1位置是temp元素的位置
		p[j+1] = temp;

	}

	return ;
}

//快速排序算法
void quickSort(int *p,int len)
{
	if(p == NULL || len <= 0)
 		return ;
	int i = 0;//i记录第一个元素下标
	int j = len-1;//j记录最后一个元素下标
	int temp = p[0];//记录基准值
	
	while(i != j)
	{
		for(;j>i;j--)//循环遍历右边的数据元素
		{
			if(p[j] < temp)
			{
				p[i] = p[j];
				break;
			}

		}
		
		for(;i<j;i++)//循环遍历左边的数据元素
		{
			if(temp < p[i])
			{
				p[j] = p[i];
				break;
			}
	
		}
		p[i] = temp;
		
	}
	
	quickSort(p,i);//左边元素快排
	quickSort(p+i+1,len-i-1);//右边元素快排

}


int main()
{

	int a[] = {50,36,66,79,100,95,12,25,3,36};
	int len = sizeof(a) / sizeof(a[0]);
	int i;

	//insertSort(a,len);//插入排序
	quickSort(a,len);
	for(i=0;i<len;i++)
		printf("%d ",a[i]);
	printf("\n");
	


	return 0;
}
