class Solution {
public:
    void ans(vector<int>& nums,int target,int i,vector<vector<int>>& res,vector<int>& subset){
        if(target==0){
            res.push_back(subset);
            return;
        }
        if(target<0 || nums.size()==i)return;
        if(nums[i]>target)return;
        subset.push_back(nums[i]);
        ans(nums,target-nums[i],i,res,subset);
        subset.pop_back();
        ans(nums,target,i+1,res,subset);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res={};
        vector<int> subset={};
        ans(nums,target,0,res,subset);
        return res;

    }
};
