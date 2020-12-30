//C++ program to find smallest subarray which has sum greater than a given number
//Time Complexity: O(n)
//Space Complexity: O(1)
#include<bits/stdc++.h>
using namespace std;

//Returns length of smallest subarray with sum greater than x
//If there is no subarray with given sum, then return n + 1 
int smallestSubWithSum(int arr[], int n, int x)
{
    //Initialize current sum and minimum length
    int curr_sum = 0, min_len = n + 1;
    
    //Initialize starting and ending indexes
    int start = 0, end = 0;
    
    while(end < n)
    {
        //Keep adding array elements while sum is smaller than x
        while(curr_sum <= x && end < n)
        {
            curr_sum += arr[end++];
        }
        
        //If current sum becomes greater than x
        while(curr_sum > x && start < n)
        {
            //update minimum length if needed
            if(end - start < min_len)
            {
                min_len = end - start;
            }
            
            //remove starting elements
            curr_sum -= arr[start++];
        }
        
        
    }
    return min_len;
}

//Driver code
int main()
{
    int arr[] = {1, 4, 45, 6, 10, 19};
    int x = 51;
    int n = sizeof(arr)/sizeof(arr[0]);
    //function calling
    int res = smallestSubWithSum(arr, n, x);
    //printing the result
    res == n + 1 ? cout<<"Not possible" : cout<<res<<endl;
    
    return 0;
}
