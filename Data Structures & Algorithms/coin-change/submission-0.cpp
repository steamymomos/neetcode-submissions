class Solution {
public:
    int coinChange(vector<int>& nums, int amount) {
        int n=nums.size();
        vector<int> dp(amount+1,INT_MAX);
        dp[0]=0;
        for(int i=1;i<amount+1;i++){
            for(int j=0;j<n;j++){
                if(i>=nums[j] && dp[i-nums[j]]!=INT_MAX)
                dp[i]=min(1+dp[i-nums[j]],dp[i]);
            }
        }
        if(dp[amount]==INT_MAX)return -1;
        return dp[amount];
    }
};
