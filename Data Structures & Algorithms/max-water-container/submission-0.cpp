class Solution {
public:
    int maxArea(vector<int>& arr) {
        int n=arr.size();
        int i=0,j=n-1;
        int curr=0;
        int res=0;
        while(i<j){
            curr=min(arr[i],arr[j])*(j-i);
            res=max(res,curr);
            if(arr[i]<arr[j])i++;
            else j--;
        }
        return res;
    }
};
