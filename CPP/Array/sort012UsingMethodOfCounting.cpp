//C++ program to sort an array with Os, 1s and 2s in a single pass using method of counting
//Time Complexity = O(n)
//Extra Space = O(1)

#include<bits/stdc++.h>
using namespace std;

void printArray(int arr[], int size)
{
    for(int i = 0; i<size; i++)
        cout<<arr[i]<<" ";
}

void sortArray(int arr[], int arr_size)
{
    int i, cnt0 = 0, cnt1 = 0, cnt2 = 0;
    
    //count the number of 0s, 1s and 2s in the array
    for(i = 0; i<arr_size; i++)
    {
        switch(arr[i])
        {
            case 0: cnt0++;
                    break;
                    
            case 1: cnt1++;
                    break;
                    
            case 2: cnt2++;
                    break;
        }
        
    }
    
    //updating the array
    i = 0;
    
    //store all the 0s in the beginning
    while(cnt0 > 0)
    {
        arr[i++] = 0;
        cnt0--;
    }
    
    //then all the 1s
    while(cnt1 > 0)
    {
        arr[i++] = 1;
        cnt1--;
    }
    
    //finally all the 2s
    while(cnt2 > 0)
    {
        arr[i++] = 2;
        cnt2--;
    }
    
}

int main()
{
    int arr[] = {0, 1, 1, 0, 1, 2, 2, 0, 0, 0, 2, 1 ,1 ,1};
    
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    
    sortArray(arr, arr_size);
    
    cout<<"Array after segregation is : ";
    printArray(arr, arr_size);
    
    return 0;
}
