#include<stdio.h>
void main()
	{
	int n,i,j,sum=0,sumn=0;
	scanf("%d",&n);
	int pr[n],pn[n],np=0,p=0;
	for(i=2;i<=n;i++)
		{
		int k=0;
		k=0;
		for(j=2;j<i;j++)
			{
			if(i%j==0)
				{
				k=1;
				break;
				}	
			}
		if(k==0)
			{
			pr[p]=i;
			p++;	
			}
		else
			{
			pn[np]=i;
			np++;	
			}
		}
	for(i=0;i<p;i++)
				{
				printf("\n%d",pr[i]);	
				}
	for(i=0;i<np;i++)
				{
			//	printf("\n%d",pn[i]);	
				}
	int pid=fork();
	if(pid==0)
			{
			printf("I sm child");
			for(i=0;i<p;i++)
				{
				sum=sum+pr[i];	
				}
			printf("sum of prime numbers is %d\n",sum);

			}
	else
		{
			wait(NULL);
			printf("I sm parent");
			for(j=0;j<np;j++)
				{
				sumn=sumn+pn[j];	
				}
			printf("sum of prime numbers is %d",sumn);

			}

	}