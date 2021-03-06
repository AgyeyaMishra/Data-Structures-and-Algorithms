//C++ program to print largest contiguous subarray sum using Kadane's Algorithm
//Time Complexity: O(n)
//Algorithm Paradigm: Dynamic Programming

#include<bits/stdc++.h>
using namespace std;

int maxSubArraySum(int a[], int size)
{
    int max_so_far = INT_MIN, max_ending_here = 0;
    for(int i = 0; i < size; i++)
    {
        max_ending_here = max_ending_here + a[i];
        
        if(max_ending_here < 0)
        {
            max_ending_here = 0;
        }
        
        else if(max_so_far < max_ending_here)
        {
            max_so_far = max_ending_here;
        }
    }
    
    return max_so_far;
}

//Driver code
int main()
{
    int a[] = {-2, -3, 4, -1, 2, 1, 5, -3};
    int n = sizeof(a)/sizeof(a[0]);
    
    int max_sum = maxSubArraySum(a, n);
    cout<<"Maximum contiguous sub array sum is : "<<max_sum;
    
    return 0;
}
