#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>
pid_t pid;
pid_t ppid;
void call(int x)
{
  printf("Recieved SIGCHLD child exit normally %d, Parent =%d and child =%d\n",x, ppid, pid );
}
void call1(int x)
{
  printf("CHILD(%d) killed by force by parent(%d)), Signal= %d\n",pid,ppid,x );
  system("ps -ax| grep pts");
  kill(pid,SIGTERM);
}

void main(int argc, char* args[])
{
  int status;
  ppid= getpid();
  signal(SIGCHLD,call);
  signal(SIGINT,call1);
  if((pid=fork())==0)
  {
    pid= getpid();
    printf("CHILD(%d) my parent is %d \n",getpid(),ppid );
    sleep(3);
    printf("child was busy for 3s\n" );
  }else if(pid > 0)
  {
    printf("PARENT(%d) my child is %d\n",ppid,pid );
    int delay = atoi(args[1]);
    sleep(delay);
    kill(pid,SIGINT);
    int ret = wait(&status);
    printf("CHILD terminated with status %d and ret val %d\n",status, ret );
  }
}
