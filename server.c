#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

void main(){
	struct sockaddr_in serveradd , clientadd;
	int size_c = sizeof(serveradd);
	int l_fd = socket(AF_INET,SOCK_STREAM,0);
	//intialise
	serveradd.sin_family = AF_INET;
	serveradd.sin_port = htons(2022);	
	serveradd.sin_addr.s_addr = inet_addr("127.0.0.1");
	//binding
	bind(l_fd,(struct sockaddr *)&serveradd , sizeof(serveradd));
	listen(l_fd,10);
	char buf[100];
	while(1){
		int d_fd = accept(l_fd,(struct sockaddr *)&clientadd , &size_c);
		for(int i = 0;i < 2;i++){
			recv(d_fd,buf,5,0);
			write(1,buf,5);
			send(d_fd, buf, 5,0);
			memset(buf,0,100);
		}
	}		
}
