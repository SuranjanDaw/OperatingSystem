#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<sys/types.h>

void* odd(void* arg)
{
  
  int i = 0;
  int *n =(int*)arg;
  for(i = 0; i< *n; i++)
  {
    if(i %2 != 0)
    {
      printf("Odd =%d, TID= %ld\n",i,pthread_self() );
    }
  }
  pthread_exit("DONE");
}
void * even(void* arg)
{
  int i = 0;
  int *n =(int*)arg;
  for(i = 0; i< *n; i++)
  {
    if(i %2 == 0)
    {
      printf("Even =%d, TID= %ld\n",i,pthread_self() );
    }
  }
  pthread_exit("DONE");
}
int main()
{
  int n = 20;
  void *arg1, *arg2;
  pthread_t t1, t2;
  pthread_create(&t1, NULL, odd, (char*)&n);
  pthread_create(&t2, NULL, even, (char*)&n);

  pthread_join(t1, &arg1);
  pthread_join(t2, &arg2);

  printf("ARG1= %s, ARG2= %s\n",(char*)arg1,(char*)arg2 );
}
