#include<stdio.h>
#include<ctype.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
int main(){
	int wrfd, rdfd,n,d,ret_val, count;
	char buff[50];
	ret_val=mkfifo("np1",0666);
	ret_val=mkfifo("np2",0666);
	rdfd=open("np1",O_RDONLY);
	wrfd=open("np2",O_WRONLY);
	n=read(rdfd,buff,50);
	buff[n]='\0';
	printf("Full Duplex server: read from the pipe:%s\n",buff);
	count=0;
	while(count<0){
		buff[count]=toupper(buff[count]);
		count++;
	}
	write(wrfd,buff,strlen(buff));
}

