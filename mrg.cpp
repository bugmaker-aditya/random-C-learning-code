#include <iostream>
#include <time.h> //for using clock_t
//#include<graphics.h>//just for using delay function
#include <stdlib.h>
using namespace std;

//funtion for merging
void merge(int Array[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int left[n1], right[n2];

    for (int i = 0; i < n1; i++)
        left[i] = Array[l + i];

    for (int j = 0; j < n2; j++)
        right[j] = Array[m + 1 + j];

    int i = 0, j = 0;
    int k = l;
    while ( i < n1 && j < n2)
     {
        if (left[i] <= right[j])
        {
            Array[k] = left[i];
            i++;
        }
        else
        {
            Array[k] = right[j];
            j++;
        }
        k++;
      }
    while (i < n1)
    {
        Array[k] = left[i];
        i++;
        k++;
    }
    while ( j < n2)
    {
        Array[k] = right[j];
        j++;
        k++;
    }
  }
void MergeSort(int Array[], int l, int r)
  {
      if (l < r)
      {
        int m = l + (r - l) / 2;
        MergeSort(Array, l, m);
        MergeSort(Array, m + 1, r);
        merge(Array, l, m, r);
      }
  }
int main()
  {
    clock_t st, end; //for calculating time spend in sorting

    int d=1000;
    ///cout<<"Enter size of array: ";
    //cin>>d;
    int *arr = new int[d];
    cout<<"\nArray will be filled with random elements\n";

    //delay(1000);

    for (int j = 0;j<d;j++)
	{
      int i = rand() % (d+1);
		  arr[j]=i;
  }
    cout<<"\nBefore merge sorting\n";
    for (int i = 0; i < d; i++)
        cout<<arr[i]<<" ";

    cout<<"\n";

    st= (int)clock();
    MergeSort(arr, 0, d - 1);

    cout<<"\nSorted array is \n";

    for (int i = 0; i < d; i++)
        cout<<arr[i]<<" ";
    cout<<"\n";
  //  delay(1000);
    end= (int)clock();
    cout<<"\nTime required for execution: "<< end-st<<" ms"<<endl;
    return 0;
  }
