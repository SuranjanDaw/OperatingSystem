#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<string.h>
#include<stdlib.h>

int main()
{
  FILE *fdin, *fdout;
  char readbuf[80];
  if((fdin =popen("ls -l| tr -s ' '| cut -d ' ' -f5,9","r"))==NULL)
  {
    printf("Popen read error \n");
    exit(1);
  }

  if((fdout=popen("sort -nr","w"))==NULL)
  {
    printf("popen write error\n" );
    exit(1);
  }
  while(fgets(readbuf,80,fdin))
  {
    fputs(readbuf,fdout);
  }
  return 0;
}
