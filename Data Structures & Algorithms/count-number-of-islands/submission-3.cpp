class Solution {
public:
    queue<pair<int,int>> q;
    void bfs(vector<vector<char>>& grid){
        while(!q.empty()){
            auto a=q.front();
            q.pop();
            int i=a.first;
            int j=a.second;
            if(j!=grid[0].size()-1){
                if(grid[i][j+1]!='0'){
                    q.push({i,j+1});
                    grid[i][j+1]='0';}
            }
            if(j!=0){
                if(grid[i][j-1]!='0'){
                    q.push({i,j-1});
                    grid[i][j-1]='0';}

            }
            if(i!=grid.size()-1){
                if(grid[i+1][j]!='0'){
                    q.push({i+1,j});
                    grid[i+1][j]='0';}
            }
            if(i!=0){
                if(grid[i-1][j]!='0'){
                    q.push({i-1,j});
                    grid[i-1][j]='0';}
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
                    grid[i][j]='0';
                    bfs(grid);
                    count++;
                }
            }
        }
        return count;
    }
};
