#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>
int call(int i,int j)
	{
	int pid=0;
	if(j==0)
		{
		return 0;
		}
	pid=fork();
	if(pid==0)
		{
		printf("\niam level %d | pid : %d|ppid: %d",i-j,getpid(),getppid());
		call(i,i-1);
		exit(0);
		}
	else{
		wait(NULL);
		}
	exit(0);
	}
	
void main()
	{
	int n;
	scanf("%d",&n);
	printf("iam level 0 | pid : %d\n",getpid());
	call(n,n-1);
	}