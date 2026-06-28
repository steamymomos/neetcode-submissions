class Solution {
public:
    vector<int> productExceptSelf(vector<int>& arr) {
        int n=arr.size();
        long long prod=1;
        vector<int> res(n,0);
        int count=0;
        int nonzero=1;
        for(int i=0;i<n;i++){
            prod*=arr[i];
            if(arr[i]!=0)nonzero*=arr[i];
            if(arr[i]==0)count++;
        }
        for(int i=0;i<n;i++){
            if(arr[i]!=0)res[i]=prod/arr[i];
            else if(count!=1) res[i]=0;
            else res[i]=nonzero;
        }
        return res;

    }
};
