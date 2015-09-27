/*********************************
    > File Name: echo_client.c
    > Author: Zeno
    > Mail:340562424@qq.com 
    > Created Time: 2015年09月26日 星期六 16时21分21秒
 ********************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#define BUF_SIZE 1024
void error_handling(char *message);
int main(int argc, char* argv[])
{
	int sock;
	struct sockaddr_in serv_adr;
	char message[BUF_SIZE];
	int str_len;

	FILE * readfp;
	FILE *writefp;

	if(argc != 3)
	{
		printf("Usage: %s <IP> <port>\n ", argv[0]);
		exit(1);
	}

	sock = socket(PF_INET, SOCK_STREAM, 0);
	if(sock == -1)
		error_handling("socket() error");

	memset(&serv_adr, 0, sizeof(serv_adr));
	serv_adr.sin_family = AF_INET;
	serv_adr.sin_addr.s_addr = inet_addr(argv[1]);//转换ｉｐ
	serv_adr.sin_port = htons(atoi(argv[2]));//转换端口号

	if(connect(sock, (struct sockaddr*)&serv_adr, sizeof(serv_adr)) == -1)
		error_handling("connect() error");	
	else
		puts("Connected .....");
	//添加处
	readfp = fdopen(sock, "r");
	writefp = fdopen(sock, "w");
	while(1)
	{
		fputs("Input message(Q to quit): ", stdout);
		fgets(message, BUF_SIZE, stdin);

		if(!strcmp(message, "q\n") || !strcmp(message, "Q\n"))
			break;

		fputs(message, writefp);
		fflush(writefp);
		fgets(message, BUF_SIZE, readfp);
		printf("Mesage from server : %s \n", message);
	}
	fclose(writefp);
	fclose(readfp);
	return 0;
}
void error_handling(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}

