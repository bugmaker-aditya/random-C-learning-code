#include <iostream>
#include <time.h>
using namespace std;

void swapnum(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int divide(int arr[], int low, int high)
{
    int mid = arr[high];
    int s = low - 1;
    for (int j = low; j <= high -1 ; j++)
    {
      if (arr[j] < mid)
        {   s++;
            swapnum(&arr[s], &arr[j]);
        }
    }
    swapnum(&arr[s + 1], &arr[high]);
    return s+1;
}

void qSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int ss = divide(arr, low, high);
        qSort(arr, low, ss - 1);
        qSort(arr, ss + 1, high);
    }
}

int main()
{ clock_t start, end;
    int a=6 ;
    //cout<<"enter size of array";
    //cin>> a;
    //int *arr = new int[a];
    int arr[]={3,8,1,4,7,6};
    /*for (int j = 0;j<a;j++)
	{
      int i = rand() % a;
		  arr[j]=i;
    }*/
  for(int i =0; i<a;i++)
    cout<<arr[i]<<" ";
  cout<<endl;

    qSort(arr, 0, a - 1);

    cout << "Sorted array: \n";

    for (int i = 0; i <= a-1 ; i++)
           cout << arr[i] << " ";
    cout<<endl<<"array after ordering"<<endl;
     for (int i=0;i<=a/2;i++)
    {
       int  j=a-i-1;
        if(i>j)
        break;
        if(i==j)
        {
            cout<<arr[i];
        }
        else
        {
            cout<<arr[i]<<arr[j];
        }

    }
    return 0;
}
