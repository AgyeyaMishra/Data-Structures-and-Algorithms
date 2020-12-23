//C++ program to find the minimum number of jumps required to reach the end of the array 
//Time Complexity: O(n)
//Space Complexity: O(1)
#include<bits/stdc++.h>
using namespace std;

int max(int x, int y)
{
    return (x > y)? x : y;
}

//Return minimum number of jumps required to reach arr[n - 1] from arr[0]
int minJumps(int arr[], int n)
{
    //The number of jumps needed to reach the starting index is 0
    if(n <= 1)
    {
        return 0;
    }
    
    //Return -1 if it is not possible to jump
    if(arr[0] == 0)
    {
        return -1;
    }
    
    //Inititalization
    //stores all time the maximal reachable index in the array
    int maxReach = arr[0];
    
    //stores the number of steps we can still take 
    int step = arr[0];
    
    //stores the number of jumps neccesaary to reach the maximum reachable position
    int jump = 1;
    //start traversing the array
    int i = 1;
    for(i = 1; i < n; i++)
    {
        //check if we have reached the end of the array
        if(i == n - 1)
        {
            return jump;
        }
        
        //updating maxReach
        maxReach = max(maxReach, i + arr[i]);
        
        //we use a step to get to the current index
        step--;
        
        //If no further steps are left
        if(step == 0)
        {
            jump++;
            
            //check if the current index/position or lesser index is the maximum reach point from the previous indices
            
            if(i >= maxReach)
            {
                return -1;
            }
            
            //re-initialize the steps to the amount of steps to reach maxReach from position i
            step = maxReach - i;
        }
        
    }
    return -1;
}

//Driver code
int main()
{
    int arr[] = {1, 3, 6, 1, 0, 9};
    
    int size = sizeof(arr)/sizeof(arr[0]);
    
    cout<<"Minimum number of steps to reach the end is : "<<minJumps(arr, size);
    
    return 0;
}
