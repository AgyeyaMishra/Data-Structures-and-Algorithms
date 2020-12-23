//C++ program to find the minimum number of jumps required to reach the end of the array using naive recursive approach
//Time Complexity: O(n*n) - Since there are maximum n possible ways to make a move from a element
//Space Complexity: O(1) - if recursive stack is ignored
#include<bits/stdc++.h>
using namespace std;

//Function to return the minimum number of jumps to reach arr[h] from arr[l]
int minJumps(int arr[], int n)
{
    //Base case: when source and destination are same
    if(n == 1)
    {
        return 0;
    }
    
    //Traverse through all points reachable from arr[l]
    //Recursively, get the minimum number of jumps needed to reach arr[h] from these reachable points
    int res = INT_MAX;
    for(int i = n - 2; i >= 0; i--)
    {
        if(i + arr[i] >= n - 1)
        {
            int sub_res = minJumps(arr, i + 1);
            if(sub_res != INT_MAX)
            {
                res = min(res, sub_res + 1);
            }
        }
    }
    
    return res;
}

//Driver code
int main()
{
    int arr[] = {1, 3, 6, 3, 2, 3, 6, 8, 9, 5};
    
    int n = sizeof(arr)/sizeof(arr[0]);
    
    cout<<"Minimum number of jumps to reach the end is : "<<minJumps(arr, n);
    
    return 0;
}
