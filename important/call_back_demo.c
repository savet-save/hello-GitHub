#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int sum(int num1, int num2, int (*call_back)(void *arg, int times), void *arg);
int call_back(void *arg, int times);

int main(int argc, char const *argv[])
{
	int arg = 5;
	sum(1, 2, call_back, &arg);
	return 0;
}

int sum(int num1, int num2, int (*call_back)(void *arg, int times), void *arg)//公共接口
{
	int t = num1 + num2;
	call_back(arg, t);
	return 0;
}

int call_back(void *arg, int times)//自行实现
{
	int *e = (int *)arg;
	while (times--)
	{
		(*e)++;
		printf("%d", *e);
	}
	
	return 0;
}