#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
pthread_t philo[5];
pthread_mutex_t chop[5];

void *fun(int n)
	{
	printf("\nphiloshper %d is hungry",n+1);
	pthread_mutex_lock(&chop[n]);
	pthread_mutex_lock(&chop[(n+1)%5]);
    printf("\nphiloshper %d is eating",n+1);
    sleep(3);
    printf("\nphiloshper %d is thinking",n+1);
	pthread_mutex_unlock(&chop[n]);
	pthread_mutex_unlock(&chop[(n+1)%5]);
	}
void main()
	{
	int i;
	for(i=0;i<5;i++)
		pthread_mutex_init(&chop[i],NULL);
	for(i=0;i<5;i++)
		 printf("\nphiloshper %d is thinking",i+1);
	for(i=0;i<5;i++)
		pthread_create(&philo[i],NULL,(void *)fun,(void *)i);
	for(i=0;i<5;i++)
		pthread_join(philo[i],NULL);
	for(i=0;i<5;i++)
		pthread_mutex_destroy(&chop[i]);

	}