#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main()
{
  pid_t p = fork();
  if(p == 0)
  {
    printf("CHILD(%d) my parent is = %d\n",getpid(),getppid() );
    system("gcc back.c -o bb; ./bb");
  }else if(p > 0)
  {
    printf("PARENT(%d) my child is= %d\n", getpid(), p);
    wait(NULL);
  }
}
