class Solution {
public:
    bool checkInclusion(string s1, string s) {
        unordered_map<char,int> hash;
        int n=s1.size();
        for(auto a:s1){
            hash[a]++;
        }
        for(int i=0;i<s.size();i++){
            if(i<n){
                hash[s[i]]--;
                if(hash[s[i]]==0)hash.erase(s[i]);}
            else{
                hash[s[i]]--;
                hash[s[i-n]]++;
                if(hash[s[i]]==0)hash.erase(s[i]);
                if(hash[s[i-n]]==0)hash.erase(s[i-n]);
            }
            if(hash.size()==0){
                return true;
            }
        }
        return false;
    }
};
