#include<stdio.h>
int main()
{
  int a[5],i,max=0;
  for(i=0;i<=4;i++)
  {
    scanf("%d",&a[i]);
  }
  for(i=0;i<=4;i++)
  {
    if(max>a[i])
    {
      continue;
    }
    else if(max<a[i])
    {
      max=a[i];
      continue;
    }
    }
  printf("max is %d",max);
return 0;
}
