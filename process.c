#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc,char*argv[])
{
	int ret=0;
	int pid=0,status=0;
	ret=fork();
	if(ret==0) //Child is running
	{
		execl("./a.out",argv[1],NULL);
	}
	else		//Parent is running
	{
		printf("Parent process pid : %d\n",getpid());
		pid=wait(&status);
		printf("Terminating parent\n");
	}
	return 0;
}
