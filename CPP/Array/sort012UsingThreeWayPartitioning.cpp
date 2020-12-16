//C++ program to sort an array with Os, 1s and 2s in a single pass using 3-way paritioning
//Time Complexity = O(n)
//Extra Space = O(1)

#include<bits/stdc++.h>
using namespace std;

void sort012(int a[], int arr_size)
{
    int low = 0;
    int high = arr_size - 1;
    int mid = 0;
    
    while(mid <= high)
    {
        switch(a[mid])
        {
            case 0: swap(a[low++], a[mid++]);
                    break;
                    
            case 1: mid++;
                    break;
                    
            case 2: swap(a[mid], a[high--]);
                    break;
                    
        }
    }
}

void printArray(int arr[], int arr_size)
{
    for(int i = 0; i<arr_size; i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main()
{
    int arr[] = {0, 1, 1, 0, 1, 2, 2, 0, 0, 0, 2, 1, 2, 0};
    
    int size = sizeof(arr)/sizeof(arr[0]);
    
    sort012(arr, size);
    
    cout<<"Array after segregation : ";
    printArray(arr, size);
    
    return 0;
}
