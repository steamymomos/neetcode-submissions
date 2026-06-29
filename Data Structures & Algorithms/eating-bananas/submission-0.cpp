class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int max=INT_MIN;
        for(int i=0;i<n;i++){
            if(piles[i]>max)max=piles[i];
        }
        int i=1;
        int mid;
        int ans=0;
        while(i<=max){
            mid=(i+max)/2;
            int target=0;
            for(int z=0;z<n;z++){
                target+=(piles[z]/mid + ((piles[z]%mid==0)?0:1));
            };
            if(target>h)i=mid+1;
            else{
                ans=mid;
                max=mid-1;
            }
        }
        return ans;
    }
};
