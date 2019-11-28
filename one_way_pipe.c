#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<sys/wait.h>
#define MAXSIZE 50
int main()
{


  int fd1[2];
  int fd2[2];
  int d1,d2;
  char buf1[MAXSIZE];
  char buf2[MAXSIZE];
  int s2= pipe(fd1);
  int s = pipe(fd2);
  if(s == -1 || s2 == -1)
  {
    printf("Pipe error!!!" );
  }
  pid_t pid;
  if((pid = fork())==0)
  {
    close(fd1[1]);//child dont have write access to fd1
    close(fd2[0]);//child dont have read access to fd2
    printf("CHILD(%d)\n",getpid() );
    while(1) {

    char *chC = "Hello from Child";
    write(fd2[1], chC, strlen(chC)+1);
    d1 = read(fd1[0], buf1, MAXSIZE);
    printf("Child(%d):%s of size %d\n",getpid(),buf1,d1 );

    sleep(3);

  }


  } else if(pid  > 0)
  {
    printf("Parent(%d)\n", getpid());
    close(fd2[1]); //closing write access to fd2
    close(fd1[0]); //closing read access to fd1
    while(1) {

    char *chP = "Hello from Parent";
    write(fd1[1], chP, strlen(chP )+1);
    d2 = read(fd2[0], buf2, MAXSIZE);
    printf("Parent(%d):%s of size %d\n",getpid(),buf2,d2 );
    sleep(3);

  }
  }
}
