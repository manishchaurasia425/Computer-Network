#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdio.h>
int main(){
	int msgid;
	key_t key;
	int mykey;
	msgid = msgget((key)|2,IPC_CREAT|777);
	if(msgid<0)
		printf("Message Fialed");
	else
		printf("Message Queue is created with key value: %d",msgid);

}

