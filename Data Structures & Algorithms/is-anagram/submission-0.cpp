class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> hash;
        if(s.size()!=t.size())return false;
        for(char a:s){
            hash[a]++;
        }
        for(char a:t){
            hash[a]--;
        }
        for(auto a:hash){
            if(a.second!=0)return false;
        }
        return true;
    }
};
