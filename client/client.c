#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <signal.h>
#include <dirent.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdlib.h>

typedef struct _msg
{
	char type;
	char data[255];

}MMSG;


int do_ls(int socketfd);
int send_jpg(int socketfd);

int main(int argc, const char* argv[])
{

	int socketfd = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in addr;
	if (socketfd < 0)
	{
		fprintf(stderr, "creat socket fault.\n");
		return -1;
	}
	memset(&addr, 0, sizeof(addr));
	addr.sin_addr.s_addr = inet_addr("192.168.101.8");
	addr.sin_port = htons(6800);
	addr.sin_family = AF_INET;

	if (connect(socketfd, (struct sockaddr*) & addr, sizeof(addr)) < 0)
	{
		perror("connect server fault ");
		return -1;
	}

	while (1)
	{
		printf("************************************************************************\n");
		printf("1.send data  2.send jpg  3.up to server file  4.quit\n");
		printf("************************************************************************\n");
		int choose = 0;
		printf("please your choose : ");
		scanf("%d", &choose);
		getchar();
		switch (choose)
		{
		case 1:
			do_ls(socketfd);
			break;
		case 2:
			send_jpg(socketfd);
			break;
		case 3:
			break;
		case 4:
			printf("thanks for your usr.\n--------------------\n");
			exit(0);
			break;
		default:
			printf("Invalid data info\n");
			break;
		}
	}


	return 0;
}

int do_ls(int socketfd)
{
	MMSG msg;
	strcpy(msg.data, "test data!");
	msg.type = 'D';
	if (send(socketfd, (void *)&msg, sizeof(MMSG), 0) < 0)
	{
		fprintf(stderr, "send 'L' fault\n");
		return -1;
	}
	printf("%s send sucess\n", msg.data);
	/*while (1)
	{
		if (recv(socketfd, (char*)&msg, sizeof(MMSG), 0) > 0)
		{
			if (msg.data[0] == '\0')
				break;
			printf("%s  ", msg.data);
		}
	}*/
	printf("\n");
	return 0;
}

int send_jpg(int socketfd)
{
	FILE *jpg_fp;
	int ch = 0;//recive char
	jpg_fp = fopen("test.jpg", "rb");
	if(jpg_fp == NULL)
	{
		fprintf(stderr, "open fail : not have test.jpg\n");
		return -1;
	}
	unsigned int jpg_size = 0;
	fseek(jpg_fp, 0, SEEK_END);
	jpg_size = ftell(jpg_fp);
	printf("size: %d\n", jpg_size);
	rewind(jpg_fp);
	MMSG msg;
	msg.type = 'J';
	memcpy((void *)msg.data, (void *)&jpg_size, sizeof(jpg_size));
	msg.data[sizeof(jpg_size)] = '\0';
	//发送图片大小
	send(socketfd, (void *)&msg, sizeof(msg), 0);
	int i = 0;
	while((ch = fgetc(jpg_fp)) != EOF)
	{
		if(i < sizeof(msg.data))
		{
			msg.data[i] = (unsigned char)ch;
			i++;
			if(i == sizeof(msg.data))
			{
				if(send(socketfd, (char *)&msg, sizeof(MMSG), 0) < 0)
				{
					fprintf(stderr, "send jpg fail\n");
					return -1;
				}
				
				i = 0;
			}
		}				
	}
	for(;i<sizeof(msg.data);i++)
	{
		msg.data[i] = '\0';
	}
	if(send(socketfd, (char *)&msg, sizeof(MMSG), 0) < 0)
	{
		fprintf(stderr, "send jpg fail\n");
		return -1;
	}
	//memcpy(msg.data, "jpg send over", sizeof("jpg send over"));
	strcpy(msg.data, "jpg send over");
	msg.type = 'E';
	if(send(socketfd, (char *)&msg, sizeof(MMSG), 0) < 0)
	{
		fprintf(stderr, "send jpg fail\n");
		return -1;
	}
	printf("send jpg success!\n");
	fclose(jpg_fp);
	return 0;
}
