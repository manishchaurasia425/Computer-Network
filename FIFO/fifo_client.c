
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
int main(){
	int wrfd, rdfd, n;
	char buff[50], line[50];
	wrfd=open("np1",O_WRONLY);
	rdfd=open("np2",O_RDONLY);
	printf("Enter the line of text:");
	gets(line);
	write(wrfd,line,strlen(line));
	n=read(rdfd,buff,50);
	buff[n]='\0';
	printf("Full Duplex client: read from the pipe:%s\n",buff);
}

