//C++ progrm to find the minimum number of jumps required to reach the end of an array using dynamic programming algorithm paradigm
//Time Complexity: O(n*n)
#include<bits/stdc++.h>
using namespace std;

int min(int x, int y)
{
    return (x < y)? x : y;
}

int minJumps(int arr[], int n)
{
    //jumps[n - 1] will hold the result
    
    int* jumps = new int[n];
    int i, j;
    
    if(n == 0 || arr[0] == 0)
    {
        return INT_MAX;
    }
    
    jumps[0] = 0;
    
    //find the minimum number of jumps required to reach arr[i] from arr[0], and assign this value to jumps[i];
    for(i = 1; i < n; i++)
    {
        jumps[i] = INT_MAX;
        for(j = 0; j < i; j++)
        {
            if(i <= j + arr[j] && jumps[j] != INT_MAX)
            {
                jumps[i] = min(jumps[i], jumps[j] + 1);
                break;
            }
        }
    }
    
    return jumps[ n - 1];
}

//Driver code
int main()
{
    int arr[] = {1, 3, 6, 1, 0, 9};
    
    int size = sizeof(arr)/sizeof(arr[0]);
    
    cout<<"Minimum number of jumps to reach the end is : "<<minJumps(arr, size);
    
    return 0;
}
