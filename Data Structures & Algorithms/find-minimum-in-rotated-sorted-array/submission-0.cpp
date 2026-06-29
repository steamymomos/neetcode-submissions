class Solution {
public:
    int findMin(vector<int> &nums) {
        int n=nums.size();
        int i=0,j=n-1;
        int res=nums[0];
        while(i<=j){
            if(nums[i]<nums[j]){
                res=min(res,nums[i]);
                break;
            }
            int mid=(i+j)/2;
            res=min(res,nums[mid]);
            if(nums[i]<=nums[mid]){
                i=mid+1;
            }
            else j=mid-1;;
        }
        return res;

    }
};
