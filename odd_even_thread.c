#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<sys/types.h>

void * odd(void * x)
{
  int i = 0;
  int n = *(int*)x;
  for(i = 0; i<n;i++)
  {
    if(i%2!=0)
    {
      printf("ODD %d\n",i );
    }
  }
  pthread_exit("odd bye");
}

void * even(void * x)
{
  int i = 0;
  int n = *(int*)x;
  for(i = 0; i<n;i++)
  {
    if(i%2==0)
    {
      printf("EVEN %d\n",i );
    }
  }
  pthread_exit("even bye");
}

void main()
{
  pthread_t p1, p2;
  int n = 100;
  void *pp, *pp1;
  int ret1 = pthread_create(&p1,NULL,odd,(void*)&n);
  int ret2 = pthread_create(&p2,NULL,even,(void*)&n);
  if(ret1 == 0)
  {
    printf("Success thread1 \n" );
  }
  if(ret2 == 0)
  {
    printf("Success thread2\n" );
  }

  ret1 = pthread_join(p1,&pp);
  ret2 = pthread_join(p2,&pp1);
  if(ret1 == 0)
  {
    printf("Success thread1 join %s\n",(char*)pp );
  }
  if(ret2 == 0)
  {
    printf("Success thread2 join%s\n",(char*)pp1 );
  }


}
