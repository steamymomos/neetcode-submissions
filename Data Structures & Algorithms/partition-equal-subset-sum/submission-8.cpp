class Solution {
public:
    int dfs(vector<vector<int>>& dp,vector<int>& nums,int i,int last){
        if(i==0)return dp[i][last]=1;
        if(last==0)return 0;
        if(i<0)return 0;
        if(dp[i][last]!=-1)return dp[i][last];
        return dp[i][last]=(dfs(dp,nums,i,last-1)||dfs(dp,nums,i-nums[last],last-1));
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int tot=0;
        for(int num:nums){
            tot+=num;
        }
        if(tot%2!=0)return false;
        int target=tot/2;
        vector<vector<int>> dp(target+1,vector<int>(n,-1));
        for(int i=0;i<n;i++)
        return dfs(dp,nums,target,n-1)==1;
    }
};
