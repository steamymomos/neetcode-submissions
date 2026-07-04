class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,int>,vector<pair<double,int>>,greater<pair<double,int>>> pq;
        vector<vector<int>> res(k);
        for(int i=0;i<points.size();i++){
            pq.push({sqrt(points[i][0]*points[i][0]+points[i][1]*points[i][1]),i});
        }
        int i=0;
        while(k--){
            res[i]=points[pq.top().second];
            pq.pop();
            i++;
        }
        return res;
    }
};
