#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/wait.h>
void main()
	{
	if(fork()==0)
		{
		key_t key;
		int shmid;
		key=ftok("shmfile",65);
		shmid=shmget(key,1024, 0666 |IPC_CREAT);
		char *str=(char*) shmat(shmid,(void*)0,0);
		printf("witr data :");
		gets(str);
		shmdt(str);
		}
	else
		{
		wait(NULL);
		key_t key;
		int shmid;
		key=ftok("shmfile",65);
		shmid=shmget(key,1024, 0666 |IPC_CREAT);
		char *str=(char*) shmat(shmid,(void*)0,0);
		printf("\nRECIVED:%s",str);
		shmdt(str);
		shmctl(shmid,IPC_RMID,NULL);
		}
	}