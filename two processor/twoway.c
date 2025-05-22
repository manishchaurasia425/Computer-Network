#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(){
	int p1[2],p2[2],n,pid;
	char buf1[25],buf2[25];
	pipe(1);
	pipe(2);
	printf("\n readfds=%d%d\n",p1[0],p2[0]);
	printf("\n writefds=%d%d\n",p1[0],p2[0]);
	pid=fork();
	if(pid==0){
		close(p1[0]);
		printf("Child process sending data\n");
		write(p1[1],"where is gce",25);
		close(p2[1]);
		read(p2[0],buf1,25);
		printf("reply from parent :%s\n",buf1);
	}else{
		close(p1[1]);
		printf("Parent process reciving data\n");
		n=read(p1[0],buf2,sizeof(buf2));
		printf("\nData recive from child through pipe:%s\n",buf2);
		sleep(3);
		close(p2[0]);
		write(p2[1],"in haldia ",25);
		printf("\nreply send\n");
	}
}


