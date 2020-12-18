//C++ program to find union and intersection of two unsorted arrays using hashing
//Time Complexity: O(n1+n2) under the assumption that hash table search and insert operations take O(1) time

#include<bits/stdc++.h>
using namespace std;

//Prints union of arr1[0...n1-1] and arr2[0...n2-1]
void printUnion(int arr1[], int arr2[], int n1, int n2)
{
    set<int> hs;
    
    //Insert the elements of arr1[] to set hs
    for(int i = 0; i < n1; i++)
    {
        hs.insert(arr1[i]);
    }
    
    //Insert the elements of arr2[] to set hs
    for(int i = 0; i < n2; i++)
    {
        hs.insert(arr2[i]);
    }
    
    //Prints the content of set hs
    for(auto it = hs.begin(); it != hs.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<"\n";
}

//Prints intersection of arr1[0...n1-1] and arr2[0...n2-1]
void printIntersection(int arr1[], int arr2[], int n1, int n2)
{
    set<int> hs;
    
    //Insert the elements of arr1[] to set hs
    for(int i = 0; i < n1; i++)
    {
        hs.insert(arr1[i]);
    }
    
    for(int i = 0; i < n2; i++)
    {
        if(hs.find(arr2[i]) != hs.end())
        {
            cout<<arr2[i]<<" ";
        }
    }
}

//Driver code
int main()
{
    int arr1[] = {7, 1, 5, 2, 3, 6};
    int arr2[] = {3, 8, 6, 20, 7};
    
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    
    cout<<"The union of the two sets is : ";
    printUnion(arr1, arr2, n1, n2);
    
    cout<<"The intersection of the two sets is : ";
    printIntersection(arr1, arr2, n1, n2);
    
    return 0;
}
