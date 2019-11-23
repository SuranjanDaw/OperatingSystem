#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main()
{
  pid_t pi,pj;
  pid_t p = fork();
  if(p == 0)
  {
    printf("CHILD(%d) my parent is = %d\n",p,getppid() );
    sleep(2);
    if((pi = fork())==0)
    {
      printf("inner CHILD(%d) my parent is = %d\n",pi,getppid() );
      sleep(4);
    }else if(pi > 0)
    {

        printf("inner PARENT(%d) my child is= %d\n", getpid(), pi);
        sleep(2);
        wait(NULL);
    }
  }else if(p > 0)
  {
    printf("PARENT(%d) my child is= %d\n", getpid(), p);
    sleep(2);
    if((pj = fork())==0)
    {
      printf("inner parent CHILD(%d) my parent is = %d\n",pj,getppid() );
      sleep(4);
    }else if(pj > 0)
    {

        printf("inner parent PARENT(%d) my child is= %d\n", getpid(), pj);
        sleep(2);
        wait(NULL);
    }
  }
}
