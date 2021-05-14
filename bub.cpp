#include<iostream>
#include<stdlib.h>

using namespace std;

void swap(int &a, int &b) {
   int temp;
   temp = a;
   a = b;
   b = temp;
}
void disp(int *arr, int size) {
   for(int i = 0; i<size; i++)
      cout << arr[i] << " ";
   cout << endl;
}
void BSort(int *arr, int size) {
   for(int i = 0; i<size; i++) {
      int flag = 0;
      for(int j = 0; j<size-i-1; j++) {
         if(arr[j] > arr[j+1]) {
            swap(arr[j], arr[j+1]);
            flag = 1;
         }
      }
      if(!flag)
         break;
   }
}

void reverseArray(int *arr, int n){
   for (int low = 0, high = n - 1; low < high; low++, high--){
      swap(arr[low], arr[high]);
   }
}

void addarr(int *arr, int n){
  int *arr2 = new int [n];
  for(int i=0; i<n; i++){
    arr2[i]= arr[i]+arr[n-i-1];
  }
  for(int i=0; i<n; i++){
    cout<<arr2[i]<<" ";
  }
}

int main() {
   int n;
   cout << "Enter the size of array ";
   cin >> n;
   int *arr = new int [n];

   for(int i = 0; i<n; i++) {
      int j= rand()%n;
      arr[i]=j;
    }
   cout <<endl<< "array before Sorting: "<<endl;
   disp(arr, n);
   BSort(arr, n);
   cout <<endl<< "array after Sorting: "<<endl;
   disp(arr, n);
   cout<<endl<<"array after reversing"<<endl;
   reverseArray(arr, n);
   disp(arr,n);
   cout<<endl<<"sum of array"<<endl;
   addarr(arr,n);
}
