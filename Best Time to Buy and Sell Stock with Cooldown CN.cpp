#include <bits/stdc++.h> 
using namespace std;
/* recursion 
int f(int index,int buy,vector<int> &prices)
{
    if(index>=prices.size())
    return 0;
    int profit;
    if(buy)
    {
        profit= max(f(index+1,1,prices),-prices[index]+f(index+1,0,prices));
    }
    else
    {
        profit= max(f(index+1,0,prices), prices[index]+f(index+2,1,prices));
    }
    return profit;
}
int stockProfit(vector<int> &prices){
    return f(0,1,prices);
}

*/

/* memozitaion

int f(int index,int buy,vector<int> &prices,vector<vector<int>> &dp)
{
    if(index>=prices.size())
    return 0;
    
    if(dp[index][buy]!=-1)  return dp[index][buy];
    
    int profit;
    if(buy)
    {
        profit= max(f(index+1,1,prices,dp),-prices[index]+f(index+1,0,prices,dp));
    }
    else
    {
        profit= max(f(index+1,0,prices,dp), prices[index]+f(index+2,1,prices,dp));
    }
    return dp[index][buy]=profit;
}
int stockProfit(vector<int> &prices){
    int n=prices.size();
    vector<vector<int>> dp(n,vector<int>(2,-1));
    return f(0,1,prices,dp);
}
*/

/* tabulation 

int stockProfit(vector<int> &prices){
    int n=prices.size();
    vector<vector<int>> dp(n+2,vector<int>(2,0));
    

    

    for(int index=n-1;index>=0;index--)
    {
        for(int buy=0;buy<=1;buy++)
        {           int profit;
                      if(buy)
                {
              profit= max(dp[index+1][1],-prices[index]+dp[index+1][0]);
                             }
                     else
                     {
                        profit= max(dp[index+1][0],prices[index]+dp[index+2][1]);
                         }
                         
                     dp[index][buy]=profit;
            
        }
    }
    return dp[0][1];
}

*/

// tabulation + space optiization

int stockProfit(vector<int> &prices){
    int n=prices.size();
    vector<int> prev1(2,0);
    vector<int> prev2(2,0);
     vector<int> curr(2,0); 
    

    

    for(int index=n-1;index>=0;index--)
    {
        for(int buy=0;buy<=1;buy++)
        {     
            
                int profit;
        
                      if(buy)
                {
              profit= max(prev1[1],-prices[index]+prev1[0]);
                             }
                     else
                     {
                        profit= max(prev1[0],prices[index]+prev2[1]);
                         }
                         
                     curr[buy]=profit;
            
        }
        
        prev2=prev1;
        prev1=curr;
        
    }
    return curr[1];
}


   
