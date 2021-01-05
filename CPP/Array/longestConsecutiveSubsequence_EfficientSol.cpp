//C++ program to find longest consecutive subsequence using the method of hashing
//Time Complexity: O(n)
//Auxiliary Space: O(1)
#include<bits/stdc++.h>
using namespace std;

//Returns length of longest consecutive subsequence
int findLongestConsecSubseq(int arr[], int n)
{
    unordered_set<int> s;
    int ans = 0;
    
    //Hash all the array elements
    for(int i = 0; i < n; i++)
    {
        s.insert(arr[i]);
    }
    
    //check each possible sequence from start then update optimal length
    for(int i = 0; i < n; i++)
    {
        //if current element is the starting element of a sequence
        if(s.find(arr[i] - 1) == s.end())
        {
            //Then check for next elements in the sequence
            int j = arr[i];
            while(s.find(j) != s.end())
            j++;
            
            //update optimal length if this length is more
            ans = max(ans, j - arr[i]);
        }
    }
    return ans;
}

//Driver code
int main()
{
    int arr[] = {1, 9, 3, 10, 4, 20, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Length of the longest consecutive subsequence is : "<<findLongestConsecSubseq(arr, n);
    
    return 0;
}
