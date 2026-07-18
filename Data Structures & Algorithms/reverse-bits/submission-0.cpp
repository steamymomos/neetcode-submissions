class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res=0;
        int ct=32;
        while(ct--){
            res=res*2+n%2;
            n=n/2;
        }
        return res;
    }
};
