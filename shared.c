#include<sys/ipc.h> 
#include<sys/shm.h> 
#include<stdio.h> 
  
int main() 
{ 
	if (fork() == 0) 
		{
		printf("i am parent!\n"); 
		 key_t key = ftok("shmfile",65); 
  
    // shmget returns an identifier in shmid 
    int shmid = shmget(key,1024,0666|IPC_CREAT); 
  
    // shmat to attach to shared memory 
    char *str = (char*) shmat(shmid,(void*)0,0); 
  
    printf("\nWrite Data : "); 
    gets(str); 
  
    printf("\nData written in memory: %s\n",str); 
      
    //detach from shared memory  
    shmdt(str); 
		
    	}
    else
    	{
       wait(NULL);
        printf("i am parent!\n"); 
   	    key_t key = ftok("shmfile",65); 
    	int shmid = shmget(key,1024,0666|IPC_CREAT); 
    	char *str = (char*) shmat(shmid,(void*)0,0); 
    	printf("\nData read from memory: %s\n",str);
    	shmdt(str); 
	    shmctl(shmid,IPC_RMID,NULL); 
    	}
     
    return 0; 
} 