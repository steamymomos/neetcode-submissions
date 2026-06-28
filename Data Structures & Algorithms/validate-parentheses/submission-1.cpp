class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n=s.length();
        for(char a:s){
            if((a=='(' || a=='{' || a=='[')){
                st.push(a);
            }
            else if(!st.empty() && ((a==')' && st.top()=='(')|| (a=='}' && st.top()=='{') || (a==']' && st.top()=='['))){
                st.pop();
            }
            else{
                return false;
            }
        }
        return (st.empty());
    }
};
