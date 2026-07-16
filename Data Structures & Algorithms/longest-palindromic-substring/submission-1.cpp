class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        int res=0;
        string final="";
        for(int i=0;i<n;i++){
            int left=i-1;
            int right=i+1;
            int count=1;
            string str;
            str=s[i];
            while(left>=0 && right<n){
                if(s[left]==s[right]){
                    str=s[left]+str+s[right];
                    left--;
                    right++;
                    count+=2;
                }
                else{
                    break;
                }
            }
            if(count>res){
                res=count;
                final=str;
            }
            if(i<n-1 && s[i]==s[i+1]){
                str = s.substr(i, 2);
                int lefty=i-1;
                int righty=i+2;
                count=2;
                while(lefty>=0 && righty<n){
                    if(s[lefty]==s[righty]){
                        str=s[lefty]+str+s[righty];
                        lefty--;
                        righty++;
                        count+=2;
                    }
                    else{
                        break;
                    }
                }
            }
            if(count>res){
                res=count;
                final=str;
            }
        }
        return final;
    }
};
