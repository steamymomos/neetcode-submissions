class Solution {
public:
    vector<int> productExceptSelf(vector<int>& arr) {
        int n=arr.size();
        long long prod=1;
        vector<int> res(n,0);
        vector<int> pref(n,1);
        vector<int> post(n,1);
        pref[0]=arr[0];
        post[n-1]=arr[n-1];

        for(int i=1;i<n;i++){
            pref[i]=pref[i-1]*arr[i];
            post[n-i-1]=post[n-i]*arr[n-i-1];
        }
        res[0]=post[1];
        res[n-1]=pref[n-2];
        for(int i=1;i<n-1;i++){
            res[i]=(pref[i-1]*post[i+1]);
        }
        return res;

    }
};
