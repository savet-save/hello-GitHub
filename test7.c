#include <stdio.h>
#include <stdlib.h>
//测试变量和程序在内存上存放的位置

int a=0;
static int a1 = 0;

void test(int arg1, int arg2);

int main(int argc, char const *argv[])
{
	test(1, 2);
	int b = 0;
	int b1 = 0;
	const int cnt = 1;
	int *p = (int *)malloc(sizeof(int));
	char *p1 = "abc";
	
	printf("a:%p a1:%p \n", &a, &a1);
	printf("b:%p b1:%p cnt:%p\n", &b, &b1, &cnt);
	printf("p:%p p1:%p\n", p, p1);
	printf("&p:%p &p1:%p\n", &p, &p1);
	printf("main:%p test:%p\n", main, test);
	free(p);
	return 0;
}

void test(int arg1, int arg2)
{
	int i;
	printf("arg1:%p arg2:%p i:%p\n", &arg1, &arg2, &i);
	
}
