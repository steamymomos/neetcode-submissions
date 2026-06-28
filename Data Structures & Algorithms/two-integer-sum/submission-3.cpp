class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> res;
        unordered_map<int,int> sol;
        for(int i=0;i<n;i++){
            auto it=sol.find(target-nums[i]);
            if(it!=sol.end()){
                res.push_back(it->second);
                res.push_back(i);
                break;
            }
            else{
                sol[nums[i]]=i;
            }
        }
        return res;
    }
};