/*********************************
    > File Name: todes.c
    > Author: Zeno
    > Mail:340562424@qq.com 
    > Created Time: 2015年09月26日 星期六 15时55分03秒
 ********************************/
#include<stdio.h>
#include<fcntl.h>

int main(void)
{
	FILE *fp;
	int fd = open("data.cat", O_WRONLY|O_CREAT|O_TRUNC);
	if(fd == -1)
	{
		fputs("file open error", stdout);
		return -1;
	}

	printf("First file descriptor: %d \n", fd);
	fp = fdopen(fd, "w");
	fputs("TCP/IP SOCKET PROGRAMING \n", fp);
	printf("Second file descriptor : %d \n", fileno(fp));
	fclose(fp);
	return 0;
}
