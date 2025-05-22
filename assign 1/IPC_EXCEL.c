#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdlib.h>
#include<stdio.h>
int main(){
        int msgid;
        key_t key=11;
        int mykey;
        msgid=msgget(key,IPC_CREAT|IPC_EXCL);
        if(msgid<0){
                perror("Message failed");
		exit(1);

	}
        else
        printf("Message queue is created with key value %d ",msgid);
}

