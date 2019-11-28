#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<stdlib.h>

void func(int x)
{

  signal(SIGINT,SIG_DFL);
  printf("SIGINT recieved= %d\n",x );

}
int main()
{
  pid_t pid;
  signal(SIGINT,func);
  system("who");
  sleep(2);
  while(1){}
  return 0;
}
