//C++ program to find the next lexicographically greater permutation of a word using STL
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    string s = {"gfg"};
    bool val = next_permutation(s.begin(), s.end());
    
    if(val == false)
    cout<<"No word possible!"<<endl;
    
    else
    cout<<s<<endl;
    
    return 0;
}
