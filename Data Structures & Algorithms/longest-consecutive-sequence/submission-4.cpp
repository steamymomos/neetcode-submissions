class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        int count=1;
        int res=0;
        if(n==0)return 0;
        sort(nums.begin(),nums.end());
        int prev=nums[0];
        for(int i=0;i<n;i++){
            if(nums[i]==prev){
                continue;
            }
            else if(nums[i]==(prev+1)){
                count++;
                prev=nums[i];
            }
            else{
                res=max(res,count);
                count=1;
                prev=nums[i];
            }
        }
        res=max(res,count);
        return res;
    }
};
