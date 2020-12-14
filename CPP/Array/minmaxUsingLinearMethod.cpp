//Program to find the minimum and maximum element in an array using linear method

#include <iostream>
using namespace std;

//Pair struct is used to return two values from getMinMan() function

struct Pair
{
    int min;
    int max;
};

struct Pair getMinMax(int arr[], int size)
{
    struct Pair minmax;
    int i;
    
    /*if there is only one element in the array*/
    
    if(size==1)
    {
        minmax.min = arr[0];
        minmax.max = arr[0];
        return minmax;
    }
    
    /*if there are more than one elements in the array*/
    
    if(arr[0] > arr[1])
    {
        minmax.max = arr[0];
        minmax.min = arr[1];
    }
    
    else
    {
        minmax.max = arr[1];
        minmax.min = arr[0];
    }
    
    for(i = 2; i<size; i++)
    {
        if(arr[i] > minmax.max)
           minmax.max = arr[i];
           
        else if(arr[i] < minmax.min)
               minmax.min = arr[i];
    }
    
    return minmax;
}

//Driver function
int main() 
{
    int arr[] = {100, 200, 1, 2, 30, 1000};
    
    int size = sizeof(arr)/sizeof(arr[0]);
    
    struct Pair minmax = getMinMax(arr, size);
    
    cout<<"The minimum element in the array is : "<<minmax.min<<"\n";
    cout<<"The maximum element in the array is : "<<minmax.max<<"\n";
    
    return 0;

}
