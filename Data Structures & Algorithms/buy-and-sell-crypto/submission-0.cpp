class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n=arr.size();
        int res=0;
        int l=0,r=1;
        while(r<n){
            if(arr[l]<arr[r]){
                int pro=arr[r]-arr[l];
                res=max(res,pro);
            }
            else{
                l=r;
            }
            r++;
        }
        return res;
    }
};
