//C++ implementation of a naive approach for stock buy-sell problem to maximise project
#include<bits/stdc++.h>
using namespace std;

//Function to return the maximum profit that can be made after buying and selling the given stocks
int maxProfit(int price[], int start, int end)
{
    //If the stock cannot be bough
    if(end <= start)
    {
        return 0;
    }
    
    //Initialise the profit
    int profit = 0;
    
    //The day at which the stock must be bought
    for(int i = start; i < end; i++)
    {
        //The day at which the stock must be sold
        for(int j = i + 1; j <= end; j++)
        {
            //If buying the stock at ith day and selling it at jth day is profitable
            if(price[j] > price[i])
            {
                //update the current profit
                int curr_profit = price[j] - price[i] + maxProfit(price, start, i - 1) + maxProfit(price, j + 1, end);
                
                //update the max profit so far
                profit = max(profit, curr_profit);
            }
        }
    }
    return profit;
}

//Driver code
int main()
{
    int price[] = {100, 180, 260, 310, 40, 435, 695};
    
    int n = sizeof(price)/sizeof(price[0]);
    
    cout<<maxProfit(price, 0, n - 1);
    
    return 0;
}
