#include<stdio.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<unistd.h>
#include<pthread.h>
void* bb(void* arg)
{
  printf("THREAD BODY. my id = %ld,  %s\n",pthread_self() , (char*)arg);
}
int main()
{
    pthread_t pp;
    int ret =  pthread_create(&pp,NULL,bb, (void*)"WELCOME" );
    if( ret ==0)
      printf("THREAD CREATED SUCCESSFULLY\n" );
    int ret2= pthread_join(pp, NULL);
    if(ret2 == 0)
    {
      printf("JOIN SUCCESSFULLY\n" );
    }

}
