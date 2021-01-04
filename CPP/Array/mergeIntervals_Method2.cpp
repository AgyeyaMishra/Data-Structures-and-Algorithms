//C++ program to merge overlapping intervals in O(nlogn) time and O(1) extra space 
#include<bits/stdc++.h>
using namespace std;

//An interval
struct Interval
{
    int s, e;
};

//Function used in sort
bool mycomp(Interval a, Interval b)
{
    return a.s < b.s;
}

void mergeIntervals(Interval arr[], int n)
{
    //sort intervals in increasing order of start time
    sort(arr, arr + n, mycomp);
    int index = 0; //stores index of last element in output array
    
    //Traverse all input intervals
    for(int i = 1; i < n; i++)
    {
        //If this is not first interval and overlaps with previous one 
        if(arr[index].e >= arr[i].s)
        {
            //Merge previous and current intervals 
            arr[index].e = max(arr[index].e, arr[i].e);
            arr[index].s = min(arr[index].e, arr[i].s);
        }
        
        else
        {
            index++;
            arr[index] = arr[i];
            
        }
    }
    
    cout<<"The merged intervals are : ";
    for(int i = 0; i <= index; i++)
    {
        cout<<"["<<arr[i].s<<","<<arr[i].e<<"]";
    }
}

//Driver code
int main()
{
    Interval arr[] = {{6, 8}, {1, 9}, {2, 4}, {4, 7}};
    int n = sizeof(arr)/sizeof(arr[0]);
    mergeIntervals(arr, n);
    return 0;
}

