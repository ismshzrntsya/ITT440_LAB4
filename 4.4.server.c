#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>	//inet_addr
#include <string.h>	//strlen
#include <unistd.h>	//write

int main(int argc,char*argv[])
{
	int socket_desc, new_socket, c;
	struct sockaddr_in server, client;
	char*message;

	//Create socket
	socket_desc=socket(AF_INET,SOCK_STREAM,0);
	if(socket_desc==-1)
	{
		printf("Nobody likes me");
	}

	//Prepare the sockaddr_in structure
	server.sin_family=AF_INET;
	server.sin_addr.s_addr=INADDR_ANY;
	server.sin_port=htons(8888);

	//Bind
	if(bind(socket_desc,(struct sockaddr*)&server,sizeof(server))<0)
	{
		puts("We can't be friends");
		return 1;
	}
	puts("Would you like to be my friend?");

	//Listen
	listen(socket_desc,3);

	//Accept and incoming connection
	puts("I await your immediate response...");
	c=sizeof(struct sockaddr_in);

	while((new_socket=accept(socket_desc,(struct sockaddr*)&client,(socklen_t*)&c)))
	{
	puts("Thank you!");

	//Reply to the client
	message = "How wonderful to meet you! ;)\n";
	write(new_socket,message,strlen(message));
	}

	if(new_socket<0)
	{
		perror("We can't be friends, sorry :(");
		return 1;
	}
	return 0;
}
