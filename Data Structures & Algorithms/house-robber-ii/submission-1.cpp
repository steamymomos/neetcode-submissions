class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        int rob1 = 0, rob2 = 0;
        for (int i=0;i<n-1;i++) {
            int temp = max(nums[i] + rob1, rob2);
            rob1 = rob2;
            rob2 = temp;
        }
        int rob11=0;int rob22=0;
        for (int i=1;i<n;i++) {
            int temp = max(nums[i] + rob11, rob22);
            rob11 = rob22;
            rob22 = temp;
        }
        return max(rob2,rob22);

    }
};