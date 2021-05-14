#include<iostream>
using namespace std;

int main()
{ char a[100]; int i, count = 0;
  gets(a);
  for (i=0; a[i]!='\0';i++)
  {count++;}
  while (count>=0)
  {
    cout<<a[count];
    count--;
  }
  return 0;
}
