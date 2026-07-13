class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> in(numCourses);
        queue<int> q;
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            in[prerequisites[i][0]]++;
        }
        for(int i=0;i<numCourses;i++){
            if(in[i]==0){
                q.push(i);
            }
        }
        int count=0;
        while(!q.empty()){
            auto a=q.front();
            q.pop();
            for(auto u:adj[a]){
                in[u]--;
                if(in[u]==0)q.push(u);
            }
            count++;
        }
        return (count==numCourses);
    }
};
