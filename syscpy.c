/*********************************
    > File Name: syscpy.c
    > Author: Zeno
    > Mail:340562424@qq.com 
    > Created Time: 2015年09月26日 星期六 08时40分41秒
 ********************************/

#include<stdio.h>
#include<fcntl.h>
#define BUF_SIZE 3

int main(int argc, char *argv[])
{
	int fd1, fd2; //保存在fd1和fd2中的是文件描述符
	int len;
	char buf[BUF_SIZE];

	fd1 = open("randomNum.txt", O_RDONLY);
	fd2 = open("cpy.txt", O_WRONLY|O_CREAT|O_TRUNC);

	while((len = read(fd1, buf, sizeof(buf))) > 0)
		write(fd2, buf, len);
	close(fd1);
	close(fd2);
	return 0;
}
