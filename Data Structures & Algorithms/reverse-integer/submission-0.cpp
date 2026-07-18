class Solution {
public:
    int reverse(int x) {
        int res=0;
        if(x>0){
        while(x>0){
            if(res>INT_MAX/10){
                return 0;
            }
            if(res==INT_MAX/10 && x<=7){
                res=res*10+x;
                return res;
            }
            res=res*10+x%10;
            x=x/10;
        }}
        else if(x<0){
            x=-x;
            while(x>0){
                if(res>INT_MAX/10){
                    return 0;
                }
                if(res==INT_MAX/10 && x<=8){
                    res=-res*10-x;
                    return res;
                }
                res=res*10+x%10;
                x=x/10;
            }
            res=-res;
        }
        return res;
    }
};
