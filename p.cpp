#include<iostream>
using namespace std;
#define mkpr 100

float cumulative(int arr[])
{	int dspr=0;
	int m = mkpr;
	for( int i=0;i<3; i++)
		{
			 dspr=mkpr*(100 - arr[i])/100;
				dspr=mkpr;
		}
	int fdis= 100-(dspr*100/float(m));
	return fdis;
}

int main()
{ int arr[]={10,20,30};
	int result = cumulative(arr);
cout<<result;
 return 0;
}