#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>
#define MSG 16
void main()
	{
	char ms[MSG];
	char sen[MSG];
	scanf("%s",sen);
	int p[2],i,pi;
	pi=pipe(p);

	if(fork()==0)
		{
		write(p[1],sen,strlen(sen)+1);
		}
	else
		{
		wait(NULL);
		read(p[0],ms,MSG);
		printf("%s",ms);
		}
	}