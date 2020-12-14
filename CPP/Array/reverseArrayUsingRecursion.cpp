//program to reverse an array using recursion
#include<bits/stdc++.h>

using namespace std;

void reverseArray(int arr[], int start, int end)
{
    if(start >= end)
       return;
       
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    
    reverseArray(arr, start + 1, end - 1);
}

void displayArray(int arr[], int size)
{
    cout<<"The output array is : ";
    for(int i = 0; i<size; i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main()
{
    int start, end;
    int arr[] = {1, 2, 3, 4, 5, 6};
    
    int n = sizeof(arr)/sizeof(arr[0]);
    
    start = 0;
    end = n - 1;
    
    reverseArray(arr, start, end);
    displayArray(arr, n);
    
    return 0;
}
