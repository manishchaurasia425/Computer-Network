#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/types.h>
main(int argc,char *argv[]){
	int sockfd;
	struct sockaddr_in serv_addr;
	int i;
	long int p;
	char buf[5];
	printf("Enter the port address:");
	scanf("%ld",&p);

	if((sockfd=socket(AF_INET,SOCK_STREAM,0))<0){
		printf("Error creation in socket!\n");
		exit(0);
	}
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_addr.s_addr=inet_addr(argv[1]);
	serv_addr.sin_port=htons(p);
	if((connect(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr)))<0){
		printf("unable to connect to server\n");
	       exit(0);
	}
int j=0;
	while(j<5){
		for(i=0;i<5;i++)
			buf[i]='0';
			recv(sockfd,buf,5,0);
			printf("FRAME:%s\n",buf);
			if(buf[0]=='0')
				buf[0]='1';
			else
				buf[0]='0';
			send(sockfd,buf,5,0);
			j++;
		}
	close(sockfd);
	
}
					
