class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res={{}};
        int prev=0;
        int idx=0;
        for(int i=0;i<nums.size();i++){
            idx=(i>=1 && nums[i]==nums[i-1])?prev:0;
            prev=res.size();
            for(int j=idx;j<prev;j++){
                vector<int> tmp=res[j];
                tmp.push_back(nums[i]);
                res.push_back(tmp);
            }
        }
        return res;
    }
};
