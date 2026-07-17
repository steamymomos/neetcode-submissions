class Solution {
public:
    int dfs(vector<int>& prices,int canbuy,int i,vector<vector<int>>& dp){
        if(i==prices.size())return 0;
        if(dp[i][canbuy]!=-1)return dp[i][canbuy];
        if(canbuy==1){
            return dp[i][canbuy]=max(-prices[i]+dfs(prices,canbuy+1,i+1,dp),dfs(prices,canbuy,i+1,dp));
        }
        else if(canbuy==2){
            return dp[i][canbuy]=max(prices[i]+dfs(prices,canbuy-2,i+1,dp),dfs(prices,canbuy,i+1,dp)); 
        }
        else{
            return dp[i][canbuy]=dfs(prices,canbuy+1,i+1,dp);
        }
    }
    int maxProfit(vector<int>& prices) {
        int canbuy=1;
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(3,-1));
        return dfs(prices,canbuy,0,dp);
    }
};
