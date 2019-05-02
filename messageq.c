#include<stdio.h>
#include<unistd.h>
#include <stdlib.h>
#include<sys/wait.h>
#include<sys/msg.h>
#include<sys/ipc.h>
struct message
	{
	long type;
	char text[100];
};
void main()
	{

	if(fork()>0)
		{
		wait(NULL);
		struct message msg2;
		key_t key;
		int msgid;
		key=ftok("profile", 65 );
		msgid=msgget(key, 0666 |IPC_CREAT);
		msgrcv(msgid,&msg2,sizeof(msg2),1,0);
		printf("\nMessage :%s",msg2.text);
		}
	else
		{
		
		struct message msg1;
		gets(msg1.text);
		msg1.type=1;
		key_t key;
		int msgid;
		key=ftok("profile", 65 );
		msgid=msgget(key, 0666 |IPC_CREAT);
		msgsnd(msgid,&msg1,sizeof(msg1),0);
		printf("Message sucessfully sent");
		}

	}
