#include <string.h>
#include <stdio.h>
#include <windows.h>

struct name2{
	char str;
	int num;
	short x;
};

int main(int argc, const char *argv[])
{
	char szstr[10];
	strcpy(szstr,"0123456789");
	printf("%s", szstr);

   	return(0);
}