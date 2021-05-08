#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>	//inet_addr
#include <string.h>

int main(int argc, char*argv[])
{
	int socket_desc;
	struct sockaddr_in server;
	char*message,server_reply[6000];

	//Create socket
	socket_desc=socket(AF_INET,SOCK_STREAM,0);
	if(socket_desc==-1)
	{
		printf("Nobody likes me");
	}

	server.sin_addr.s_addr=inet_addr("192.168.56.102");	//Enter ip addr of Server VM
	server.sin_family=AF_INET;
	server.sin_port=htons(22);

	//Connect to remote server
	if(connect(socket_desc,(struct sockaddr*)&server,sizeof(server))<0)
	{
	puts("We can't be friends");
	return 1;
	}
	puts("Yeah sure! Let's be friend ;)\n");


	//Send some data
	message="Can we meet?";
	if(send(socket_desc, message, strlen(message),0)<0)
	{
	puts("We can't be friends");
	return 1;
	}

	puts("My pleasure ;)\n");

	//Receive a reply from the server
	if(recv(socket_desc,server_reply,2000,0)<0)
	{
	puts("I'm sorry, we can't meet");
	}
	puts("Let's hangout together!\n");
	puts(server_reply);

	return 0;
}
