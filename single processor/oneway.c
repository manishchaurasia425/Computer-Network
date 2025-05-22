#include<stdio.h>
#include<stdlib.h>
int main(){
	int pipefd[2],n;
	char buff[100];
	pipe(pipefd);
	printf("\nreadfd=%d",pipefd[0]);
	printf("\nwritefd=%d",pipefd[1]);
	write(pipefd[1],"Hello World",12);
	n=read(pipefd[0],buff,sizeof(buff));
	printf("\n Size of data: %d",n);
	printf("\n Data from pipe: %s", buff);
}
