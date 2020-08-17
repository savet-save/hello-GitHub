#include <stdio.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "service.h"

#define err_log(log) do{perror(log);return -1;}while(0)

#define PORT 9002

int main(int argc, const char *argv[])
{
	//clear zombie
	signal(SIGCHLD, SIG_IGN);

	//create socket fd
	socket_t sockfd = get_listen_socket(PORT);
	if(sockfd < 0)
	{
		err_log("get_listen_socket");
		return -1;
	}

	int accefd;
	//accept connect from client
	while((accefd = accept(sockfd, NULL, NULL)) > 0)
	{
		if(fork() == 0)
		{
			printf("accept connect from client success! %d\n", accefd);
			close(sockfd);
			//deal with client action
			client_action(accefd);

			exit(0);
		}
		close(accefd);
	}

	if(close(sockfd) < 0)
	{
		err_log("close sockfd");
	}

	return 0;
}
