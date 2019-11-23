#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<string.h>
#define MAXSIZE 50

int isPrime(int x)
{
  int count= 0;
  int i = 0;
  for(i= 2 ;i< x/2; i++)
  {
    if(x % i == 0)
      count++;
  }
  if(count == 0)
  {
    return 1;
  }
  return 0;
}

void primeFinder(int x, int y,int child)
{
  int i  = 0;
  for(i = x; i<y; i++)
  {
    if(isPrime(i))
    {
      printf("Primes arefro child(%d)=%d\n",child,i );
    }
  }
}

int main()
{
  int fd1[2], fd2[2],fd3[2];
  char* s;
  if(pipe(fd1)==0 && pipe(fd2)==0 && pipe(fd3)==0)
  {
    printf("PIPE success\n" );
  }

  pid_t p1, p2, p3;

  if((p1=fork())==0)
  { //START OF CHILD 1 BODY
    char* buf[MAXSIZE];
    int x[2];
    close(fd1[1]);
    read(fd1[0],x,MAXSIZE);
    printf("GOT FROM PARENT CHILD1\n");


    printf("Range for Child1 is %d %d\n",x[0],x[1] );
    primeFinder(x[0],x[1],1);



    //END OF CHILD 1 BODY
  }else if(p1 > 0)
  {
    if((p2=fork())==0)
    {
      //START OF CHILD 2 BODY
        char* buf2[MAXSIZE];
        int x[2];
        close(fd2[1]);
        read(fd2[0],x,MAXSIZE);
        printf("GOT FROM PARENT CHILD2\n" );

        printf("Range for Child2 is %d %d\n",x[0],x[1] );
        primeFinder(x[0],x[1],2);





        //END OF CHILD 2 BODY
    }else if(p2 > 0)
    {
      if((p3=fork())==0)
      {
        //START OF CHILD 3 BODY
          char* buf3[MAXSIZE];
          int x[2];
          close(fd3[1]);
          read(fd3[0],x,MAXSIZE);
          printf("GOT FROM PARENT CHILD3\n" );

          printf("Range for Child3 is %d %d\n",x[0],x[1] );
          primeFinder(x[0],x[1],3);




          //END OF CHILD 3 BODY
      }else if(p3 > 0)
      {
        //PARENT FOR ALL THREE CHILD PROCESS
        int n = 0;
        printf("Enter UPPER Range:\n" );
        scanf("%d", &n);
        int ar1[2];
        int ar2[2];
        int ar3[2];

        float r1 = n;
        float r2 = 2*n/3;
        float r3 = n/3;
        ar1[0] = 0;
        ar1[1] = r3;
        ar2[0] = (int)r3+1;
        ar2[1] = (int)r2;
        ar3[0] = (int)r2+1;
        ar3[1] = (int)r1;
        close(fd1[0]);
        close(fd2[0]);
        close(fd3[3]);
        write(fd1[1],ar1, sizeof(ar1)+1 );
        printf("Writing %d and %d to pipe 1\n",ar1[0],ar1[1] );
        write(fd2[1],ar2, sizeof(ar2)+1);
        printf("Writing %d and %d to pipe 1\n",ar2[0],ar2[1] );
        write(fd3[1],ar3, sizeof(ar3)+1);
        printf("Writing %d and %d to pipe 1\n",ar3[0], ar3[1] );

        wait(NULL);
      }
    }
  }
}
