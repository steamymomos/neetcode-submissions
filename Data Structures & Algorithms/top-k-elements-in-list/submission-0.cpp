class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> hash;
        vector<int> resi(k);
        for(int i=0;i<n;i++){
            hash[nums[i]]++;
        }
        for(int j=0;j<k;j++){
            int max=INT_MIN;
            int res=0;
            for(auto a:hash){
                if(a.second>max){
                    max=a.second;
                    res=a.first;
                }
            }
            resi[j]=res;
            hash.erase(res);
        }
        return resi;
    }
};
