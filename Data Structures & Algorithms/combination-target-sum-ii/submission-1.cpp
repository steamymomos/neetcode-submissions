class Solution {
public:
    void ans(vector<int>& candidates,vector<vector<int>>& res,int target,int i,vector<int>& subset){
        if(target==0){
            res.push_back(subset);
            return;
        }
        if(target<0 || candidates.size()==i)return;
        if(candidates[i]>target)return;
        subset.push_back(candidates[i]);
        ans(candidates,res,target-candidates[i],i+1,subset);
        subset.pop_back();
        int j=i+1;
        while(j<candidates.size() && candidates[j]==candidates[i]){
            j++;
        }
        ans(candidates,res,target,j,subset);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> res={};
        vector<int> subset={};
        ans(candidates,res,target,0,subset);
        return res;
    }
};
