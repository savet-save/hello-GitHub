#include <stdio.h>

int atoi_hex(const char *str);

int main(void)
{
	char *hex = "12345fe";
	int ret = 0;
	ret = atoi_hex(hex);
	printf("%d", ret);
	return 0;
}

int atoi_hex(const char *str)
{
	int ret_int= 0;
	while (*str)
	{
		if(*str>='0' && *str <= '9')
		{
			ret_int = ret_int * 16 + *str - '0';
		}
		else if(*str>= 'a' && *str <= 'f')
		{
			ret_int = ret_int * 16 + *str - 'a' + 10;
		}
		else if(*str>= 'A' && *str <= 'F')
		{
			ret_int = ret_int * 16 + *str - 'A' + 10;
		}
		str++;
	}

	return ret_int;
}