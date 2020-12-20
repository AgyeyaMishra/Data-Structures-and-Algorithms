//C++ program to cyclically rotate an array by one 
//Time Complexity: O(n) since we have to iterate through all elements
//Space Complexity: O(1) 

#include<bits/stdc++.h>
using namespace std;

void rotate(int arr[], int n)
{
    int x = arr[n - 1], i;
    for(i = n - 1; i > 0; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = x;
}

//Driver code
int main()
{
    int arr[] = {1, 2, 3, 4, 5}, i;
    
    int n = sizeof(arr)/sizeof(arr[0]);
    
    cout<<"Given array is : ";
    for(i = 0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    cout<<endl;
    
    //function calling
    rotate(arr, n);
    
    cout<<"Rotated array is : ";
    for(i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}
