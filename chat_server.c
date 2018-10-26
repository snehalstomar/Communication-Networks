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

	struct sockaddr_in s_address, c_address;
	s_address.sin_family = AF_INET;
	s_address.sin_port = htons(10200);
	s_address.sin_addr.s_addr = inet_addr("127.0.0.1");

	bind(sockid, (struct sockaddr*)&s_address, sizeof(s_address));
	listen(sockid, 5);

	length = sizeof(c_address);
	new_sockid = accept(sockid, (struct sockaddr *)&c_address, &length);

	while(1)
	{
		result = recv(sockid, buf, 256, 0);

		printf("CLIENT: %s", buf);	
		printf("Type Here: ");
        fgets(buf,100,stdin);

        result = send(new_sockid, buf, 256, 0);


	}
	//close(c_address);	
	exit(0);


	return 0;
}

