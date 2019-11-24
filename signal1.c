#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>

void func(int x)
{
  signal(SIGINT,SIG_DFL);
  printf("SIGINT recieved= %d\n",x );
}
int main()
{
  pid_t pid;
  signal(SIGINT,func);
  if((pid=fork())==0)
  {
     printf("CHILD(%d) my parent is %d\n",getpid(),getppid() );
     while(1){
       sleep(2);
       printf("in loop\n" );
     }
     sleep(2);
  }else if(pid > 0)
  {
    printf("PARENT(%d) my CHILD is %d\n",getpid(),pid );
    wait(NULL);
  }
}
