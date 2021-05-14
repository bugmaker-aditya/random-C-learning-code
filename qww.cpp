#include<iostream>
#include<math.h>
using namespace std;
class X
{
int a;
public:
friend void prime(X);
void getnum(int);
};
void X::getnum(int R)
{a=R;}
void prime(X s)
{int i=2;
while(i<s.a)
{if (s.a%i==0)
  break;
  i++;
}
if(i==s.a)
cout<<"prime";
else
cout<<"not prime";
}



int main()
{ X t;
  int a;
  cout<<"enter no.";
  cin>>a;
  t.getnum(a);
  prime(t);
  return 0;
}
