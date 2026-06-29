class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int i=0,j=n-1;
        int mid=(i+j)/2;
        while(i<=j){
            if(nums[mid]==target)return mid;
            else if(nums[mid]>target) j=mid-1;
            else i=mid+1;
            mid=(i+j)/2;
        }
        return -1;
    }
};
