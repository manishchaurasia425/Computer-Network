#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	struct msgbht{
		long mytype;
		char mtext[100];
	}send, recv;
	int msg, len;
	msg = msgget((key_t)25, IPC_CREAT|0666);
	if(msg<0){
		perror("Message Failed");
		exit(1);
	}
	strcpy(send.mtext,"I am fine, Thank You!");
	send.mytype = 2;
	len = strlen(send.mtext);
	if(msgrcv(msg,&recv,100,1,0)==-1){
		perror("Message Failed");
		exit(1);
	}
	if(msgsnd(msg,&send,len,0)==-1){
		perror("Message Failed");
		exit(1);
	}
	printf("Message from program 1 is:\n%s\n",recv.mtext);
}



