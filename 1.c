#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
void main(){
    int n;
    printf("\n Enter value of n:");
    
    scanf("%d",&n);
    int primes[n];
    int non_primes[n];
    int sp=0,np=0;
    for(int i=2;i<=n;i++){
        int f=0;
        for(int j=2;j<=i/2;j++){
                if(i%j==0){
                        f=1;
                        break;
                 }
          }
          if(f==1)
                non_primes[np++]=i;
          else
                primes[sp++]=i;
    }
    
    int pid=fork();
    if(pid<0){
            fprintf(stderr,"fork failed");
           }
  else if (pid==0){
            int sum=0;
            for(int i=0;i<sp;i++)
                    sum+=primes[i];
                    
            printf("\n sum of primes %d",sum);
                    
   }
   else if(pid>0){
 
              int sum2=0;
            for(int i=0;i<np;i++)
                    sum2+=non_primes[i];
                    
              printf("\n sum of non primes %d",sum2);
   }
   else;
    /*  for(int i=0;i<np;i++){
            printf("%d",non_primes[i]);
           }*/
 }