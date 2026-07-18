class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1,0);
        res[0]=0;
        for(int i=1;i<n+1;i++){
            int a=i;
            while(a>0){
                if(a!=i){
                    res[i]+=res[a];
                    break;
                }
                a=a&(a-1);
                res[i]++;
            }
        }
        return res;
    }
};
