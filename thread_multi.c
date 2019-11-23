#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<sys/types.h>
void * foo(void* arg)
{
  int x = *(int*)arg;
  printf("Welcome from thread %d, %ld\n", x, pthread_self());

  pthread_exit("BYE");
}
int main()
{
  int i = 0;
  int y = 20;
  void * arg;
  pthread_t p[5];
  for(int i = 0; i< 5 ; i++)
  {
    int ret = pthread_create(&p[i], NULL, foo, (void*)&y);
    if(ret == 0)
    {
      printf("Thread %d SUCCESSFULLY CREATED\n", i);
    }
  }
  for(int i = 0; i< 5 ; i++)
  {
    int ret = pthread_join(p[i], &arg);
    if(ret == 0)
    {
      printf("Thread %d SUCCESSFULLY JOINED::%s\n", i,(char*)arg);
    }
  }
}
