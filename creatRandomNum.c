/*********************************
    > File Name: creatRandomNum.c
    > Author: Zeno
    > Mail:340562424@qq.com 
    > Created Time: 2015年09月26日 星期六 08时49分09秒
 ********************************/

#include<stdio.h>
#include<time.h>
#include<stdlib.h>//random()
//#define LEN 5
//int arr[LEN];
int main(void)
{
	int i, temp;
	FILE *fp;
	srand(time(NULL));
	fp = fopen("randomNum.txt", "w");
	if(fp == NULL)
	{
		perror("fopen");
		exit(1);
	}
	for(i = 0; i < 8000000; i++)
	{
		temp = rand()%1000000;
		fprintf(fp, "%d\t", temp);
		if((i+1)%10 == 0)
			fprintf(fp, "%c", '\n');
			
	}
	fclose(fp);
	return 0;
}
