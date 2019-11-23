#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>
int main()
{
  pid_t pid = fork();
  if(pid == 0)
  {
    pid_t parent = getppid();
    printf("CHILD(%d) my parent is = %d\n",getpid(), getppid());
    printf("child Sleeps for 2s\n" );
    sleep(2);
    exit(0);
  }else if(pid > 0)
  {
    printf("PARENT(%d) my child is =%d\n",getpid(), pid );
    printf("parent sleeps for 10s\n" );
    sleep(10);
    while(1)
    {
      sleep(2);
      printf("I have become zombie\n" );
    }
  }
}
