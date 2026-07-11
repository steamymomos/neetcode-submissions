class Solution {
public:
    void ans(vector<int>& nums, vector<vector<int>>& res, int i) {
        if (i == nums.size()) {
            res.push_back(nums);
            return;
        }

        for (int j = i; j < nums.size(); j++) {
            swap(nums[i], nums[j]);
            ans(nums, res, i + 1);
            swap(nums[i], nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res={};
        ans(nums,res,0);
        return res;

    }
};
