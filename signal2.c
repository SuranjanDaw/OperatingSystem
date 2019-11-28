#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<stdlib.h>
pid_t kv;
pid_t pid;
void func(int x)
{
  int status=0;
  printf("Caught signal =%d\n", x);
  /*kv = kill(pid,SIGKILL);
  if(kv)
  {
    printf("Cannot kill %d\n",pid );
    waitpid(pid,&status,0);
  }else{
    printf("Process killed\n");
  }*/

}
int main()
{
  pid=getpid();
  signal(SIGINT,func);
  system("who");
  sleep(2);
  while(1){
    sleep(2);
    printf("PID(%d)\n",getpid() );
  }
  return 0;
}
