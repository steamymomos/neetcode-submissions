class Solution {
public:
    int trap(vector<int>& arr) {
        int n=arr.size();
        int l=0;int r=n-1;
        int leftmax=0,rightmax=0,water=0;
        while(l<r){
            if(arr[l]<arr[r]){
                leftmax=max(leftmax,arr[l]);
                water+=leftmax-arr[l];
                l++;
            }
            else{
                rightmax=max(rightmax,arr[r]);
                water+=rightmax-arr[r];
                r--;
            }
        }
        return water;
    }
};
