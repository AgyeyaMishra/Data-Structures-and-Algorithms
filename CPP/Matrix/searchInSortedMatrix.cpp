//C++ program to find whether a given element is present in the given 2-D Matrix
#include<bits/stdc++.h>
using namespace std;

#define M 3 
#define N 4

//basic binary search to find an element in a 1-D array 
bool binarySearch1D(int arr[], int k)
{
    int low = 0;
    int high = N - 1;
    
    while(low <= high)
    {
        int mid = low + (high - low)/2;
        
        //If element if found, return true 
        if(arr[mid] == k)
        {
            return true;
        }
        
        //If middle less than k then skip the left part of an array else skip the right part 
        if(arr[mid] < k)
        {
            low = mid + 1;
        }
        
        else
        {
            high = mid - 1;
        }
    }
    //If not found, return false 
    return false;
}

//Function to search an element in a matrix based on divide and conquer approach
bool searchMatrix(int matrix[M][N], int k)
{
    int low = 0;
    int high = M - 1;
    while(low <= high)
    {
        int mid = low + (high - low)/2;
        
        //If the element lies in the range of this row then call 1-D binary search on this row 
        if((k >= matrix[mid][0]) && (k <= matrix[mid][N - 1]))
        {
            return binarySearch1D(matrix[mid], k);
        }
        
        //If the element if less than the starting element of that row then search in upper rows else search in the lower rows
        if(k < matrix[mid][0])
            high = mid - 1;
         
        else
            low = mid + 1;
    }
    //if not found
    return false;
}

//Driver code
int main()
{
    int matrix[M][N] = {{1, 3, 5, 7}, {10, 11, 16, 20}, {12, 13, 34, 50}};
    int k = 3;
    
    if(searchMatrix(matrix, k))
        cout<<"Found."<<endl;
        
    else
        cout<<"Not Found."<<endl;
        
    return 0;
}
