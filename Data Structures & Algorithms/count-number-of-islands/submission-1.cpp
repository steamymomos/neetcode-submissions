class Solution {
public:
    queue<pair<int,int>> q;
    void bfs(vector<vector<char>>& grid){
        while(!q.empty()){
            auto a=q.front();
            q.pop();
            grid[a.first][a.second]='0';
            if(a.second!=grid[0].size()-1){
                if(grid[a.first][a.second+1]!='0')q.push({a.first,a.second+1});
            }
            if(a.second!=0){
                if(grid[a.first][a.second-1]!='0')q.push({a.first,a.second-1});
            }
            if(a.first!=grid.size()-1){
                if(grid[a.first+1][a.second]!='0')q.push({a.first+1,a.second});
            }
            if(a.first!=0){
                if(grid[a.first-1][a.second]!='0')q.push({a.first-1,a.second});
            }
        }
        return;

    }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(),false));
        int count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]=='1'){
                    q.push({i,j});
                    bfs(grid);
                    count++;
                }
            }
        }
        return count;
    }
};
