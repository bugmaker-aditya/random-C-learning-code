#include<iostream>
int f(int x, int y)
{
  return(x>y)?y:x;
}
int main()
{int x;
  x=f(5,9);
  for(int i=1; i<3; i+=3)
  std::cout<<--i;
      return 0;
}
