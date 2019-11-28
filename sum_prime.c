#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<sys/types.h>

int isPrime(int x){
  int i = 0;
  int cnt = 0;
  for(i = 2 ; i<= x/2; i++)
  {
    if(x % i==0)
    {
      cnt++;
    }
  }
  if(cnt == 0)
  {
    return 1;
  }
  return 0;
}


void* sum(void* arg)
{
  int sum = 0;
  int i = 0;
  int *n =(int*)arg;
  for(i = 0; i< *n; i++)
  {
    sum+=i;
  }
  printf("sum =%d, TID= %ld\n",sum,pthread_self() );
  pthread_exit("DONE");
}
void * prime(void* arg)
{
  int i = 0;
  int *n =(int*)arg;
  for(i = 0 ;i< *n; i++)
  {
    if(isPrime(i)==1)
    {
      printf("Prime = %d, %ld\n",i,pthread_self() );
    }
  }
  pthread_exit("DONE");
}
int main()
{
  int n = 20;
  void *arg1, *arg2;
  pthread_t t1, t2;
  pthread_create(&t1, NULL, prime, (void*)&n);
  pthread_create(&t2, NULL, sum, (void*)&n);

  pthread_join(t1, &arg1);
  pthread_join(t2, &arg2);

  printf("ARG1= %s, ARG2= %s\n",(char*)arg1,(char*)arg2 );
}
