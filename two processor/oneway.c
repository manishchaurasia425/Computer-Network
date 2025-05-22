#include<stdio.h>
#include<stdlib.h>
int main(){
	int pipefd[12],n,pid;
	char buff[100];
	pipe(pipefd);
	printf("\n readfd=%d",pipefd[0]);
	printf("\nwritefd=%d",pipefd[1]);
	pid=fork();
	if(pid==0){
		close(pipefd[0]);
		printf("\nCHILD PROCESS SENDING DATA\N");
		write(pipefd[1],"Hello World",12);
		}
	else{
		close(pipefd[1]);
		printf("\nPARENT PROCESS RECIEVE DATA");
		n=read(pipefd[0],buff,sizeof(buff));
		printf("\nSize of data: %d",n);
		printf("\n Data recieved from child through pipe: %s",buff);
	}
}
