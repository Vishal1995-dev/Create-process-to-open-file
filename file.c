#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char* argv[])
{
	int fd=0;
	int ret=0;
	char Buffer[1024];
	
	fd=open(argv[0],O_RDONLY);
	if(fd==-1)
	{
		printf("Unable to open file\n");
		return -1;
	}
	
	while((ret=read(fd,Buffer,sizeof(Buffer)))!=0)
	{
		write(1,Buffer,ret);
	}
	
	close(fd);
	return 0;
}
