//Program to find the minimum and maximum element in an array using tournament method

#include <iostream>
using namespace std;

//Pair struct is used to return two values from getMinMan() function

struct Pair
{
    int min;
    int max;
};

struct Pair getMinMax(int arr[], int low, int high)
{
    struct Pair minmax, mml, mmr;
    int mid;
    
    //If there is only one element in the array
    if(low == high)
    {
        minmax.max = arr[low];
        minmax.min = arr[low];
        return minmax;
    }
    
    //If there are two elements in the array
    if(high == low + 1)
    {
        if(arr[low] > arr[high])
        {
            minmax.max = arr[low];
            minmax.min = arr[high];
        }
        
        else
        {
            minmax.max = arr[high];
            minmax.min = arr[low];
        }
        
        return minmax;
    }
    
    //If there are more than two elements
    mid = (low + high)/2;
    mml = getMinMax(arr, 0, mid);
    mmr = getMinMax(arr, mid + 1, high);
    
    if(mml.min < mmr.min)
      minmax.min = mml.min;
      
    else
      minmax.min = mmr.min;
    
    
    if(mml.max < mmr.max)
       minmax.max = mmr.max;
       
    else
       minmax.max = mml.max;
       
    return minmax;
    
}

//Driver code
int main ()
{
    int arr[] = {100, 2, 11, 100, 156};
    
    int size = sizeof(arr)/sizeof(arr[0]);
    
    struct Pair minmax = getMinMax(arr, 0 , size - 1);
    
    cout<<"The minimum element is : "<<minmax.min<<"\n";
    cout<<"The maximum element is : "<<minmax.max<<"\n";
    
    return 0;
}
   
