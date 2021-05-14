/*Enter your code here. Read input from STDIN. Print your output to STDOUT*/
#include <iostream>
using namespace std;
int main()
{int R,C,i,j,arr[20][20],b[10],max,count=0;
	//Write code here
	cin>>R;
	for(i =1 ;i<=R;i++)
	{for(j=1;j<=R;j++)
	{cin>>arr[i][j];
	}
	}
	for(i =1 ;i<=R;i++)
	{for(j=1;j<=C;j++)
	{if(arr[i][j]==1)
	{count++;
	if(arr[i-1][j]==1&& i-1 >0)
	count++;
	if(arr[i][j-1]==1 && j-1>0)
	count++;
	if(arr[i+1][j]==1 && i+1<=R)
	count++;
	if(arr[i][j+1]==1 && j+1<=C)
	count++;
	if(arr[i-1][j+1]==1 && j+1<=C)
	count++;
	if(arr[i-1][j-1]==1 && i-1>0 && j-1>0)
	count++;
	if(arr[i+1][j-1]==1 && i+1<=R && j-1>0)
	count++;
	if(arr[i+1][j+1]==1 && i+1<=R && j+1<=C)
	count++;

	}
	b[j]=count;
	count=0;}
	}
	max=b[0];
	for(j=1;j<=C;j++)
	{if(b[j]>max)
	max=b[j];
	cout<<b[j]<<"\n";
	}
cout<<max;
}
