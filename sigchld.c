#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>

void func(int x)
{
  printf("SIGCHLD recieved= %d\n",x );
}
int main()
{
  pid_t pid;
  signal(SIGCHLD,func);
  if((pid=fork())==0)
  {
     printf("CHILD(%d) my parent is %d\n",getpid(),getppid() );
     sleep(2);
  }else if(pid > 0)
  {
    printf("PARENT(%d) my CHILD is %d\n",getpid(),pid );
    wait(NULL);
  }
}
