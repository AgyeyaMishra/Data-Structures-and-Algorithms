//C++ program code to implement Three Way Partitioning around a given range in an array 
//Time Complexity: O(n)
//Auxiliary Space: O(1)
#include<bits/stdc++.h>
using namespace std;

//Partitions are [0...n - 1] around [lowVal...highVal]
void threeWayPartition(int arr[], int n, int lowVal, int highVal)
{
    //Initialize extra available positions for smaller (than range) and greater elements
    int start = 0, end = n - 1;
    
    //Traverse elements from left
    for(int i = 0; i <= end;    )
    {
        //If current element is smaller than the range, then put it on next available smaller position
        if(arr[i] < lowVal)
        {
            swap(arr[i++], arr[start++]);
        }
        
        //If current element is greater than the range then put it on next available greater position
        if(arr[i] > highVal)
        {
            swap(arr[i], arr[end--]);
        }
        
        else
        {
            i++;
        }
    }
}

//Driver code
int main()
{
    int arr[] = {1, 14, 5, 20, 4, 2, 54, 20, 87, 98, 3, 1, 32};
    
    int size = sizeof(arr)/sizeof(arr[0]);
    
    threeWayPartition(arr, size, 10, 20);
    
    cout<<"Modified Array : ";
    for(int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}
