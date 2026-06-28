class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> idk;
        for(auto s : strs){
            string sorted_s = s;
            sort(sorted_s.begin(), sorted_s.end());
            idk[sorted_s].push_back(s);
        }
        for(auto const& [key, val] : idk){
            res.push_back(val);
        }
        return res;
    }
};