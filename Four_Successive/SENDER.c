#include<stdlib.h>
#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>
int main(){
	struct msgget{
		long mtype;
		char mtext[100];
	}send,recv;
	int msg,len;
	msg=msgget((key_t)25,IPC_CREAT|0666);
	if(msg<0){
		perror("Message is failed");
		exit(1);
	}
	strcpy(send.mtext,"Hello how are you?");
	send.mtype=1;
	len=strlen(send.mtext);
	if(msgsnd(msg,&send,len,0)==-1){
		perror("Message failed");
		exit(1);
	}
	strcpy(send.mtext,"\nmsg 2:Where are you?");
        send.mtype=2;
        len=strlen(send.mtext);
        if(msgsnd(msg,&send,len,0)==-1){
                perror("Message failed");
                exit(1);
        }
	strcpy(send.mtext,"\nmsg 3:what are you doing?");
        send.mtype=3;
        len=strlen(send.mtext);
        if(msgsnd(msg,&send,len,0)==-1){
                perror("Message failed");
                exit(1);
        }
	strcpy(send.mtext,"\nmsg 4:why are you here now?");
        send.mtype=4;
        len=strlen(send.mtext);
        if(msgsnd(msg,&send,len,0)==-1){
                perror("Message failed");
                exit(1);
        }
}



