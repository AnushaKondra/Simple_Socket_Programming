#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
void main(){
	struct sockaddr_in serveradd , clientadd;
	int  size_c = sizeof(serveradd);
	char buf[100];
	int s_fd = socket(AF_INET,SOCK_STREAM,0);
	//intialise
	serveradd.sin_family = AF_INET;
	serveradd.sin_port = htons(2022);	
	serveradd.sin_addr.s_addr = inet_addr("127.0.0.1");
	connect(s_fd,(struct sockaddr *)&serveradd , size_c);
	send(s_fd,"Hello",5,0);
	recv(s_fd,buf,5,0);
	write(1,buf,5);		
}
