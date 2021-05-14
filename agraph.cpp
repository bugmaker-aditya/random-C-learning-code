#include <iostream>
using namespace std;

int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
  return -1;
}
int main()
{
	int arr[100],d;

	cout<<"enter no. of elements you wanna enter (max 10?:0)" ;
	ONE: cin>>d;
	if(d<=100)
	for(int i = 0; i<d; i+=1)
	cin>>arr[i];
	else
	{
		cout<<"wrong choice!!! enter again";
		goto ONE;
	}
	int x;
	cout<<"Enter element to be searched"<<endl;
	cin>>x;
	int result = binarySearch(arr, 0, d- 1, x);
	 if(result == -1)
	  cout << "Element is not present in array";
	else
	cout << "Element is present at index " << result;
	return 0;
}
