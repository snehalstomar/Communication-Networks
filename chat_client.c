#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
	int len,result,sockid,n=1, new_sockid, length;
	sockid = socket(AF_INET, SOCK_STREAM, 0);
	char buf[256];

	struct sockaddr_in c_address;
	c_address.sin_family = AF_INET;
	c_address.sin_port = htons(10200);
	c_address.sin_addr.s_addr = inet_addr("127.0.0.1");

	result = connect(sockid, (struct sockaddr *)&c_address, sizeof(c_address));
	
	while(1)
	{
		printf("Hit Enter to receive data from Server::");
		fgets(buf,100,stdin);
		result = send(sockid, buf, 256, 0);
		result = recv(sockid, buf, 256, 0);
		printf("Data Received from Server--> %s", buf);	
	}
	exit(0);
	return 0;
}

