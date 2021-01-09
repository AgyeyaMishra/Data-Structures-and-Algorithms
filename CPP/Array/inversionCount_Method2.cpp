//C++ program to count inversions in an array using the method of merge sort 
//Time Complexity: O(nlogn)
//Auxiliary Space: O(n) for temp array
#include<bits/stdc++.h>
using namespace std;

int _mergeSort(int arr[], int temp[], int left, int right);
int merge(int arr[], int temp[], int left, int mid, int right);

//This function sorts the input array and returns the number of inversions in the array
int mergeSort(int arr[], int array_size)
{
    int temp[array_size];
    return _mergeSort(arr, temp, 0, array_size-1);
}

//An auxiliary recursive function that sorts the input array and returns the number of inversions in the array
int _mergeSort(int arr[], int temp[], int left, int right)
{
    int mid, inv_count = 0;
    if(right > left)
    {
        //Divide the array into two parts and call _mergeSortAndCountInv() for each of the parts 
        mid = (right + left)/2;
        
        //Inversion count will be sum of inversions in left part, right part and no of inversions in merging
        inv_count += _mergeSort(arr, temp, left, mid);
        inv_count += _mergeSort(arr, temp, mid + 1, right);
        
        //Merge the two parts
        inv_count += merge(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}

//This function merges two sorted arrays and returns inversion count in the arrays 
int merge(int arr[], int temp[], int left, int mid, int right)
{
    int i, j, k;
    int inv_count = 0;
    
    i = left; // i is index for left sub-array 
    j = mid;  // j is index for right sub-array
    k = left; // k is index for resultant merged sub-array
    
    while((i <= mid - 1) && (j <= right))
    {
        if(arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        
        else
        {
            temp[k++] = arr[j++];
            
            inv_count = inv_count + (mid - i);
        }
    }
    
    //Copy the remaining elements of left sub-array (if there are any) to temp 
    while(i <= mid - 1)
        temp[k++] = arr[i++];
        
    //Copy the remaining elements of right sub-array (if there are any) to temp 
    while(j <= right)
        temp[k++] = arr[j++];
        
    //Copy back the merged elements to the original array 
    for(i = left; i <= right; i++)
        arr[i] = temp[i];
        
    return inv_count;
}

//Driver code
int main()
{
    int arr[] = {1, 20, 6, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int answer = mergeSort(arr, n);
    cout<<"Number of inversions are : "<<answer;
    
    return 0;
}
