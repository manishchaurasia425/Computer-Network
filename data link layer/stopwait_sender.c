#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/types.h>
int main()
{
	 int sockfd,newsockfd,clilen;
        struct sockaddr_in cli_addr,serv_addr;
        int i,j=0;
        long int p;
        char buf[5],f='0';
        printf("Enter the port address:");
        scanf("%ld",&p);
	if((sockfd=socket(AF_INET,SOCK_STREAM,0))<0){
                printf("Error creation in socket!\n");
                exit(0);
        }
        serv_addr.sin_family=AF_INET;
        serv_addr.sin_addr.s_addr=INADDR_ANY;
        serv_addr.sin_port=htons(p);
	if(bind(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr))<0){
		printf("Error in binding \n");
		exit(0);
	}
	listen(sockfd,5);
	clilen=sizeof(cli_addr);
	newsockfd=accept(sockfd,(struct sockaddr *)&cli_addr,&clilen);
	if(newsockfd<0){
		printf("Accept error\n");
		exit(0);
	}
	while(j<5){
                for(i=0;i<5;i++)
                buf[i]='\0';
		buf[0]=f;
                send(newsockfd,buf,5,0);
	       	for(i=0;i<5;i++)
  		buf[i]='\0';
                recv(newsockfd,buf,5,0);
		printf("ACK:%s\n",buf);
                if(f=='0')
                 f='1';
                 else
                  f='0';
	j++;
	}
	close(newsockfd);
        close(sockfd);

}



