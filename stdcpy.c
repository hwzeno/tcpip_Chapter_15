/*********************************
    > File Name: stdcpy.c
    > Author: Zeno
    > Mail:340562424@qq.com 
    > Created Time: 2015年09月26日 星期六 08时31分25秒
 ********************************/

#include<stdio.h>
#define BUF_SIZE 3

int main(int argc, char *argv[])
{
		FILE *fp1;//保存在fp1中的是FILE结构体指针
		FILE *fp2;
		char buf[BUF_SIZE];

		fp1 = fopen("randomNum.txt", "r");
		fp2 = fopen("cpy.txt", "w");

		while(fgets(buf, BUF_SIZE, fp1) != NULL)
			fputs(buf, fp2);

		fclose(fp1);
		fclose(fp2);
		return 0;
}
