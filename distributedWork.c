#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main()
{
  pid_t p = fork();
  pid_t p2;
  if(p == 0)
  {
    printf("CHILD(%d) my parent is = %d\n",getpid(),getppid() );
    int i = 0;
    for(i = 1;i <=10; i++)
    {
      printf("CHILD1(%d)= %d\n",getpid(),i );
      //sleep(1);
    }
  }else if(p > 0)
  {
    printf("PARENT(%d) my child is= %d\n", getpid(), p);
    if((p2=fork()) == 0)
    {
      printf("CHILD2(%d) my parent is = %d\n",getpid(),getppid() );
      int i = 0;
      for(i = 1;i <=10; i++)
      {
        printf("CHILD2(%d)= %d\n",getpid(),i );
        //sleep(1);
      }
    }else if(p2 > 0)
    {
      printf("PARENT(%d) my child is= %d\n", getpid(), p2);

      wait(NULL);
      printf("PARENT(%d): GOODBYE\n",getpid() );
    }
    /*wait(NULL);
    printf("PARENT(%d): GOODBYE\n",getpid() );*/
  }
}
