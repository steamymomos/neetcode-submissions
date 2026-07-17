class Solution {
public:
    int dfs(vector<int>& coins,vector<vector<int>>& dp,int amount,int i){
        if(i>=coins.size())return 0;
        if(amount==0)return dp[0][i];
        if(amount<0){
            return 0;
        }
        if(dp[amount][i]!=-1)return dp[amount][i];
        return dp[amount][i]=dfs(coins,dp,amount-coins[i],i)+dfs(coins,dp,amount,i+1);
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(amount+1,vector<int>(n,-1));
        for(int i=0;i<n;i++)
        dp[0][i]=1;
        return dfs(coins,dp,amount,0);
    }
};
