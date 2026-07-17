class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
        int n=arr.size();
        vector<int> dp(n,0);
        for(int i=0;i<n;i++){
            dp[i]=1;
            for(int j=0;j<i;j++){
                if(arr[j]<arr[i]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
        int mx=1;
        for(int i=0;i<n;i++){
            if(dp[i]>mx){
                mx=dp[i];
            }
        }
        return mx;
    }
};
