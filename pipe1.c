#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<signal.h>
#define MAXSIZE 50
void func(int x)
{
  
}
int main()
{
  int fd[2];
  char buf[MAXSIZE];
  if(pipe(fd) == 0)
  {
    printf("Success\n" );
  }

  pid_t p = fork();
  if(p == 0)
  {
    //close(fd[1]);
      while(1) {
      int size = read(fd[0], buf, MAXSIZE);
      printf("Got from parent:%s\n",buf );
      if(strcmp(buf,"quit") == 0)
      {
        printf("exiting child");
        exit(0);
      }
      sleep(2);
    }


  }else if(p > 0)
  {
    //close(fd[0]);
    char *ch = "Hello from Parent";
    printf("Hello from Parent(%d) my child %d",getpid(),p );
    while(1) {
      char* d;
      printf("Enter some string=" );
      scanf("%s",d );
      printf("%s\n",d );
      //char* s = (char*)d;
      if(strcmp(d,"quit")==0){
        kill(p,SIGKILL);
        printf("Exiting\n");
        exit(0);
      }

      write(fd[1], d, strlen(d)+1);
      printf("Written to pipe\n" );
      sleep(2);
    }
    wait(NULL);
  }
}
