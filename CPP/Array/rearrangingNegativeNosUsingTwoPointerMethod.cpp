//C++ program to put all negative numbers befor epositive number using 2 - pointer approach
//Time Complexity = O(n)
//Space Complexity = O(1)

#include<bits/stdc++.h>
using namespace std;

//Function to shift all the negative elements on the left side
void shiftall(int arr[], int left, int right)
{
    //Loop t iterate the array from left to right
    while(left<=right)
    {
        //condition to check if the left and right elements are negative
        if(arr[left] < 0 && arr[right] < 0)
        {
            left += 1;
        }
        
        //condition to check if the left elements are positive and the right elements are negative
        else if(arr[left] > 0 && arr[right] < 0)
        {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left += 1;
            right -= 1;
        }
        
        else if(arr[left] > 0 && arr[right] > 0)
        {
            right -= 1;
        }
        
        else
        {
            left += 1;
            right -= 1;
        }
    }
}

//Utility function to print the array
void printArray(int arr[], int right)
{
    for(int i = 0; i <= right; i++)
    {
        cout<<arr[i]<<" ";
    }
}

//Driver code
int main()
{
    int arr[] = {-12, 11, 13, -6, -7, -8, 4, 5};
    
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    
    shiftall(arr, 0, arr_size-1);
    
    cout<<"The rearranged array is : ";
    printArray(arr, arr_size-1);
    
    return 0;
}

