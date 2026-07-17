class Solution {
public:
    vector<vector<int>> dp;

    bool dfs(const string &s,unordered_map<int, unordered_set<string>> &mp,int i, int len){
        if(i + len > s.length())
            return false;
        if(dp[i][len] != -1)
            return dp[i][len];
        if(i + len == s.length()){
            return dp[i][len] =
                (mp[len].find(s.substr(i,len)) != mp[len].end());
        }
        if(mp[len].find(s.substr(i,len)) != mp[len].end()
            && dfs(s, mp, i+len, 1))
            return dp[i][len] = true;
        return dp[i][len] = dfs(s, mp, i, len+1);
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<int, unordered_set<string>> mp;
        for(auto &x : wordDict)
            mp[x.size()].insert(x);
        int n = s.size();
        dp.assign(n+1, vector<int>(n+1, -1));
        return dfs(s, mp, 0, 1);
    }
};