#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>		//inet_addr

int main(int argc, char*argv[])
{
	int socket_desc;
	struct sockaddr_in server;

	//Create socket
	socket_desc=socket(AF_INET, SOCK_STREAM,0);
	if(socket_desc==-1)
	{
		printf("Could not create socket");
	}

	//Prepare the socketaddr_in structure
	server.sin_addr.s_addr=inet_addr("192.168.56.102");
	server.sin_family=AF_INET;
	server.sin_port=htons(8888);

	//Connect to remove server
	if(connect(socket_desc, (struct sockaddr*)&server, sizeof(server))<0)
	{
		puts("Connect error");
		return 1;
	}

	puts("Connected");
	return 0;
}
