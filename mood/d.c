#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

double max(double i,double j)
{
   
   return i>j?i:j;
}

int max5(int sum1,int sum2,int sum3,int sum4,int sum5)
{
  return max(sum1,max(sum2,max(sum3,max(sum4,sum5))));
}

int main()
{
int i=0;
float sum=0;
while (i!=10)
 {
 sum=sum + i;
i++;
}
printf("%lf\n",log2(1.0/5.0)+ 2.0);
}
