class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int oper1=0;
        int oper2=0;
        int i=0;
        stack<int> st;
        for(string a:tokens){
            if(a=="+"){
                oper2=st.top();
                st.pop();
                oper1=st.top();
                st.pop();
                oper1+=oper2;
                st.push(oper1);
            }
            else if(a=="-") {
                oper2=st.top();
                st.pop();
                oper1=st.top();
                st.pop();
                oper1-=oper2;
                st.push(oper1);}
            else if(a=="*") {
                                oper2=st.top();
                st.pop();
                oper1=st.top();
                st.pop();
                oper1*=oper2;
                st.push(oper1);}
            else if(a=="/") {
                                oper2=st.top();
                st.pop();
                oper1=st.top();
                st.pop();
                oper1/=oper2;
                st.push(oper1);}
            else{
                st.push(stoi(a));
            }

        }
        return st.top();
    }
};
