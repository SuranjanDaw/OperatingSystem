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
    printf("Sleeps for 10s\n" );
    sleep(10);
    if(parent != getppid())
    {
      while(1){
        sleep(2);
        printf("PARENT left\n" );
      }
    }
  }else if(pid > 0)
  {
    printf("PARENT(%d) my child is =%d\n",getpid(), pid );
    printf("sleeps for 2s\n" );
    sleep(2);
    exit(0);
  }
}
