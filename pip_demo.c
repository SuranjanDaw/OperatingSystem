#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#define MAXSIZE 50
void main()
{
  pid_t p1;
  int fd[2];
  int num;
  if(pipe(fd))
  {
    printf("Success\n" );
  }

  if((p1=fork())==0)
  {
    printf("CHILD(%d) my parent is %d\n",getpid(),getppid() );
    int n1= 0;
    close(fd[1]);
      read(fd[0],&n1,MAXSIZE);
      printf("Got for parent:%d\n",n1 );


  }else if(p1 >0)
  {
    printf("PARENT(%d) my child is %d\n",getpid(),p1 );
    close(fd[0]);
    num = 20;
    write(fd[1],&num,sizeof(num)+1);
    wait(NULL);
    printf("SENT to child %d\n",num );
  }
}
