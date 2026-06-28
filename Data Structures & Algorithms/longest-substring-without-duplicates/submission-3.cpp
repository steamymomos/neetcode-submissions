class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        unordered_map<char,int> hash;
        int latest=-1;
        int res=0;
        if(n==1 || n==0)return n;
        for(int i=0;i<n;i++){
            if(hash.find(s[i])!=hash.end()){
                latest=max(hash[s[i]],latest);
            }
            res=max(res,i-latest);
            hash[s[i]]=i;
        }
        return res;
    }
};
