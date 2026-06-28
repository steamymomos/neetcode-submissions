class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> hash(nums.begin(),nums.end());
        return !(hash.size()==n);
    }
};