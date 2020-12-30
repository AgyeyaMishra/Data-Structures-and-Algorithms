//C++ program to find smallest subarray which has sum greater than a given number
//Time Complexity: O(n^2)
//Space Complexity: O(1)
#include<bits/stdc++.h>
using namespace std;

//Returns length of smallest subarray with sum greater than x
//If there is no subarray with given sum, then return n + 1 
int smallestSubWithSum(int arr[], int n, int x)
{
    //Initialize length of smallest subarray as n + 1
    int min_len = n + 1;
    
    //Pick every element as starting point
    for(int start = 0; start < n; start++)
    {
        //Initialize sum starting with current start
        int curr_sum = arr[start];
        
        //If first element itself is greater
        if(curr_sum > x)
        {
            return 1;
        }
        
        //Try different ending points for current start
        for(int end = start + 1; end < n; end++)
        {
            //add last element to current sum
            curr_sum += arr[end];
            
            //If sum becomes more than x and length of this subarray is smaller than current smallest length, update the smallest length (or result)
            if(curr_sum > x && (end - start + 1) < min_len)
            {
                min_len = (end - start + 1);
            }
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
    //function call
    int res = smallestSubWithSum(arr, n, x);
    //printing result
    (res == n + 1)? cout<<"Not possible" : cout<<res<<endl;
    
    return 0;
}
