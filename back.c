#include<stdio.h>
int main()
{
  long sum;
  int i , j , k;
  for(i = 0 ; i < 1000; i++)
    for(j = 0; j< 1000; j++)
      for(k = 0; k< 1000; k++)
        sum += i * j *k;
  return 0;
}
