//C++ program to merge two sorted arrays with O(1) extra space
//Time Complexity: The worst case time complexity of the below code is O(m*n). The worst case occurs when all elements of ar1[] are greater than all elements of ar2[]
#include<bits/stdc++.h>
using namespace std;

//Merge ar1[] and ar2[] with O(1) extra space
void merge(int ar1[], int ar2[], int m, int n)
{
    //Iterate through all elements of ar2[] starting from the last element
    for(int i = n - 1; i >= 0; i--)
    {
        //Find the smallest element greater than ar2[i]. Move all elements one position ahead till the smallest greater element is not found
        
        int j, last = ar1[m - 1];
        for(j = m - 2; j >= 0 && ar1[j] > ar2[i]; j--)
        {
            ar1[j + 1] = ar1[j];
        }
        
        //If there was a greater element
        if(j != m - 2 || last > ar2[j])
        {
            ar1[j + 1] = ar2[i];
            ar2[i] = last;
        }
        
    }
}

//Driver code
int main()
{
 int ar1[] = {1, 5, 9, 10, 15, 20};
 int ar2[] = {2, 3, 8, 13};
 
 int m = sizeof(ar1)/sizeof(ar1[0]);
 int n = sizeof(ar2)/sizeof(ar2[0]);
 
 merge(ar1, ar2, m, n);
 
 cout<<"After merging first array : ";
 for(int i = 0; i < m; i++)
 {
     cout<<ar1[i]<<" ";
 }
 
 cout<<"\n"<<"After merging second array : ";
 for(int i = 0; i < n; i++)
 {
     cout<<ar2[i]<<" ";
 }
 
 return 0;
}
