class Solution {
public:
    bool dfs(string s1,string s2,string s3,vector<vector<int>>& dp,int i,int j){
        if(i>=0 && j>=0 && dp[i+1][j+1]!=-1)return dp[i+1][j+1];
        if(i>=0 && j>=0 && s2[j]==s3[j+i+1]&& s1[i]==s3[i+j+1])return dp[i+1][j+1]=(dfs(s1,s2,s3,dp,i,j-1)||dfs(s1,s2,s3,dp,i-1,j));
        else if(j>=0 && s2[j]==s3[j+i+1])return dp[i+1][j+1]=dfs(s1,s2,s3,dp,i,j-1);
        else if(i>=0 && s1[i]==s3[i+j+1])return dp[i+1][j+1]=dfs(s1,s2,s3,dp,i-1,j);
        else if(i<0 && j<0)return true;
        else return false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.size();
        int m=s2.size();
        if(s3.size()!=m+n)return false;
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return dfs(s1,s2,s3,dp,n-1,m-1);
    }
};
