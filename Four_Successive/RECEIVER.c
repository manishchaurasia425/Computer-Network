#include<stdlib.h>
#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>
int main(){
        struct msggbht{
                long mtype;
                char mtext[100];
        }recv;
        int i;
        int qid=msgget((key_t)25,IPC_CREAT|0666);
        if(qid<0){
                perror("Message is failed");
                exit(1);
        }

	for(i=1;i<=4;i++){
		if(msgrcv(qid,&recv,100,0,0)==-1)
		{
			printf("msg %d failed",i);
		}
		printf("%s",recv.mtext);
	}
}
