//program to reverse an array using iterative way
#include<bits/stdc++.h>

using namespace std;

void reverseArray (int arr[], int size)
{
    int temp, start = 0, end = size - 1;
    while(start < end)
    {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
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
    int arr[] = {1, 2, 3, 4, 5, 6};
    
    int n = sizeof(arr)/sizeof(arr[0]);
    
    reverseArray(arr, n);
    displayArray(arr, n);
    
    return 0;
}
