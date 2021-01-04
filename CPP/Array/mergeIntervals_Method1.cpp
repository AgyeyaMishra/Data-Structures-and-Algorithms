//C++ program for merging overlapping intervals
//Time Complexity: O(nlogn)
//Space Complexity: O(n) extra space for stack
#include<bits/stdc++.h>
using namespace std;

//An interval has start time and end time
struct Interval
{
    int start, end;
};

//compare two intervals according to their starting time
//This is needed for sorting the intervals using library function std::sort() 
bool compareInterval(Interval i1, Interval i2)
{
    return (i1.start < i2.start);
}

//The main function that takes a set of intervals, merges overlapping intervals and prints the result
void mergeIntervals(Interval arr[], int n)
{
    //Test if the given set has at least one Interval
    if(n <= 0)
    {
        return;
    }
    
    //create an empty stack of intervals
    stack <Interval> s;
    
    //sort the intervals in increasing order of start time
    sort(arr, arr + n, compareInterval);
    
    //push the first interval to stack
    s.push(arr[0]);
    
    //start from the next interval and merge if necessary
    for(int i = 1; i < n; i++)
    {
        //get interval from stack top
        Interval top = s.top();
        
        //If current interval is not overlapping with stack top, then push it to the stack
        if(top.end < arr[i].start)
        {
            s.push(arr[i]);
        }
        
        //otherwise update the ending time of top if ending of current interval is more
        else if(top.end < arr[i].end)
        {
            top.end = arr[i].end;
            s.pop();
            s.push(top);
        }
    }
    
    //printing the contents of stack
    cout<<"The merged intervals are : ";
    while(!s.empty())
    {
        Interval t = s.top();
        cout<<"["<<t.start<<","<<t.end<<"]";
        s.pop();
    }
    return;
}

//Driver code
int main()
{
    Interval arr[] = {{6, 8}, {1, 9}, {2, 4}, {4, 7}};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    mergeIntervals(arr, n);
    return 0;
}
