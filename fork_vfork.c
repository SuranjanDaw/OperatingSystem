#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>
int g=20;
void main()
{

  pid_t pid;
  int a = 10;
  int b = 15;
  if((pid=fork()) == 0)
  {
    //pid_t parent = getppid();
    printf("CHILD(%d) my parent is = %d\n",getpid(), getppid());
    a++;b++;g++;
    printf("CHILD(%d) a = %d, b = %d,g=%d\n",getpid(), a,b,g );
    sleep(2);
    printf("child bye\n" );
  }else if(pid > 0)
  {
    int c = 14;a--;g--;
    wait(NULL);
    printf("PARENT(%d) my child is =%d\n",getpid(), pid );

    printf("PARENT(%d) a = %d, b = %d,g=%d\n",getpid(), a,b,g );
    printf("parent bye\n" );
    //wait(NULL);
    exit(0);
  }
}
