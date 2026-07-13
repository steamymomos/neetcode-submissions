class Solution {
public:
    void dfs(vector<vector<int>>& adj,vector<bool>& visited,int i){
        for(auto u:adj[i]){
            if(!visited[u]){
                visited[u]=true;
                dfs(adj,visited,u);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> visited(n,false);
        int count=0;
        for(auto a:edges){
            adj[a[0]].push_back(a[1]);
            adj[a[1]].push_back(a[0]);
        }
        for(int i=0;i<n;i++){
            if(!visited[i]){
                visited[i]=true;
                dfs(adj,visited,i);
                count++;
            }
        }
        return count;
    }
};
