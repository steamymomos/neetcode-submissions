class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n-1) return false;
        vector<vector<int>> adj(n);
        for(auto a:edges){
            adj[a[0]].push_back(a[1]);
            adj[a[1]].push_back(a[0]);
        }
        vector<bool> visited(n,false);
        vector<int> parent(n,-1);
        queue<int> q;
        q.push(0);
        visited[0]=true;
        while(!q.empty()){
            auto a=q.front();
            q.pop();
            for(auto u:adj[a]){
                if(visited[u] && u!=parent[a]){
                    return false;
                }
                else if(!visited[u]){
                    visited[u]=true;
                    parent[u]=a;
                    q.push(u);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(!visited[i])return false;
        }
        return true;

    }
};
