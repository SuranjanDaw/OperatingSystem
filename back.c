#include<stdio.h>
int main()
{
  long sum;
  int i , j , k;
  for(i = 0 ; i < 500000; i++)
    for(j = 0; j< 500000; j++)
      for(k = 0; k< 500000; k++)
        sum += i * j *k;
  return 0;
}
