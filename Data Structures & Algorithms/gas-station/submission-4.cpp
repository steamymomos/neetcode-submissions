class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int min=INT_MAX;
        int res=0;
        int tot=0;;
        for(int i=0;i<gas.size();i++){
            if(tot+gas[i]-cost[i]<min){
                min=tot+gas[i]-cost[i];
                res=i;
            }
            tot+=gas[i]-cost[i];
        }
        if(tot<0)return -1;
        return (res+1)%gas.size();
    }
};
