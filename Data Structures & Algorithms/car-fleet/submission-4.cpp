class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<int> st;
        vector<pair<double,double>> vec;
        for(int i=0;i<position.size();i++){
            vec.push_back({position[i],(double)(target-position[i])/speed[i]});
        }
        sort(vec.begin(),vec.end(),[&](auto x,auto y){return x.first<y.first;});
        st.push(0);
        for(int i=1;i<vec.size();i++){
            while(!st.empty() && vec[i].second >= vec[st.top()].second){
                st.pop();
            }
            st.push(i);
        }
        return st.size();
    }
};
