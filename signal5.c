#include<stdio.h>
#include<signal.h>
#include<sys/types.h>
#include<sys/wait.h>
#include "unistd.h"
#include "stdlib.h"
pid_t a,b;
void sigusr1(int x)
{
  printf("CHILD i woke up\n");
  printf("Signal number from CHILD(%d) = %d\n",a,x );
}
void sigusr2(int x)
{
  printf("PARENT i woke up\n");
  printf("Signal number from PARENT(%d) = %d\n",b,x );
}

void main()
{

  b= getpid();//parent
  signal(SIGUSR1,sigusr1);
  signal(SIGUSR2,sigusr2);
  if((a=fork())==0)
  {
    printf("CHILD(%d) my parent is%d\n",getpid(),getppid() );
    sleep(2);

    kill(b,SIGUSR1);
  }else if(a >0){
    printf("PARENT(%d) my child is %d\n",getpid(),a );
    sleep(2);

    kill(a,SIGUSR2);
  }
}
