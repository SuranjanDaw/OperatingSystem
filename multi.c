#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main()
{
  pid_t p = fork();
  pid_t p2,p3;
  if(p == 0)
  {
    printf("CHILD(%d) my parent is = %d\n",getpid(),getppid() );
    sleep(2);
    system("who");

  }else if(p > 0)
  {
    printf("PARENT(%d) my child is= %d\n", getpid(), p);
    if((p2 = fork())==0)
    {
      printf("CHILD2(%d) my parent is = %d\n",getpid(), getppid() );
      sleep(2);
      execlp("ls","ls","-al",(char*)NULL);
      sleep(2);
    }else if( p2 > 0)
    {
      printf("PARENT2(%d) my child is - %d\n",getpid(),p2 );
      if((p3 = fork())==0)
      {
        printf("CHILD3(%d) my parent is = %d\n", getpid(), getppid());
        sleep(2);
        execl("/bin/date","date",(char*)NULL);
        sleep(2);
      }else if(p3 > 0)
      {
        printf("PARENT3(%d) my child is = %d\n", getpid(),p3);
        wait(NULL);
      }
    }
  }
}
